#include "libs/array.h"

int main(void) {
    array *int1 = NULL, *int2 = NULL, *complex1 = NULL, *complex2 = NULL, *concatInt = NULL, *concatComplex = NULL,
    *mapComplex1 = NULL, *mapComplex2 = NULL, *mapInt1 = NULL, *mapInt2 = NULL;
    array *whereComplex1 = NULL, *whereComplex2 = NULL, *whereInt1 = NULL, *whereInt2 = NULL;
    int intlen1, intlen2, complexlen1, complexlen2, choice;

    printf("Let's create two INTEGER arrays...\n");
    printf("Please, enter the length of the first array: ");
    scanf("%d", &intlen1);
    while (intlen1 < 0) {
        printf("Why are you trying to initialize an array with negative length?\nLet's try again!\n");
        printf("Enter the length of the array: ");
        scanf("%d", &intlen1);
    }
    getchar();
    printf("Generate | Keyboard (1/0)?: ");
    scanf("%d", &choice);
    while ((choice < 0) || (choice > 1)) {
        printf("Error. Let's try again!\n");
        printf("Generate | Keyboard (1/0)?: ");
        scanf("%d", &choice);
    }
    getchar();
    if (choice == 0) {
        int1 = intArraySetKeyboard(intlen1);
    }
    else {
        int1 = intArraySetRandom(intlen1);
    }
    printf("And now for the second one: ");
    scanf("%d", &intlen2);
    while (intlen2 < 0) {
        printf("Why are you trying to initialize an array with negative length?\nLet's try again!\n");
        printf("Enter the length of the array: ");
        scanf("%d", &intlen2);
    }
    getchar();
    printf("Generate | Keyboard (1/0)?: ");
    scanf("%d", &choice);
    while ((choice < 0) || (choice > 1)) {
        printf("Error. Let's try again!\n");
        printf("Generate | Keyboard (1/0)?: ");
        scanf("%d", &choice);
    }
    getchar();
    if (choice == 0) {
        int2 = intArraySetKeyboard(intlen2);
    } else {
        int2 = intArraySetRandom(intlen2);
    }

    printf("What about two COMPLEX NUMBER arrays...\n");
    printf("Length of the first array: ");
    scanf("%d", &complexlen1);
    while (complexlen1 < 0) {
        printf("Why are you trying to initialize an array with negative length?\nLet's try again!\n");
        printf("Enter the length of the array: ");
        scanf("%d", &complexlen1);
    }
    getchar();
    printf("Generate | Keyboard (1/0)?: ");
    scanf("%d", &choice);
    while ((choice < 0) || (choice > 1)) {
        printf("Error. Let's try again!\n");
        printf("Generate | Keyboard (1/0)?: ");
        scanf("%d", &choice);
    }
    getchar();
    if (choice == 0) {
        complex1 = complexArraySetKeyboard(complexlen1);
    } else {
        complex1 = complexArraySetRandom(complexlen1);
    }
    printf("And the length of the second one?: ");
    scanf("%d", &complexlen2);
    while (complexlen2 < 0) {
        printf("Why are you trying to initialize an array with negative length?\nLet's try again!\n");
        printf("Enter the length of the array: ");
        scanf("%d", &complexlen2);
    }
    getchar();
    printf("Generate | Keyboard (1/0)?: ");
    scanf("%d", &choice);
    while ((choice < 0) || (choice > 1)) {
        printf("Error. Let's try again!\n");
        printf("Generate | Keyboard (1/0)?: ");
        scanf("%d", &choice);
    }
    getchar();
    if (choice == 0) {
        complex2 = complexArraySetKeyboard(complexlen2);
    } else {
        complex2 = complexArraySetRandom(complexlen2);
    }

    choice = 1;
    while (choice != 0) {
        printf("\n");
        printf("1. Print arrays\n");
        printf("2. Reinitialize arrays\n");
        printf("3. Concatinate arrays\n");
        printf("4. Map functions\n");
        printf("5. Where functions\n");
        printf("0. Exit\n");
        printf("Choice: ");
        
        scanf("%d", &choice);
        while ((choice < 0) || (choice > 5)) {
            printf("ERROR\nPlease, try again!\n");
            printf("Choice: ");
            scanf("%d", &choice);
        }
        getchar();
        printf("\n");
        
        if (choice == 0) {
            system("cat ./libs/bye.txt");
	    printf("\n");
            break;
        }

        if (choice == 1) {
            printf("INTEGERS 1: ");
            intArrayPrint(int1);
            printf("INTEGERS 2: ");
            intArrayPrint(int2);
            printf("\n");
            printf("COMPLEX NUMBERS 1: ");
            complexArrayPrint(complex1);
            printf("COMPLEX NUMBERS 2: ");
            complexArrayPrint(complex2);
            printf("\n");
            if (concatInt != NULL) {
                printf("CONCATINATED INTEGERS: ");
                intArrayPrint(concatInt);
            }
            if (concatComplex != NULL) {
                printf("CONCATINATED COMPLEX NUMBERS: ");
                complexArrayPrint(concatComplex);
                printf("\n");
            }
            if (mapComplex1 != NULL) {
                printf("MAP1 COMPLEX NUMBERS: ");
                complexArrayPrint(mapComplex1);
            }
            if (mapComplex2 != NULL) {
                printf("MAP2 COMPLEX NUMBERS: ");
                complexArrayPrint(mapComplex2);
                printf("\n");
            }
            if (mapInt1 != NULL) {
                printf("MAP1 INTEGERS: ");
                intArrayPrint(mapInt1);
            }
            if (mapInt2 != NULL) {
                printf("MAP2 INTEGERS: ");
                intArrayPrint(mapInt2);
                printf("\n");
            }
            if (whereComplex1 != NULL) {
                printf("WHERE1 COMPLEX NUMBERS: ");
                intArrayPrint(whereComplex1);
            }
            if (whereComplex2 != NULL) {
                printf("WHERE2 COMPLEX NUMBERS: ");
                intArrayPrint(whereComplex2);
                printf("\n");
            }
            if (whereInt1 != NULL) {
                printf("WHERE1 INTEGERS: ");
                intArrayPrint(whereInt1);
            }
            if (whereInt2 != NULL) {
                printf("WHERE2 INTEGERS: ");
                intArrayPrint(whereInt2);
                printf("\n");
            }
        }

        if (choice == 2) {
            printf("SELECT THE ARRAY TO REINITIALIZE:\n");
            printf("1. INTEGERS_1\n");
            printf("2. INTEGERS_2\n");
            printf("3. COMPLEX_NUMBERS_1\n");
            printf("4. COMPLEX_NUMBERS_2\n");
            printf("Which one?: ");
            scanf("%d", &choice);
            while ((choice < 0) || (choice > 4)) {
                printf("ERROR\nPlease, try again!\n");
                printf("Which one?: ");
                scanf("%d", &choice);
            }
            getchar();

            if (choice == 1) {
                array_free(int1);
                printf("Enter the length of the array: ");
                scanf("%d", &intlen1);
                while (intlen1 < 0) {
                    printf("Why are you trying to initialize an array with negative length?\nLet's try again!\n");
                    printf("Enter the length of the array: ");
                    scanf("%d", &intlen1);
                }
                getchar();
                printf("Generate | Keyboard (1/0)?: ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 1)) {
                    printf("Error. Let's try again!\n");
                    printf("Generate | Keyboard (1/0)?: ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 0) {
                    int1 = intArraySetKeyboard(intlen1);
                }
                else {
                    int1 = intArraySetRandom(intlen1);
                }
            }

            if (choice == 2) {
                array_free(int2);
                printf("Enter the length of the array: ");
                scanf("%d", &intlen2);
                while (intlen2 < 0) {
                    printf("Why are you trying to initialize an array with negative length?\nLet's try again!\n");
                    printf("Enter the length of the array: ");
                    scanf("%d", &intlen2);
                }
                getchar();
                printf("Generate | Keyboard (1/0)?: ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 1)) {
                    printf("Error. Let's try again!\n");
                    printf("Generate | Keyboard (1/0)?: ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 0) {
                    int2 = intArraySetKeyboard(intlen2);
                } else {
                    int2 = intArraySetRandom(intlen2);
                }
            }

            if (choice == 3) {
                array_free(complex1);
                printf("Enter the length of the array: ");
                scanf("%d", &complexlen1);
                while (complexlen1 < 0) {
                    printf("Why are you trying to initialize an array with negative length?\nLet's try again!\n");
                    printf("Enter the length of the array: ");
                    scanf("%d", &complexlen1);
                }
                getchar();
                printf("Generate | Keyboard (1/0)?: ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 1)) {
                    printf("Error. Let's try again!\n");
                    printf("Generate | Keyboard (1/0)?: ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 0) {
                    complex1 = complexArraySetKeyboard(complexlen1);
                } else {
                    complex1 = complexArraySetRandom(complexlen1);
                }
            }

            if (choice == 4) {
                array_free(complex2);
                printf("Enter the length of the array: ");
                scanf("%d", &complexlen2);
                while (complexlen2 < 0) {
                    printf("Why are you trying to initialize an array with negative length?\nLet's try again!\n");
                    printf("Enter the length of the array: ");
                    scanf("%d", &complexlen2);
                }
                getchar();
                printf("Generate | Keyboard (1/0)?: ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 1)) {
                    printf("Error. Let's try again!\n");
                    printf("Generate | Keyboard (1/0)?: ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 0) {
                    complex2 = complexArraySetKeyboard(complexlen2);
                } else {
                    complex2 = complexArraySetRandom(complexlen2);
                }
            }

            printf("Reinitialized successfully!\n");
            choice = 1;

        }

        if (choice == 3) {
            concatInt = concatenate(int1, int2);
            concatComplex = concatenate(complex1, complex2);
            printf("INTEGER 1 + INTEGER 2: ");
            intArrayPrint(concatInt);
            printf("\n");
            printf("COMPLEX NUMBER 1 + COMPLEX NUMBER 2: ");
            complexArrayPrint(concatComplex);
            printf("\n");
        }

        if (choice == 4) {
            printf("SELECT TYPE OF AN ARRAY: \n");
            printf("1. Integers\n");
            printf("2. Complex numbers\n");
            scanf("%d", &choice);
            while ((choice < 1) || (choice > 2)) {
                printf("Oh no... That's no good. ERROR.\n");
                scanf("%d", &choice);
                printf("\n");
            }
            getchar();

            if (choice == 1) {
                printf("Avalaible functions:\n");
                printf("1. Square the integers\n");
                printf("2. Substract 1\n");
                printf("Your decision?: ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 2)) {
                    printf("Oh no... That's no good. ERROR.\n");
                    printf("Fine, I'll give you some more chances...: ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 1) {
                    mapInt1 = Map(int1, int_square);
                    mapInt2 = Map(int2, int_square);
                } else {
                    mapInt1 = Map(int1, int_substr_one);
                    mapInt2 = Map(int2, int_substr_one);
                }
            } else {
                printf("You have to decide which one to use:\n");
                printf("1. Square complex numbers\n");
                printf("2. Multiply complex numbers by 2\n");
                printf("Your decision?: ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 2)) {
                    printf("Oh no... That's no good. ERROR.\n");
                    printf("Fine, I'll give you some more chances...: ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 1) {
                    mapComplex1 = Map(complex1, complex_square);
                    mapComplex2 = Map(complex2, complex_square);
                }
                else {
                    mapComplex1 = Map(complex1, complex_mult_2);
                    mapComplex2 = Map(complex2, complex_mult_2);
                }
            }
            printf("Done\n");
            choice = 1;
        }

        if (choice == 5) {
            printf("SELECT TYPE OF AN ARRAY: \n");
            printf("1. Integers\n");
            printf("2. Complex numbers\n");
            scanf("%d", &choice);
            while ((choice < 1) || (choice > 2)) {
                printf("Hey, there's no such option!\n");
                printf("Let's try again: ");
                scanf("%d", &choice);
            }
            getchar();

            if (choice == 1) {
                printf("Here is some stuff you can do to integers:\n");
                printf("1. Integer is more than 50\n");
                printf("2. Integer is less than 50\n");
                printf("Your decision?: ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 2)) {
                    printf("Hey, there's no such option!\n");
                    printf("Let's try again: ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 1) {
                    whereInt1 = where(int1, more_than_50);
                    whereInt2 = where(int2, more_than_50);
                }
                else {
                    whereInt1 = where(int1, less_than_50);
                    whereInt2 = where(int2, less_than_50);
                }
            }
            else {
                printf("List of some functions for complex numbers:\n");
                printf("1. Re is more than 50\n");
                printf("2. Re is less than 50\n");
                printf("Your choice?: ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 2)) {
                    printf("Oh no, something's gone wrong!");
                    printf("Nevermind, you can try again!: ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 1) {
                    complex1 = where(complex1, re_more_than_50);
                    complex2 = where(complex2, re_more_than_50);
                }
                else {
                    complex1 = where(complex1, re_less_than_50);
                    complex2 = where(complex2, re_less_than_50);
                }
            }
            printf("Success!\n");
            choice = 1;
        }
    }

//freeing all arrays
    array_free(int1);
    array_free(int2);
    array_free(complex1);
    array_free(complex2);
    array_free(concatInt);
    array_free(concatComplex);
    array_free(mapInt1);
    array_free(mapInt2);
    array_free(mapComplex1);
    array_free(mapComplex2);
    array_free(whereInt1);
    array_free(whereInt2);
    array_free(whereComplex1);
    array_free(whereComplex2);
    return 0;
}
