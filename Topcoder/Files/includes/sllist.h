#ifndef _sllist_
#define _sllist_

/* Singly linked lists.  Easy to use, but no deletion of nodes, no appending
   to a list, and you can only traverse the list one way.   */

#include "jval.h"

typedef struct sllist {
  struct sllist *link;
  Jval val;
} *Sllist;
 
extern Sllist new_sllist();
extern free_sllist(Sllist);

/* Inserting nodes */

extern Sllist sll_prepend(Sllist, Jval);
extern Sllist sll_insert_after(Sllist, Jval);

/* Moving around a sllist */

extern Sllist sll_first(Sllist);
extern Sllist sll_next(Sllist);

/* Are we at the end of a sllist? */

extern Sllist sll_nil(Sllist);

/* Is the sllist empty? */

extern int sll_empty(Sllist);

/* Traversal macro */

#define sll_traverse(tmpnode, list) for (tmpnode = sll_first(list); \
                                         tmpnode != sll_nil(list); \
                                         tmpnode = sll_next(tmpnode))
#endif
