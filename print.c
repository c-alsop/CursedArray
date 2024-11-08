//print.c
#include "print.h"
#include <stdio.h>

void print_char(void* element) {
    printf("%c", *(char*)element);
}

void print_int(void* element) {
    printf("%d", *(int*)element);
}

void print_float(void* element) {
    printf("%f", *(float*)element);
}

void print_string(void* element) {
    printf("%s", *(char**)element);
}

void print_unsigned_int(void* element) {
    printf("%u", *(unsigned int*)element);
}

void print_long(void* element) {
    printf("%ld", *(long*)element);
}

void print_unsigned_long(void* element) {
    printf("%lu", *(unsigned long*)element);
}

void print_long_long(void* element) {
    printf("%lld", *(long long*)element);
}

void print_unsigned_long_long(void* element) {
    printf("%llu", *(unsigned long long*)element);
}

void print_double(void* element) {
    printf("%lf", *(double*)element);
}

void print_long_double(void* element) {
    printf("%Lf", *(long double*)element);
}

void print_default(void) {
    printf("ERROR: Type Unprintable");
}
