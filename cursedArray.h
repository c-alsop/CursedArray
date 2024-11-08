// cursedArray.h
#include <stddef.h>

#ifndef CURSED_ARRAY_H
#define CURSED_ARRAY_H

#define append(array, element) _Generic((element), \
    char*: append_element(array, element, CHAR), \
    unsigned char*: append_element(array, element, CHAR), \
    short*: append_element(array, element, INT), \
    unsigned short*: append_element(array, element, U_INT), \
    int*: append_element(array, element, INT), \
    unsigned int*: append_element(array, element, U_INT), \
    long*: append_element(array, element, LONG), \
    unsigned long*: append_element(array, element, U_LONG), \
    long long*: append_element(array, element, LONG_LONG), \
    unsigned long long*: append_element(array, element, U_LONG_LONG), \
    float*: append_element(array, element, FLOAT), \
    double*: append_element(array, element, DOUBLE), \
    long double*: append_element(array, element, LONG_DOUBLE), \
    char**: append_element(array, element, STRING), \
    FILE**: append_element(array, element, FILE_HANDLER), \
    default: append_element(array, element, OTHER))

typedef struct {
    void* element;
    int type;
} Element;

typedef struct {
    Element** array;
    size_t size;
    size_t capacity;
} GenericArray;

typedef enum {
    INT,
    U_INT,
    FLOAT,
    CHAR,
    STRING,
    LONG,
    U_LONG,
    LONG_LONG,
    U_LONG_LONG,
    DOUBLE,
    LONG_DOUBLE,
    FILE_HANDLER,
    OTHER
} Type;


GenericArray* init(void);
void increase_size(GenericArray* genericArray);
void append_element(GenericArray* genericArray, void* element, int type);

#endif
