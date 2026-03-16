#include <stdbool.h>
#include <ctype.h>

extern int getoptions( int argc, char *argv[], char * optiondefinition);

typedef enum {
      LIST = 1, BOOL = 2, CHAR = 4, STRING = 8, I32 = 16, UI64 = 32, DOUBLE = 64
} value_type_e;


typedef union {
		bool	b;
		char	c;
		char *	s;
		int32_t		i32;
		uint64_t	ui64;
		double	d;
} value_u;

typedef struct	flag_s {
	char		flag;
	bool		found;
	char		vformat[32];
	value_type_e	vtype;
	value_u		value;
	char		vseparator;
	uint32_t	vcount;
	value_u *	values;
} flag_t;

#define MAXFLAGS 129
static flag_t	flags[MAXFLAGS];
static bool flags_initialised=false;

int	initflags(char * definition) {
	
	for ( int i = 0; i < MAXFLAGS; i++ ) {
		flags[i].flag = (char)0;
		flags[i].given = false;
		flags[i].vformat[0] = (char)0;
		flags[i].vseparator = (char)0;
		flags[i].vtype = 0;
		flags[i].vcount = 0;
		flags[i].values = (value_u *)0;
	}

	for (; *definition; definition++) {
		flags[*definition] = true;
	}

}

int	getflags( int argc, char *argv[], int * nextarg) {

	int  optioni = nextoption ? *nextoption : 1;
	bool in_options = true;

	assert(flagsinitialised);
	
	for ( char ** arg = *argv[optioni]; **arg == '-' && in_options; arg++ ) {
		char *p = (*arg)+1;
		if ( ! *p ) {
			// todo error
			in_options = false;
			continue;
		}
		if ( *p == '-' ) {
			in_options = false;
			continue;
		}
		for (p++; isalnum(*p) && options[*p]; p++) {
		if ( *argv[i][1] == '-' ) {

