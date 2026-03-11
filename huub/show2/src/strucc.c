#include "structured.h"
#include <stdio.h>
#include <stdlib.h>

INT main
FUNCTION
	INT	argc,
	CHAR *	argv[]
BODY
	INT	i = atoi(argv[1]);
	WHILE
		i-- > 0
	LOOP
		IF
			i % 2 == 0
		THEN
			printf("%s: Hello %s (even: %d).\n", argv[0], argv[2], i);
		ELSE
			printf("%s: Hello %s (odd:  %d).\n", argv[0], argv[2], i);
		END_IF
	END_LOOP
END_BODY
	
