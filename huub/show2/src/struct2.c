#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct person {
	char * name;
	short length;/* in cm */
	struct person * spouse; /* just one spouse, not an array until we learned about calloc */
} person_t;

char * hn= "huub";

int marry( person_t * a, person_t * b) {
	if ( a && b ) {
		a->spouse = b;
		b->spouse = a;
		return 1;
	} else {
		return 0;
	}
}

int main(){
	person_t jess = {"jessica", 177};
	person_t huub = { .name = hn, .length=176};
	printf("%p\n", (void *)&(huub.name[0]));
	marry(&huub, &jess);
	/*
	strcpy(huub.name, "jhjhfkhjghgkjhkjhkjhkjhkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhg");
	*/
	huub.name = "jhjhfkhjghgkjhkjhkjhkjhkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhgkjhg";
	printf("%p\n", (void *)&(huub.name[0]));
	printf("%s %d %s\n", huub.name, huub.length, huub.spouse->name);
	return EXIT_SUCCESS;
}
