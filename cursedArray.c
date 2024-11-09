#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cursedArray.h"

GenericArray* init(void) {
    GenericArray* genericArray = malloc(sizeof(GenericArray));
    genericArray->size = 0;
    genericArray->capacity = 2;
    genericArray->array = malloc(sizeof(Element*) * genericArray->capacity);
    return genericArray;
}

void increase_size(GenericArray* genericArray) {
    genericArray->size++;
    if (genericArray->size >= genericArray->capacity) {
        genericArray->capacity *= 2;
        genericArray->array = realloc(genericArray->array,
                sizeof(Element*) * genericArray->capacity);
    }
}

void append_element(GenericArray* genericArray, const void* element, size_t size, const char *type) {
    increase_size(genericArray);

    Element* arrayElement = malloc(sizeof(Element));
    arrayElement->element = malloc(size);
	memcpy(arrayElement->element, element, size);
    arrayElement->size = size;
    arrayElement->type = type;

    genericArray->array[(genericArray->size) - 1] = arrayElement;
}

static void check_null(const GenericArray* genericArray, const char *f, int l) {
	if (!genericArray) {
		fprintf(stderr, "array object is null @ \"%s\" line %d\n", f, l);
		exit(-1);
	}
}

static void check_bound(const GenericArray* genericArray, size_t index, const char *f, int l) {
	check_null(genericArray, f, l);
	if (index >= genericArray->size) {
		fprintf(stderr, "index out of range (%zu >= %zu) @ \"%s\" line %d\n", index, genericArray->size, f, l);
		exit(-1);
	}
}

size_t __safe_get_array_size(const GenericArray* genericArray, const char *f, int l) {
	check_null(genericArray, f, l);
	return genericArray->size;
}

const char *__safe_get_element_type(const GenericArray* genericArray, size_t index, const char *f, int l) {
	check_null(genericArray, f, l);
	check_bound(genericArray, index, f, l);
	return genericArray->array[index]->type;
}

void *__safe_get_element(const GenericArray* genericArray, size_t index, const char *type, const char *f, int l) {
	check_null(genericArray, f, l);
	check_bound(genericArray, index, f, l);
	Element *arrayElement = genericArray->array[index];
	if (strcmp(arrayElement->type, type)) {
		fprintf(stderr, "exception - type mismatch (expected \"%s\", got \"%s\") @ \"%s\" line %d\n", type, arrayElement->type, f, l);
		exit(-1);
	}
	return arrayElement->element;
}
