
#define talloc(ty, sz) (ty *) malloc ((sz) * sizeof(ty))
#define copy_string(s) ((char *) strcpy(talloc(char, strlen(s)+1), s))
#define TRUE 1
#define FALSE 0
#define fprintfv (void) fprintf
