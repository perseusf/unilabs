#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "libs/ComplexNumber.h"

typedef struct array {
    int length;
    size_t elementSize;
    void* data;

    void* (*concatenate)(void*, void*);
} array;

array* complexArraySetKeyboard(int arrayLen) {
    array* arrayFinal = (array*)malloc(sizeof(array));
    arrayFinal->length = arrayLen;
    arrayFinal->elementSize = sizeof(ComplexNumber);
    arrayFinal->data = malloc(arrayLen*sizeof(ComplexNumber));
    for (int i = 0; i < arrayLen; i += 1) {
        printf("Re: ");
        int re = 0;
        scanf("%d\n", &re);
        printf("Im: ");
        int im = 0;
        scanf("%d\n", &im);
        *(arrayFinal->data + i) = complexCreate(re, im);
    }
    return arrayFinal;
}

array* complexArraySetRandom(int arrayLen) {
    array* arrayFinal = (array*)malloc(sizeof(array));
    arrayFinal->length = arrayLen;
    arrayFinal->elementSize = sizeof(ComplexNumber);
    arrayFinal->data = malloc(arrayLen*sizeof(ComplexNumber));
    int t = time(NULL);
    for (int i = 0; i < arrayLen; i += 1) {
        arrayFinal->data[i] = malloc(sizeof(ComplexNumber));
        arrayFinal->data[i] = complexSetRandom();
    }
    return arrayFinal;
}

void complexArrayPrint(void* array, int len) {
    for (int i = 0; i < len; i += 1) {
        printf("A[i] = %d + %di", array->data[i]->Re, array->data[i]->Im);
    }
}

array* intArraySetKeyboard(int arrayLen) {
    array* arrayFinal = (array*)malloc(sizeof(array));
    arrayFinal->length = arrayLen;
    arrayFinal->elementSize = sizeof(int);
    arrayFinal->data = (int*)malloc(sizeof(int));
    for (int i = 0; i < arrayLen; i += 1) {
        arrayFinal->data[i] = malloc(sizeof(int));
        printf("Data: ");
        scanf("%d", &arrayFinal->data[i]);
    }
    return arrayFinal;
}

array* intArraySetRandom(int arrayLen) {
    srand(time(NULL));
    array* arrayFinal = (array*)malloc(sizeof(array));
    arrayFinal->length = arrayLen;
    arrayFinal->elementSize = sizeof(int);
    arrayFinal->data = (int*)malloc(sizeof(int));
    for (int i = 0; i < arrayLen; i += 1) {
        arrayFinal->data[i] = malloc(sizeof(int*));
        arrayFinal = rand() % 100;
    }
    return arrayFinal;
}

void intArrayPrint(void* array, int N) {
    for (int i = 0; i < N; i += 1) {
        printf("A[i] = %d\n", &array[i]);
    }
}




void** arrayConcatenate(void** mass1, int N1, void** mass2, int N2) {
    void **concat = malloc(sizeof(void*) * (N1 + N2));
    if ((N1 == 0) || (N2 == 0)) {
        printf("\n***ERROR***\n");
        exit(1);
    }
    int i = 0, j = 0;

    while (i < N1) {
        concat[i] = mass1[i];
        i += 1;
    }
    while (j < N2) {
        concat[i] = mass2[j];
        i += 1;
        j += 1;
    }

    return concat;
}



//////////////////////////////////////////////

//void map(void** mass, int N, void(*f)(void*)) {
//    int i;
//
//    for (i = 0; i < N; i += 1) {
//        f(*(mass + i));
//    }
//}
//
//void** where(void** mass, int* N, bool(*f)(void*)) {
//    int i, j = 0;
//    void **arr = malloc(sizeof(void*) * (*N));
//
//    for (i = 0; i < *N; i += 1) {
//        if (f(*(mass + i)) == true) {
//            *(arr + j) = *(mass + i);
//            j += 1;
//        }
//    }
//    *N = j;
//
//    return arr;
//}
//
///*  SPECIAL FUNCTIONS TO CALL WITH MAP */
//
//void int_plus_one(void* element) {
//    *(int*)element += 1;
//}
//
//void int_minus_ten(void* element) {
//    *(int*)element -= 10;
//}
//
//void string_plus_1(void* element) {
//    struct string a;
//    a.str[0] = '1';
//    a.str[1] = '\0';
//    *(struct string*)element = arrayConcatenate((struct string*)element, &a);
//}
//
//void string_double(void* element) {
//    *(struct string*)element = arrayConcatenate((struct string*)element, (struct string*)element);
//}
//
//void string_make_less(void* element) {
//    int i = 0;
//
//    while (((struct string*)element)->str[i] != '\0') {
//        i += 1;
//    }
//
//    if (i != 0) {
//        ((struct string*)element)->str[i-1] = '\0';
//    }
//}
//
////////////////////////////////////////////////
//
///*  SPECIAL FUNCTIONS TO CALL WITH WHERE */
//
//bool more_than_10(void* element) {
//    bool l;
//    if (*(int*)element < 10) {
//        l = false;
//    }
//    else {
//        l = true;
//    }
//    return l;
//}
//
//bool less_than_10(void* element) {
//    bool l;
//    if (*(int*)element > 10) {
//        l = false;
//    }
//    else {
//        l = true;
//    }
//    return l;
//}
//
//bool larger_than_five(void* element) {
//    bool l;
//    int length = 0;
//    while (((struct string*)element)->str[length] != '\0') {
//        length += 1;
//    }
//    if (length >= 5) {
//        l = true;
//    }
//    else {
//        l = false;
//    }
//    return l;
//}
//
//bool smaller_than_five(void* element) {
//    bool l;
//    int length = 0;
//    while (((struct string*)element)->str[length] != '\0') {
//        length += 1;
//    }
//    if (length < 5) {
//        l = true;
//    }
//    else {
//        l = false;
//    }
//    return l;
//}

//////////////////////////////////////////////

void array_free(void** mass, int N) {
    int i;
    if (mass != NULL) {
        for (i = 0; i < N; i += 1) {
            free(*(mass + i));
        }
        free(mass);
    }
}

#endif

