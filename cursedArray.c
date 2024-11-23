#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cursedArray.h"

GenericArray *GA_new(void) {
	GenericArray* genericArray = malloc(sizeof(GenericArray));
	genericArray->size = 0;
	genericArray->capacity = 2;
	genericArray->array = malloc(sizeof(Element*) * genericArray->capacity);
	return genericArray;
}

static void check_null(const GenericArray* genericArray, EXARG) {
	if (!genericArray) {
		fprintf(stderr, "exception - array object is null @ \"%s\" line %d\n", EXVAL);
		exit(-1);
	}
}

static void check_bound(const GenericArray* genericArray, size_t index, EXARG) {
	check_null(genericArray, EXVAL);
	if (index >= genericArray->size) {
		fprintf(stderr, "exception - index out of range (%zu >= %zu) @ \"%s\" line %d\n", index, genericArray->size, EXVAL);
		exit(-1);
	}
}

static void check_data(const GenericArray* genericArray, size_t index, EXARG) {
	check_bound(genericArray, index, EXVAL);
	if (!genericArray->array || !genericArray->array[index] || !genericArray->array[index]->element) {
		fprintf(stderr, "exception - array internal data structure corruption @ \"%s\" line %d\n", EXVAL);
		exit(-1);
	}
}

static void check_type(const GenericArray* genericArray, size_t index, const char *type, EXARG) {
	check_data(genericArray, index, EXVAL);
	if (strcmp(genericArray->array[index]->type, type)) {
		fprintf(stderr, "exception - type mismatch (expected \"%s\", got \"%s\") @ \"%s\" line %d\n", type, genericArray->array[index]->type, EXVAL);
		exit(-1);
	}
}

size_t __safe_GA_size(const GenericArray* genericArray, EXARG) {
	check_null(genericArray, EXVAL);
	return genericArray->size;
}

static void array_delete_element(GenericArray *genericArray, size_t index, EXARG) {
	check_data(genericArray, index, EXVAL);
	free(genericArray->array[index]->element);
	free(genericArray->array[index]);
	genericArray->array[index] = NULL;
}

void __safe_GA_clear(GenericArray *genericArray, EXARG) {
	check_null(genericArray, EXVAL);
	for (size_t i = 0; i < genericArray->size; i++) {
		array_delete_element(genericArray, i, EXVAL);
	}
	genericArray->size = 0;
}

void __safe_GA_delete(GenericArray **genericArray, EXARG) {
	if (*genericArray) {
		__safe_GA_clear(*genericArray, EXVAL);
		free((*genericArray)->array);
		free(*genericArray);
		*genericArray = NULL;
	}
}

static void increase_size(GenericArray* genericArray) {
	genericArray->size++;
	if (genericArray->size >= genericArray->capacity) {
		genericArray->capacity *= 2;
		genericArray->array = realloc(genericArray->array,
				sizeof(Element *) * genericArray->capacity);
	}
}

void __safe_GA_add(GenericArray* genericArray, const void* element, size_t size, const char *type, EXARG) {
	check_null(genericArray, EXVAL);
	increase_size(genericArray);

	Element* arrayElement = malloc(sizeof(Element));
	arrayElement->element = malloc(size);
	memcpy(arrayElement->element, element, size);
	arrayElement->size = size;
	arrayElement->type = type;

	genericArray->array[(genericArray->size) - 1] = arrayElement;
}

const char *__safe_GA_type(const GenericArray* genericArray, size_t index, EXARG) {
	check_data(genericArray, index, EXVAL);
	return genericArray->array[index]->type;
}

void *__safe_GA_get(const GenericArray* genericArray, size_t index, const char *type, EXARG) {
	check_type(genericArray, index, type, EXVAL);
	return genericArray->array[index]->element;
}
