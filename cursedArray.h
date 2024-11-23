// cursedArray.h

#ifndef CURSED_ARRAY_H
#define CURSED_ARRAY_H

#include <stddef.h>
#include <string.h>

#define TO_STR(x) #x

#define EXARG const char *f, int l
#define EXVAL f, l
#define EXDEF __FILE__, __LINE__

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

size_t __safe_GA_size(const GenericArray* genericArray, EXARG);
void __safe_GA_add(GenericArray* genericArray, const void* element, size_t size, const char *type, EXARG);
void *__safe_GA_get(const GenericArray* genericArray, size_t index, const char *type, EXARG);
const char *__safe_GA_type(const GenericArray* genericArray, size_t index, EXARG);
void __safe_GA_clear(GenericArray *genericArray, EXARG);
void __safe_GA_delete(GenericArray **genericArray, EXARG);

GenericArray* GA_new(void);
#define GA_size(arr) __safe_GA_size((arr), EXDEF)
#define GA_add(arr, elm, typ) \
	do \
	{ \
		typ __cpy##_LINE_ = elm; \
		__safe_GA_add(arr, &__cpy##_LINE_, sizeof(__cpy##_LINE_), TO_STR(typ), EXDEF); \
	} while (0)
#define GA_get(arr, idx, typ) *((typ *)__safe_GA_get((arr), (idx), TO_STR(typ), EXDEF))
#define GA_type(arr, idx) __safe_GA_type((arr), (idx), EXDEF)
#define GA_is_type(arr, idx, typ) !strcmp(GA_type((arr), (idx)), TO_STR(typ))
#define GA_clear(arr) __safe_GA_clear((arr), EXDEF)

// Won't work if it's in a register, but nobody uses registers these days...
#define GA_delete(arr) __safe_GA_delete(&(arr), EXDEF)

#endif
