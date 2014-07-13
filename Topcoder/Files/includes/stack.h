#ifndef _JSTACK_
#define _JSTACK_

/* A generic stack library.  Very simple.. */

#include "jval.h"

typedef void *Stack;

/* Allocate and deallocate a stack.  New_stack() does call malloc. */

extern Stack new_stack();
extern free_stack(Stack);

/* Test to see if the stack is empty -- or how many elements it as */

extern int stack_empty(Stack);
extern int stack_size(Stack);


/* Put something on the stack */

extern stack_push(Stack, Jval);


/* Take something off the stack */

extern Jval stack_pop(Stack);


/* Look at the top element, but don't take it off */

extern Jval stack_top(Stack);


#endif
