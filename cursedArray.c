#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
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

void append_element(GenericArray* genericArray, void* element, int type) {
    increase_size(genericArray);

    Element* arrayElement = malloc(sizeof(Element));
    arrayElement->element = element;
    arrayElement->type = type;

    genericArray->array[(genericArray->size) - 1] = arrayElement;
}

