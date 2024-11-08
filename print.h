// print.h

#ifndef PRINT_H
#define PRINT_H

#define print(element, type) \
    switch(type) { \
        case INT: \
            print_int(element);\
            break; \
        case U_INT: \
            print_unsigned_int(element);\
            break; \
        case FLOAT: \
            print_float(element);\
            break; \
        case CHAR: \
            print_char(element);\
            break; \
        case STRING: \
            print_string(element);\
            break; \
        case LONG: \
            print_long(element);\
            break; \
        case U_LONG: \
            print_unsigned_long(element);\
            break; \
        case LONG_LONG: \
            print_long_long(element);\
            break; \
        case U_LONG_LONG: \
            print_unsigned_long_long(element);\
            break; \
        case DOUBLE: \
            print_double(element);\
            break; \
        case LONG_DOUBLE: \
            print_long_double(element);\
            break; \
        default: \
            print_default(); \
            break; \
    }\

void print_char(void* element);
void print_int(void* element);
void print_float(void* element);
void print_string(void* element);
void print_unsigned_int(void* element);
void print_long(void* element);
void print_unsigned_long(void* element);
void print_long_long(void* element);
void print_unsigned_long_long(void* element);
void print_double(void* element);
void print_long_double(void* element);
void print_default(void);

#endif
