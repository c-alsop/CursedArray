// cursedArray.h

#ifndef CURSED_ARRAY_H
#define CURSED_ARRAY_H

#include <stddef.h>
#include <string.h>

#define TO_STR(x) #x

typedef struct {
    void* element;
    size_t size;
	const char *type;
} Element;

typedef struct {
    Element** array;
    size_t size;
    size_t capacity;
} GenericArray;

GenericArray* init(void);
void increase_size(GenericArray* genericArray);
void append_element(GenericArray* genericArray, const void* element, size_t size, const char *type);


size_t __safe_get_array_size(const GenericArray* genericArray, const char *f, int l);
const char *__safe_get_element_type(const GenericArray* genericArray, size_t index, const char *f, int l);
void *__safe_get_element(const GenericArray* genericArray, size_t index, const char *type, const char *f, int l);

#define get_size(arr) __safe_get_array_size((arr), __FILE__, __LINE__)
#define add_element(arr, elm, typ) \
	do \
	{ \
		typeof(elm) __cpy##_LINE_ = elm; \
		append_element(arr, &__cpy##_LINE_, sizeof(__cpy##_LINE_), TO_STR(typ)); \
	} while (0) \

#define get_element_type(arr, idx) __safe_get_element_type((arr), (idx), __FILE__, __LINE__)
#define get_element(arr, idx, typ) *((typ *)__safe_get_element((arr), (idx), TO_STR(typ), __FILE__, __LINE__))
#define check_element_type(arr, idx, typ) !strcmp(get_element_type((arr), (idx)), TO_STR(typ))

#endif
