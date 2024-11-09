#include "cursedArray.h"
#include "print.h"
#include <stddef.h>
#include <stdio.h>


int main() {
    GenericArray* genericArray = init();

    //Testing
    int num = 5;
    float othernum = 7;
    char c = 'h';
    char* str = "hello world";
    unsigned int unum = 100;
    long longg = 500000;
	struct bruh { int num; char *str; } struc = { 10, "ten" };

    add_element(genericArray, num, int);
    add_element(genericArray, othernum, float);
    add_element(genericArray, c, char);
    add_element(genericArray, str, char *);
    add_element(genericArray, unum, unsigned int);
    add_element(genericArray, longg, long);
    add_element(genericArray, 123, int);
    add_element(genericArray, (char *)"i hate this", char *);
    add_element(genericArray, struc, struct bruh);

    for (size_t i = 0; i < get_size(genericArray); i++) {
		print(genericArray, i);
        printf("\n");
    }

	printf("genericArray[0] = %d\n", get_element(genericArray, 0, int));
	struct bruh thing = get_element(genericArray, 8, struct bruh);
	printf("genericArray[8] = { %d, \"%s\" }\n", thing.num, thing.str);
	printf("genericArray[1] = %d\n", get_element(genericArray, 1, int));

    return 0;
}
