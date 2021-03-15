#include "array.h"

//COMPLEX NUMBERS
array* complexArraySetKeyboard(int arrayLen) {
    array* arrayFinal = (array*)malloc(sizeof(array));
    arrayFinal->length = arrayLen;
    arrayFinal->elementSize = sizeof(complex double);
    complex double* temparray = malloc(sizeof(complex double) * arrayLen);
    for (int i = 0; i < arrayLen; i += 1) {
        printf("Re: ");
        double re = 0;
        scanf("%lf", &re);
        printf("Im: ");
        double im = 0;
        scanf("%lf", &im);
        complex double result = re + im * I;
        temparray[i] = result;
        printf("\n");
    }
    arrayFinal->data = temparray;
    return arrayFinal;
}
//array* complexArraySetRandom(int arrayLen) {
//    array* arrayFinal = (array*)malloc(sizeof(array));
//    arrayFinal->length = arrayLen;
//    arrayFinal->elementSize = sizeof(ComplexNumber);
//    arrayFinal->data = malloc(arrayLen*sizeof(ComplexNumber));
//    int t = time(NULL);
//    for (int i = 0; i < arrayLen; i += 1) {
//        arrayFinal->data[i] = malloc(sizeof(ComplexNumber));
//        arrayFinal->data[i] = complexSetRandom();
//    }
//    return arrayFinal;
//}
void complexArrayPrint(array* a) {
    for (size_t i = 0; i < a->length; i++){
        complex double number = *((complex double*) (a->data + i * a->elementSize));
        printf("%.2lf+", creal(number));
        printf("%.2lfi  ", cimag(number));
    }
    printf("\n");
}

//INTEGERS
array* intArraySetKeyboard(int arrayLen) {
    array* arrayFinal = (array*)malloc(sizeof(array));
    arrayFinal->length = arrayLen;
    arrayFinal->elementSize = sizeof(int);
    int* tempArray = (int*)malloc(sizeof(int)*arrayLen);
    printf("Please, enter %d integers: \n", arrayLen);
    for (int i = 0; i < arrayLen; i += 1) {
        scanf("%d", &tempArray[i]);
    }
    arrayFinal->data = tempArray;
    return arrayFinal;
}
void intArrayPrint(array* a) {
    for (size_t i = 0; i < a->length; i++) {
        printf("%d ", *(int*)(a->data + i * a->elementSize));
    }
    printf("\n");
}
//array* intArraySetRandom(int arrayLen) {
//    srand(time(NULL));
//    array* arrayFinal = (array*)malloc(sizeof(array));
//    arrayFinal->length = arrayLen;
//    arrayFinal->elementSize = sizeof(int);
//    arrayFinal->data = (int*)malloc(sizeof(int));
//    for (int i = 0; i < arrayLen; i += 1) {
//        arrayFinal->data[i] = malloc(sizeof(int*));
//        arrayFinal = rand() % 100;
//    }
//    return arrayFinal;
//}

//OPERATIONS
array* concatenate (array *a1, array *a2) {
    array* arrayFinal = (array*)malloc(sizeof(array));
    arrayFinal->length = a1->length + a2->length;
    arrayFinal->elementSize = a1->elementSize;
    arrayFinal->data = malloc(arrayFinal->length * arrayFinal->elementSize);
    memcpy(arrayFinal->data, a1->data, a1->length * a1->elementSize);
    memcpy(arrayFinal->data + a1->length * a1->elementSize, a2->data, a2->length * a2->elementSize);
    return arrayFinal;
}

//MAP
array* Map (array *a, void (*function) (void *elementOfArray)) {
    array* arrayFinal = (array*)malloc(sizeof(array));
    arrayFinal->length = a->length;
    arrayFinal->elementSize = a->elementSize;
    arrayFinal->data = malloc(a->elementSize * a->length);
    memcpy(arrayFinal->data, a->data, a->length * a->elementSize);
    for (size_t i = 0; i < a->length; i++)
        function(arrayFinal->data + i * a->elementSize);

    return arrayFinal;
}

void int_square(void* item) {
    *(int*)item *= *(int*)item;
}

void int_substr_one(void* item) {
    *(int*)item -= 1;
}

void complex_square(void* item) {
    *((complex double*) item) *= *((complex double*) item);
}

void complex_mult_2(void* item) {
    *((complex double*) item) *= 2;
}


//WHERE
array* where (array *a, bool (*function) (void *item)) {
    array* arrayFinal = (array*)malloc(sizeof(array));
    arrayFinal->length = a->length;
    arrayFinal->elementSize = a->elementSize;
    arrayFinal->data = malloc(a->elementSize * a->elementSize);
    size_t updatedLength = 0;
    for (size_t i = 0; i < a->length; i++) {
        bool isTrue = function(a->data + i * a->elementSize);
        if (isTrue) {
            memcpy(arrayFinal->data + updatedLength * arrayFinal->elementSize, a->data + i * a->elementSize, a->elementSize);
            updatedLength++;
        }
    }
    arrayFinal->length = updatedLength;
    return arrayFinal;
}

bool more_than_5(void* item) {
    bool l;
    if (*(int*)item < 5) {
        l = false;
    }
    else {
        l = true;
    }
    return l;
}

bool less_than_5(void* element) {
    bool l;
    if (*(int*)element > 5)
        l = false;
    else
        l = true;
    return l;
}

bool has_positive_re(void* item) {
    bool l;
    if (creal(*(complex double*)item) > 0)
        l = true;
    else
        l = false;
    return l;
}

bool has_negative_re(void* item) {
    bool l;
    if (creal(*(complex double*)item) <= 0)
        l = true;
    else
        l = false;
    return l;
}

void array_free(array* array) {
    free(array->data);
}