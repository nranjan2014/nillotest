#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "fields.h"
#include "dllist.h"

#define talloc(ty, sz) (ty *) malloc ((sz) * sizeof(ty))

main(int argc, char **argv)
{
  IS is;
  char s[500];
  FILE *f;
  Dllist l, tmp;
  Dllist params;
  char *method;
  char *retval;
  char *sig;
  char *x, *y;
  char *classname = NULL;
  int indef = 0;
  int inex = 0;
  int is_ivec = 0;
  int is_svec = 0;
  int is_dvec = 0;
  int is_lvec = 0;
  int i, nargs;
  Dllist examples;
  char **pnames, saved;

  if (argc != 2) {
    fprintf(stderr, "usage: qprocess file\n");
    exit(1);
  }

  is = new_inputstruct(argv[1]);
  if (is == NULL) { perror(argv[1]); exit(1); }
  
  sprintf(s, "desc-%s.html", argv[1]);
  f = fopen(s, "w");
  if (f == NULL) { perror(s); exit(1); }

  l = new_dllist();
  examples = new_dllist();
  while (get_line(is) >= 0) {
    if (strstr(is->text1, "vector <int") != NULL) is_ivec = 1;
    if (strstr(is->text1, "vector <string") != NULL) is_svec = 1;
    if (strstr(is->text1, "vector <double") != NULL) is_dvec = 1;
    if (strstr(is->text1, "vector <long") != NULL) is_lvec = 1;
    if (!dll_empty(l)) {
      dll_append(l, new_jval_s(strdup(is->text1)));
    } else {
      fputs(is->text1, f);
      if (strstr(is->text1, "#line") == is->text1) {
        dll_append(l, new_jval_s(""));
      }
      for (i = strlen(is->text1)-1; i >=0 && isspace(is->text1[i]); i--) is->text1[i] = '\0';
      if (strstr(is->text1, "EXAMPLES") == is->text1) inex = 1;
      if (strstr(is->text1, "END") == is->text1) inex = 0;
      if (strstr(is->text1, "DEFINITION") == is->text1) indef = 1;
      if (strstr(is->text1, "CONSTRAINTS") == is->text1) indef = 0;
      if (indef) {
        if (strstr(is->text1, "Class:") == is->text1) classname = strdup(strchr(is->text1, ':')+1);
        if (strstr(is->text1, "Method:") == is->text1) method = strdup(strchr(is->text1, ':')+1);
        if (strstr(is->text1, "Returns:") == is->text1) retval = strdup(strchr(is->text1, ':')+1);
        if (strstr(is->text1, "Method signature:") == is->text1) sig = strdup(strchr(is->text1, ':')+1);
      }
      if (inex == 1) {
        if (is->NF == 1 && is->text1[0] != '(' && is->fields[0][strlen(is->fields[0])-1] == ')') {
          inex = 2;
          sprintf(s, "PROBLEM %d\n", atoi(is->fields[0]));
          dll_append(examples, new_jval_s(strdup(s)));
        }   
      } else if (inex == 2 && is->NF == 0) {
        inex = 1;
      } else if (inex == 2) {
        dll_append(examples, new_jval_s(strdup(is->text1)));
      }
    }
  }
  fclose(f);
  jettison_inputstruct(is);
  sprintf(s, "cp %s backup-%s; chmod 0400 backup-%s", argv[1], argv[1], argv[1]);
  system(s);
  sprintf(s, "head -n 19 helpers.h > %s", argv[1]);
  system(s);

  f = fopen(argv[1], "a");
  if (is_ivec) fprintf(f, "typedef vector <int> IVec;\n");
  if (is_svec) fprintf(f, "typedef vector <string> SVec;\n");
  if (is_lvec) fprintf(f, "typedef vector <long long> LLVec;\n");
  if (is_dvec) fprintf(f, "typedef vector <double> DVec;\n");
  fprintf(f, "\n");
  fprintf(f, "class %s {\n  public:\n", classname);
  fprintf(f, "    %s;\n", sig);
  fprintf(f, "};\n\n");
  fprintf(f, "%s %s::%s%s\n", retval, classname, method, strchr(sig, '('));
  fprintf(f, "{\n  int i;\n}\n");
  fclose(f);

  params = new_dllist();
  x = strchr(sig, '(');
  x++;
  while (strchr(x, ',') != NULL) {
    y = strchr(x, ',');
    *y = '\0';
    dll_append(params, new_jval_s(strdup(x)));
    x = y + 2;
  }
  y = strchr(x, ')');
  *y = '\0';
  dll_append(params, new_jval_s(strdup(x)));
  nargs = 0;
  dll_traverse(tmp, params) nargs++;
  pnames = talloc(char *, nargs);

  tmp = params->flink;
  for (i = 0; i < nargs; i++) {
    pnames[i] = strdup(strrchr(tmp->val.s, ' ')+1);
    tmp = tmp->flink;
  }
  
  f = fopen("main.cpp", "w");
  fprintf(f, "#include \"%s\"\n", argv[1]);
  fprintf(f, "\n");
  fprintf(f, "int main(int argc, char **argv)\n");
  fprintf(f, "{\n");
  fprintf(f, "  int i;\n");
  fprintf(f, "  class %s TheClass;\n", classname);
  fprintf(f, "  %s retval;\n", retval);
  dll_traverse(tmp, params) fprintf(f, "  %s;\n", tmp->val.s);
  fprintf(f, "\n");
  fprintf(f, "  if (argc != 2) { fprintf(stderr, \"usage: a.out num\\n\"); exit(1); }\n\n");
  fprintf(f, "/*\n");
  for (i = 0; i < nargs; i++) fprintf(f, "  %s = ;\n", pnames[i]);
  fprintf(f, "*/\n");
  fprintf(f, "\n");
  dll_traverse(tmp, examples) {
    if (sscanf(tmp->val.s, "PROBLEM %d)", &i) == 1) {
      if (i != 0) fprintf(f, "  }\n");
      fprintf(f, "\n");
      fprintf(f, " if (atoi(argv[1]) == %d) {\n", i);
      i = 0;
    } else {
      x = tmp->val.s;
      if (strchr(x, '{') != NULL || strchr(x, '}') != NULL || strchr(x, ',') != NULL) {
        y = strchr(x, '{');
        if (y != NULL) { 
          y++;
        } else {
          y = x;
        }
        do {
          x = y;
          y = strchr(x, ',');
          if (y == NULL) {
            y = strchr(x, '}');
            if (y == NULL) {
              printf("Can't figure out string %s\n", tmp->val.s);
              exit(1);
            }
          }
          saved = *y;
          *y = '\0';
          fprintf(f, "    %s.push_back(%s);\n", pnames[i], x);
          *y = saved;
          if (saved == '}') i++;
          y++;
        } while (strchr(y, ',') != NULL || strchr(y, '}') != NULL);
      } else {
        fprintf(f, "    %s = %s;\n", pnames[i], tmp->val.s);
        i++;
      }
    }
  }
  fflush(f);
  fprintf(f, "  }\n");
  fprintf(f, "\n");
  fprintf(f, "  retval = TheClass.%s(", method);
  for (i = 0; i < nargs; i++) {
    if (i > 0) fprintf(f, ", ");
    fprintf(f, "%s", pnames[i]);
  }
  fprintf(f, ");\n");
  if (strstr(retval, "vector") == retval) {
    fprintf(f, "  VIT(i, retval) cout << retval[i] << endl;\n");
  } else {
    fprintf(f, "  cout << retval << endl;\n");
  }
  fprintf(f, "\n");
  fprintf(f, "  exit(0);\n");
  fprintf(f, "}\n");
  fflush(f);
  fclose(f);
  sprintf(s, "sh qpscript.sh desc-%s.html", argv[1]);
  system(s);
  exit(0);
}
