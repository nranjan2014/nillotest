#include <sys/types.h>
#include <netinet/in.h>

#define	GLBSIZ	BUFSIZ

#define	RANDFILE	"/.randstate"
#define	RANDSSIZ	256
#define	RAND_SEED	0	/* start_random used srandom() */
#define	RAND_FILE	1	/* start_random used state in file */
#define	RAND_NWST	2	/* start_random created new state */

struct s_getline {
	FILE *fp;		/* open file */
	char buf[GLBSIZ];	/* current chunk of file */
	char *bp;		/* pointer to next char in buf */
	char *be;		/* pointer to end of buf */
	char *line;		/* space for the line */
	int linelen;		/* how big it can be */
};
typedef	struct s_getline *	Getline;

extern char *	cmdbase(char *);
extern char **	stov(char *);
extern void	freesv(char **);
extern int	findPseudoTTY(int);
extern void *	getmem(size_t);
extern char *	inadport_decimal(struct sockaddr_in *);
extern int	inet_conn(char *, short, int, int);
extern int	inet_serve(char *, short, int, int, int);
extern int	inet_serve_any(char *, short *, int, short, short);
extern int	inet_wait(int , struct sockaddr *, int *);
extern int	isproxycmd(char *);
extern int	printfile(char *, FILE *);
extern int	proxy_conn(char *, int, int, int);
extern void *	regetmem(void *, size_t);
extern int	wordcount(char *);
extern void *	xgetmem(size_t);
extern FILE *	xfopen(char *, char *);
extern void *	xregetmem(void *, size_t);
extern FILE *	xxfopen(char *, char *);

extern Getline	newgetline(void);
extern void	freegetline(Getline);
extern Getline	gl_open(char *);
extern Getline	gl_fdopen(int);
extern void	gl_close(Getline);
extern char *	gl_nextline(Getline);
extern void	gl_rewind(Getline);

extern FILE *		fopen_random_file(char *, char *);
extern char *		random_file_name(char *);
extern int		save_random(char *);
extern int		start_random(char *, int *);
extern struct stat *	stat_random_file(char *);
