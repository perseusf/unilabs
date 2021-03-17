#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <complex.h>

//ARRAY STRUCTURE
typedef struct array {
    int length; //length of the array
    size_t elementSize; //size of a single element
    void* data; //pointer to the first element
} array;

//COMPLEX NUMBERS
array* complexArraySetKeyboard(int arrayLen);
array* complexArraySetRandom(int arrayLen);
void complexArrayPrint(array* a);

//INTEGERS
array* intArraySetKeyboard(int arrayLen);
void intArrayPrint(array* a);
array* intArraySetRandom(int arrayLen);

//OPERATIONS
array* concatenate (array *a1, array *a2);

//MAP
array* Map (array *a, void (*function) (void *elementOfArray));
void int_square(void* item);
void int_substr_one(void* item);
void complex_square(void* item);
void complex_mult_2(void* item) ;

//WHERE
array* where (array *a, bool (*function) (void *item));
bool more_than_50(void* item);
bool less_than_50(void* element);
bool re_more_than_50(void* item);
bool re_less_than_50(void* item);

//OTHER
void array_free(array* array);
#endif
