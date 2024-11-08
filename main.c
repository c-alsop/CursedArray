#include "cursedArray.h"
#include "print.h"
#include <stddef.h>
#include <stdio.h>


int main() {
    GenericArray* genericArray = init();

    //Testing
    int num = 5;
    float othernum = 7;
    char c = 'h';
    char* str = "hello world";
    unsigned int unum = 100;
    long longg = 500000;

    append(genericArray, &num);
    append(genericArray, &othernum);
    append(genericArray, &c);
    append(genericArray, &str);
    append(genericArray, &unum);
    append(genericArray, &longg);

    for (size_t i = 0; i < genericArray->size; i++) {
            print(genericArray->array[i]->element, genericArray->array[i]->type);
        printf("\n");
    }
    return 0;
}
