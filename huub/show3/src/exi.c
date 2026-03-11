
#include <stdio.h>
#include <stdlib.h>

#include "muli.h"

int	main(int argc, char *argv[]) {
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	int z;

	z = multiply(x, y);

	printf("%d x %d = %d\n",x, y, z);
	
	return 0;
}
