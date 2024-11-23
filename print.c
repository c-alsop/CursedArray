//print.c
#include "print.h"
#include <stdio.h>

// What are you even doing here...
// [A few days later] Yeah, wtf is this...

void print(const GenericArray* genericArray, size_t index) {
	if (GA_is_type(genericArray, index, char)) {
		printf("%c", GA_get(genericArray, index, char));
	} else if (GA_is_type(genericArray, index, int)) {
		printf("%d", GA_get(genericArray, index, int));
	} else if (GA_is_type(genericArray, index, float)) {
		printf("%f", GA_get(genericArray, index, float));
	} else if (GA_is_type(genericArray, index, char *)) {
		printf("%s", GA_get(genericArray, index, char *));
	} else if (GA_is_type(genericArray, index, unsigned int)) {
		printf("%u", GA_get(genericArray, index, unsigned int));
	} else if (GA_is_type(genericArray, index, long)) {
		printf("%ld", GA_get(genericArray, index, long));
	} else if (GA_is_type(genericArray, index, unsigned long)) {
		printf("%lu", GA_get(genericArray, index, unsigned long));
	} else if (GA_is_type(genericArray, index, long long)) {
		printf("%lld", GA_get(genericArray, index, long long));
	} else if (GA_is_type(genericArray, index, unsigned long long)) {
		printf("%llu", GA_get(genericArray, index, unsigned long long));
	} else if (GA_is_type(genericArray, index, double)) {
		printf("%lf", GA_get(genericArray, index, double));
	} else if (GA_is_type(genericArray, index, long double)) {
		printf("%Lf", GA_get(genericArray, index, long double));
	} else {
		printf("Could not print variables of type \"%s\"", GA_type(genericArray, index));
	}
}
