/* Pseudo-threads, VERSION 2.0
 * Jim Plank
 * January, 1997
 * Revised, January, 2009
 * CS460/CS560
 */

/*
   You must link with libfdr.a
*/

/* Pointer to the currently running thread */

extern void *pt_self;

/* pt_fork says to make a new thread which runs the (*function)(arg).
   This gets put on the thread queue, and pt_fork returns with a 
   thread pointer.
 */

extern void *pt_fork(void (*function)(), void *arg);

/* pt_join waits for the specified thread to exit, and then calls the
              continuation.
   pt_joinall waits until there are no threads left on the ready queue, 
              and there are no threads sleeping.  Then its continuation
              is called.  */

extern void pt_join(void *tid, void (*function)(), void *arg);
extern void pt_joinall(void (*function)(), void *arg);

/* Pt_exit() forces the thread to exit */

extern void pt_exit();

/* make_gsem initializes a general semaphore with the value initval, which
   must be >= 0.  kill_gsem deallocates the semaphore.  kill_gsem() will
   fail with an error if there are any threads waiting on the semaphore. 
   With semaphores, you may access the value, but nothing else.  
   */

typedef void *Gsem;

extern Gsem make_gsem(int initval);
extern void kill_gsem(Gsem *gsem);
extern int gsem_getval(Gsem *gsem);
    
/* gsem_P performs the P operation on the semaphore.  This operation 
   works in a special way.  You must specify a function and an argument
   with gsem_P.  If the P blocks, then when it wakes up, 
   (*function)(arg) is run.  Otherwise, (*function)(arg) is run
   directly.  In either case, gsem_P() never returns.  When 
   (*function)(arg) returns, its thread dies.
   The reason for this is that our threads are stackless.
*/

extern gsem_P(Gsem *g, void (*function)(), void *arg);

/* gsem_V() is the normal V operation.  If the semaphore's value is 
   < 0 when gsem_V() is called, then a blocked thread is taken off
   the semaphore queue and put on the thread queue. */

extern gsem_V(Gsem *g);


/* pt_sleep says to sleep for a certain number of seconds.  Then the 
   thread is put back on the ready queue.  When it is time to run the
   thread (*function)(arg) is called.     pt_sleep(0) is equivalent
   to pt_yield()  */

extern void pt_sleep(int sec, void (*function)(), void *arg);
extern void pt_yield(void (*function)(), void *arg);

extern double pt_get_fake_time();
extern void pt_fake_sleep(double seconds, void (*function)(), void *arg);
