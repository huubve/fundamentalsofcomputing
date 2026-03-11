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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	string_stuff();


int main() {
	string_stuff();
	return EXIT_SUCCESS; /* not reached because string_stuff() causes termination by SIGBUS */
}

/* check out the memory layout pictures in the course presentation ! */
char *	u = "u1234_57u"; /* u is a pointer to the location where the compiler & loader placed the string. On many systems you are not allowed to write there */
char *	v = NULL; /* v is a NULL pointer: it "points to" address (location) 0. Likely you are not allowed to access that address. */
char	x[20] = "x1234_67x"; /* x is the address of an array of 20 characters. Initialisation takes care of placing the string in that place */
char	y[20]; /* uninitialised arrays are initialised with 0's since y[0] == '\0' y represents an empty string */
char *	z = NULL;


void prt(FILE * f, int linenr) {
	fprintf(f, "prt() --- at line %d ----\n", linenr);
	fprintf(f, "u = \"%s\"\n", u);
	fprintf(f, "v = \"%s\"\n", v);
	fprintf(f, "x = \"%s\"\n", x);
	fprintf(f, "y = \"%s\"\n", y);
	fprintf(f, "z = \"%s\"\n", z);
}


void	string_stuff() {

	fprintf(stdout, "Initial values --- at line %d ----\n", __LINE__);
	prt(stdout, __LINE__);
	fprintf(stdout, "v = u --- at line %d ----\n", __LINE__);
	v = u; /* this is OK. you can assign a pointer. now v equals u and thus points to the same global anonymous literal. NOTE that v does not point to u!  */
	prt(stdout, __LINE__);
	fprintf(stdout, "x[5] = 'x'  --- at line %d ----\n", __LINE__);
	x[5] = 'x' ;
	prt(stdout, __LINE__);
	fprintf(stdout, "y[5] = 'y' --- at line %d ----\n", __LINE__);
	y[5] = 'y' ;
	prt(stdout, __LINE__);
	/* y = x; would give compile error 'array type 'char[20]' is not assignable'. you can not assign arrays, you must copy them element by element */ 
	fprintf(stdout, "strcpy(y, x) --- at line %d ----\n", __LINE__);
	strcpy(y, x);
	prt(stdout, __LINE__);
	fprintf(stdout, "y[5] = 'Y'  --- at line %d ----\n", __LINE__);
	y[5] = 'Y';
	prt(stdout, __LINE__);
	fprintf(stdout, "z = u  --- at line %d ----\n", __LINE__);
	z = u;
	prt(stdout, __LINE__);
	fprintf(stdout, "z = x  --- at line %d ----\n", __LINE__);
	z = x;
	prt(stdout, __LINE__);
	fprintf(stdout, "z = y  --- at line %d ----\n", __LINE__);
	z = y;
	prt(stdout, __LINE__);
	fprintf(stdout, "Watch it. SIGBUS ahead !--- at line %d ----\n", __LINE__);
	fprintf(stdout, "v[5] = 'v' --- at line %d ----\n", __LINE__);
	fflush(stdout);
	v[5] = 'C'; /* this will evoke a SIGBUS and thus a jump to the signal handler sigbus_handler() */
	prt(stdout, __LINE__); /* we will not reach this call to prt() because our program will have been terminated by SIGBUS on executing the previous statement*/
	return; /* Not reached */
}




