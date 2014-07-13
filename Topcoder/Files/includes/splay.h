#ifndef _SPLAY_
#define SPLAY

/* Splay trees -- a general-purposed binary tree package.  All operations
   are in amortized log time.  Note, keys and vals are all jvals.  If
   you use the "_str" functions, then strings are used as keys and 
   strcmp() is the comparison function.  "_int" and "_dbl" use ints and
   doubles as the comparison function, and "_gen" lets you use generic
   jvals and define your own comparison function */

#include "jval.h"

/* Node identities */

#define SPLAY_SENTINEL 0
#define SPLAY_OTHER 1

typedef struct splay {
  Jval key;
  Jval val;
  int is_sentinel;
  struct splay *left;
  struct splay *right;
  struct splay *flink;
  struct splay *blink;
  struct splay *parent;
} Splay;

extern Splay *new_splay();
extern void free_splay(Splay *);

extern Splay *splay_insert_str(Splay *tree, char *key, Jval val);
extern Splay *splay_insert_int(Splay *tree, int key, Jval val);
extern Splay *splay_insert_dbl(Splay *tree, double key, Jval val);
extern Splay *splay_insert_gen(Splay *tree, Jval key, Jval val,
                               int (*func)(Jval, Jval));

extern Splay *splay_find_str(Splay *tree, char *key);
extern Splay *splay_find_int(Splay *tree, int key);
extern Splay *splay_find_dbl(Splay *tree, double key);
extern Splay *splay_find_gen(Splay *tree, Jval key,
                             int (*func)(Jval, Jval)); 

extern Splay *splay_find_gte_str(Splay *tree, char *key, int *found);
extern Splay *splay_find_gte_int(Splay *tree, int key, int *found);
extern Splay *splay_find_gte_dbl(Splay *tree, double key, int *found);
extern Splay *splay_find_gte_gen(Splay *tree, Jval key, int *found,
                               int (*func)(Jval, Jval));

extern Splay *splay_root(Splay *tree);
extern Splay *splay_first(Splay *tree);
extern Splay *splay_last(Splay *tree);
extern Splay *splay_next(Splay *node);
extern Splay *splay_prev(Splay *node);
extern Splay *splay_nil(Splay *tree);

extern void splay_delete_node(Splay *node);


#define splay_traverse(ptr, list) \
  for (ptr = splay_first(list); ptr != splay_nil(list); ptr = splay_next(ptr))
#define splay_rtraverse(ptr, list) \
  for (ptr = splay_last(list); ptr != splay_nil(list); ptr = splay_prev(ptr))

#endif
