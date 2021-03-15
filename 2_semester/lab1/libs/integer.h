#ifndef INTEGER_H
#define INTEGER_H
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//INTEGERS
//ok
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
void intArrayPrint(array* a) {
    for (size_t i = 0; i < a->length; i++) {
        printf("%d ", *(int*)(a->data + i * a->elementSize));
    }
    printf("\n");
}


#endif
