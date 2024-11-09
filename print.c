//print.c
#include "print.h"
#include <stdio.h>

// What are you even doing here...

void print(const GenericArray* genericArray, size_t index) {
	const char *type = get_element_type(genericArray, index);
	if (!strcmp(type, "char")) {
		printf("%c", get_element(genericArray, index, char));
	} else if (!strcmp(type, "int")) {
		printf("%d", get_element(genericArray, index, int));
	} else if (!strcmp(type, "float")) {
		printf("%f", get_element(genericArray, index, float));
	} else if (!strcmp(type, "char *")) {
		printf("%s", get_element(genericArray, index, char *));
	} else if (!strcmp(type, "unsigned int")) {
		printf("%u", get_element(genericArray, index, unsigned int));
	} else if (!strcmp(type, "long")) {
		printf("%ld", get_element(genericArray, index, long));
	} else if (!strcmp(type, "unsigned long")) {
		printf("%lu", get_element(genericArray, index, unsigned long));
	} else if (!strcmp(type, "long long")) {
		printf("%lld", get_element(genericArray, index, long long));
	} else if (!strcmp(type, "unsigned long long")) {
		printf("%llu", get_element(genericArray, index, unsigned long long));
	} else if (!strcmp(type, "double")) {
		printf("%lf", get_element(genericArray, index, double));
	} else if (!strcmp(type, "long double")) {
		printf("%Lf", get_element(genericArray, index, long double));
	} else {
		printf("Could not print");
	}
}
