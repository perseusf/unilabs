#ifndef COMPLEX_H
#define COMPLEX_H
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PI 3.14159265

typedef struct ComplexNumber {
    int Re;
    int Im;
    float arg;
    float mod;
} ComplexNumber;

//creation of a complex number from Re and Im
//ComplexNumber* complexCreate(int choice) {
//    ComplexNumber *complexFinal = malloc(sizeof(ComplexNumber));
//    int re, im;
//    switch (choice) {
//        case 1:
//            re = rand() % 100;
//            im = rand() % 100;
//        case 0:
//            printf("Re: ");
//            int re = 0;
//            scanf("%d\n", &re);
//            printf("Im: ");
//            int im = 0;
//            scanf("%d\n", &im);
//    }
//    complexFinal->Re = re;
//    complexFinal->Im = im;
//    complexFinal->mod = sqrt((complexFinal->Re) * (complexFinal->Re) + (complexFinal->Im) * (complexFinal->Im));
//    if (complexFinal->Re > 0) {
//        complexFinal->arg = atanf(complexFinal->Im / complexFinal->Re);
//    }
//    else if ((complexFinal->Re < 0) && (complexFinal->Im > 0)) {
//        complexFinal->arg = PI + atanf(complexFinal->Im / complexFinal->Re);
//    }
//    else {
//        complexFinal->arg = -PI + atanf(complexFinal->Im / complexFinal->Re);
//    }
//    return complexFinal;
//}

////print complex number in alg and trig form
//void complexPrint(struct ComplexNumber* num) {
//    if (num->Im > 0) {
//        printf("%d+%di, ", num->Re, num->Im);
//    }
//    else {
//        printf("%d%di, ", num->Re, num->Im);
//    }
//    printf("%f(cos(%f rad)+isin(%f rad))\n", num->mod, num->arg, num->arg);
//}

////алгебраические операции с комплексными числами
//struct ComplexNumber complex_math(ComplexNumber* comp1, ComplexNumber* comp2) {
//    ComplexNumber compNumber;
//    if (strncmp(sign, "+", 1) == 0) {
//        compNumber.Re = comp1->Re + comp2->Re;
//        compNumber.Im = comp1->Im + comp2->Im;
//        compNumber.mod = sqrt(powf(compNumber.Re, 2) + powf(compNumber.Im, 2));
//        if (compNumber.Re > 0) {
//            compNumber.arg = atanf(compNumber.Im / compNumber.Re);
//        }
//        else if ((compNumber.Re < 0) && (compNumber.Im > 0)) {
//            compNumber.arg = PI + atanf(compNumber.Im / compNumber.Re);
//        }
//        else {
//            compNumber.arg = -PI + atanf(compNumber.Im / compNumber.Re);
//        }
//    }
//    else if (strncmp(sign, "-", 1) == 0) {
//        compNumber.Re = comp1->Re - comp2->Re;
//        compNumber.Im = comp1->Im - comp2->Im;
//        compNumber.mod = sqrt(powf(compNumber.Re, 2) + powf(compNumber.Im, 2));
//        if (compNumber.Re > 0) {
//            compNumber.arg = atanf(compNumber.Im / compNumber.Re);
//        }
//        else if ((compNumber.Re < 0) && (compNumber.Im > 0)) {
//            compNumber.arg = PI + atanf(compNumber.Im / compNumber.Re);
//        }
//        else {
//            compNumber.arg = -PI + atanf(compNumber.Im / compNumber.Re);
//        }
//    }
//    else if (strncmp(sign, "*", 1) == 0) {
//        compNumber.mod = comp1->mod * comp2->mod;
//        compNumber.arg = comp1->arg + comp2->arg;
//        compNumber.Re = compNumber.mod * cosf(compNumber.arg);
//        compNumber.Im = compNumber.mod * sinf(compNumber.arg);
//    }
//    else if (strncmp(sign, "/", 1) == 0) {
//        compNumber.mod = comp1->mod / comp2->mod;
//        compNumber.arg = comp1->arg - comp2->arg;
//        compNumber.Re = compNumber.mod * cosf(compNumber.arg);
//        compNumber.Im = compNumber.mod * sinf(compNumber.arg);
//    }
//    else {
//        printf("Complex_simple_math: operation is not executable\n");
//        exit(228);
//    }
//    return compNumber;
//}

//возведение комплексного числа в натуральную степень
//struct ComplexNumber complex_pow(ComplexNumber* comp, int power) {
//    ComplexNumber compFinal;
//    if (power < 0) {
//        printf("Complex_pow: operation is not executable\n");
//        exit(228);
//    }
//    else {
//        compFinal.mod = powf(comp->mod, power);
//        compFinal.arg = power * comp->arg;
//        compFinal.Re = compFinal.mod * cosf(compFinal.arg);
//        compFinal.Im = compFinal.mod * sinf(compFinal.arg);
//    }
//    return compFinal;
//}

#endif
