/* c arrays and strings
 * c we discussed arays before
 * strings are weird in c
 * c knows literal strings "this is a string"
 * but there is no variable type string
 * string is not a type in c
 * the type of a string is:  array of (unsigned)char
 * (to know where the string ends, you can not check the size of the array, string has a trailing '\0' (this equals (unsigned char)0))
 * and, remember that when you declare an array, the name actualy is a pointer???
 * this all has weird repercussions for assigning, copying and initialising with strings
 * this piece of code demonstrates some of this.
 */

#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <setjmp.h>

void	prt(FILE * f, int linenr);
void	string_stuff(int avoid_sigbus);

jmp_buf back_here;

/* check out the memory layout pictures in the presentation ! */
char *	u = "u123 _ 7uuu";
char *	v = NULL;
char	x[20] = "x123 _ 7xxx";
char	y[20]; /* uninitialised arrays are initialised with 0's Thus creating an empty string in this case */
char *	z = NULL;

void	sigbus_handler(int x) {
	fprintf(stderr, "handling SIGBUS !!!\n");
	longjmp(back_here, 1);
	exit(EXIT_FAILURE);
}

int main() {
	int	setjmp_return_value;
	struct sigaction sigbus_action = { 0 };
	sigbus_action.sa_handler = &sigbus_handler;
	if (sigaction(SIGBUS, &sigbus_action, NULL) == -1) {
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	if ( ! ( setjmp_return_value = setjmp(back_here) ) ) { /* sigbus_handler() will jump back here, making setjmp return 1 */
		/* setjmp returns 0 if it only saved the return environment */
		fprintf(stdout, "First try of string_stuff(avoid_sigbus=0) --- at line %d ----\n", __LINE__); 
		fflush(stdout);
		string_stuff(0);
	} else { /* setjmp returns 1 if longjmp returned back here */
		fprintf(stdout, "Retry string_stuff(avoid_sigbus=1) after longjmp back_here --- at line %d ----\n", __LINE__);
		fflush(stdout);
		string_stuff(1);
	}
	return EXIT_SUCCESS;
}

void	string_stuff(int avoid_sigbus) {

	prt(stdout, __LINE__);
	v = u; /* this is OK. you can assign a pointer. now v equals u and thus also points to the global literal "char * u". NOTE that v does not point to u!  */
	/* y = x; would give compile error 'array type 'char[20]' is not assignable'. you can not assign arrays, you must copy them element by element */ 
	/* so, why is the initialisation of x allowed? */
	prt(stdout, __LINE__);
	fprintf(stdout, "assign to x[5] --- at line %d ----\n", __LINE__);
	x[5] = avoid_sigbus ? 'X' : 'x' ;
	prt(stdout, __LINE__);
	fprintf(stdout, "assign to y[5] --- at line %d ----\n", __LINE__);
	y[5] = avoid_sigbus ? 'Y' : 'y' ;
	prt(stdout, __LINE__);
	fprintf(stdout, "strcpy(y, x) --- at line %d ----\n", __LINE__);
	strcpy(y, x);
	prt(stdout, __LINE__);
	fprintf(stdout, "assign to y[5] --- at line %d ----\n", __LINE__);
	y[5] = avoid_sigbus ? 'Y' : 'y' ;
	prt(stdout, __LINE__);
	fflush(stdout);

	if ( avoid_sigbus ) {
		fprintf(stdout, "avoiding SIGBUS --- at line %d ----\n", __LINE__);
		fflush(stdout);
	} else {
		fprintf(stdout, "evoking SIGBUS --- at line %d ----\n", __LINE__);
		fprintf(stdout, "assign to v[5] --- at line %d ----\n", __LINE__);
		fflush(stdout);
		v[5] = 'C'; /* this will evoke a SIGBUS and thus a jump to the signal handler sigbus_handler() */
	}

	fprintf(stdout, "assigning u,x,y to z --- at line %d ----\n", __LINE__);
	z = u;
	prt(stdout, __LINE__);
	z = x;
	prt(stdout, __LINE__);
	z = y;
	prt(stdout, __LINE__);
	fflush(stdout);
	return;
}


void prt(FILE * f, int linenr) {
	fprintf(f, "--- at line %d ----\n", linenr);
	fprintf(f, "u = \"%s\"\n", u);
	fprintf(f, "v = \"%s\"\n", v);
	fprintf(f, "x = \"%s\"\n", x);
	fprintf(f, "y = \"%s\"\n", y);
	fprintf(f, "z = \"%s\"\n", z);
}



