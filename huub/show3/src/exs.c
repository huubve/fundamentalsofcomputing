
#include <stdio.h>
#include <stdlib.h>

#include "muls.h"

int	main(int argc, char *argv[]) {
	short x = (short)atoi(argv[1]);
	short y = (short)atoi(argv[2]);
	short z;

	z = multiply(x, y);

	printf("%hd x %hd = %hd\n",x, y, z);
	
	return 0;
}
