#include "cursedArray.h"
#include "print.h"
#include <stddef.h>
#include <stdio.h>


int main() {
	GenericArray* genericArray = GA_new();

	//Testing
	int num = 5;
	float othernum = 7;
	char c = 'h';
	char* str = "hello world";
	unsigned int unum = 100;
	long longg = 500000;
	struct bruh { int num; char *str; } struc = { 10, "ten" };

	GA_add(genericArray, num, int);
	GA_add(genericArray, othernum, float);
	GA_add(genericArray, c, char);
	GA_add(genericArray, str, char *);
	GA_add(genericArray, unum, unsigned int);
	GA_add(genericArray, longg, long);
	GA_add(genericArray, 123, int);
	GA_add(genericArray, "i hate this", char *);
	GA_add(genericArray, struc, struct bruh);

	for (size_t i = 0; i < GA_size(genericArray); i++) {
		print(genericArray, i);
		printf("\n");
	}

	printf("genericArray[0] = %d\n", GA_get(genericArray, 0, int));
	struct bruh thing = GA_get(genericArray, 8, struct bruh);
	printf("genericArray[8] = { %d, \"%s\" }\n", thing.num, thing.str);
	// printf("genericArray[1] = %d\n", GA_get(genericArray, 1, int));
	GA_delete(genericArray);

	return 0;
}
