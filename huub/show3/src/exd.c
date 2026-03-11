
#include <stdio.h>
#include <stdlib.h>

#include "muld.h"

int	main( int argc, char *argv[] ) {
	double x = atof(argv[1]);
	double y = atof(argv[2]);
	double z;

	z = multiply(x, y);

	printf("%lg x %lg = %lg\n",x, y, z);
	
	return 0;
}
