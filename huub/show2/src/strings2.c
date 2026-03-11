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

char *	new_string_good(char * s);
char *	new_string_wrong(char * s);
void	prt(FILE * f, int linenr, char * title);

char *	u = NULL;

int main() {
	prt(stdout, __LINE__, "Initial value");
	u = new_string_good("u1234_6789 GOOD");
	prt(stdout, __LINE__, "After new_string_good()");
	u = new_string_wrong("u1234_6789 WRONG");
	prt(stdout, __LINE__, "After new_string_wrong()"); /* this will terminate with SIGSEGV */
	return EXIT_SUCCESS; /* not reached because printing what was returned by new_string_wrong() causes termination by SIGSEGV */
}

void prt(FILE * f, int linenr, char * title) {
	fprintf(f, "prt(%s) --- at line %d ----\n", title, linenr);
	fprintf(f, "u = \"%s\"\n", u);
}

char *	new_string_good(char *s) {
	char *	r = (char *)malloc(strlen(s)+1);
	strcpy(r, s);
	return r;
}

char *	new_string_wrong(char *s) {
	char r[1024];
	strcpy(r, s);
	return r;
}

