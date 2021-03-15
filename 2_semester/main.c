#include "libs/array.c"

int main(void) {
    array *int1 = NULL, *int2 = NULL, *complex1 = NULL, *complex2 = NULL, *concatInt = NULL, *concatComplex = NULL;
    int intlen1, intlen2, complexlen1, complexlen2, choice;

    printf("Let's create two INTEGER arrays...\n");
    printf("Please, enter the length of the first array: ");
    scanf("%d", &intlen1);
    getchar();
    int1 = intArraySetKeyboard(intlen1);
    printf("And now for the second one: ");
    scanf("%d", &intlen2);
    getchar();
    int2 = intArraySetKeyboard(intlen2);

    printf("What about two COMPLEX NUMBER arrays...\n");
    printf("Length of the first array: ");
    scanf("%d", &complexlen1);
    getchar();
    complex1 = complexArraySetKeyboard(complexlen1);
    printf("And the length of the second one?: ");
    scanf("%d", &complexlen2);
    getchar();
    complex2 = complexArraySetKeyboard(complexlen2);

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
            break;
        }

        if (choice == 1) {
            printf("INTEGERS 1: ");
            intArrayPrint(int1);
            printf("\n");
            printf("INTEGERS 2: ");
            intArrayPrint(int2);
            printf("\n");
            printf("COMPLEX NUMBERS 1: ");
            complexArrayPrint(complex1);
            printf("\n");
            printf("COMPLEX NUMBERS 2: ");
            complexArrayPrint(complex2);
            printf("\n");
            if (concatInt != NULL) {
                printf("CONCATINATED INTEGERS: ");
                intArrayPrint(int1);
                intArrayPrint(int2);
                printf("\n");
            }
            if (concatComplex != NULL) {
                printf("CONCATINATED COMPLEX NUMBERS: ");
                complexArrayPrint(complex1);
                complexArrayPrint(complex2);
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
                printf("Enter the length of the array: ");
                scanf("%d", &intlen1);
                getchar();
                int1 = intArraySetKeyboard(intlen1);
            }

            if (choice == 2) {
                printf("Enter the length of the array: ");
                scanf("%d", &intlen2);
                getchar();
                int2 = intArraySetKeyboard(intlen2);
            }

            if (choice == 3) {
                printf("Enter the length of the array: ");
                scanf("%d", &complexlen1);
                getchar();
                complex1 = complexArraySetKeyboard(complexlen1);
            }

            if (choice == 4) {
                printf("Enter the length of the array: ");
                scanf("%d", &complexlen2);
                getchar();
                complex2 = complexArraySetKeyboard(complexlen2);
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
//            getchar();
        }

        if (choice == 4) {
            printf("SELECT TYPE OF AN ARRAY: \n");
            printf("1. Integers\n");
            printf("2. Complex numbers\n");
            scanf("%d", &choice);
            while ((choice < 1) || (choice > 2)) {
                printf("ERROR\nPlease, try again: ");
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
                    printf("That's no good. ERROR.\n");
                    printf("...fine, I'll give you one more chance...: ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 1) {
                    Map(int1, int_square);
                    Map(int2, int_square);
                }
                else {
                    Map(int1, int_substr_one);
                    Map(int2, int_substr_one);
                }
            } else {
                printf("Choose your fighter:\n");
                printf("1. Square complex numbers\n");
                printf("2. Multiply complex numbers by 2\n");
                printf("Your decision?: ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 2)) {
                    printf("That's no good. ERROR.\n");
                    printf("...fine, I'll give you one more chance...: ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 1) {
                    Map(complex1, complex_square);
                    Map(complex2, complex_square);
                }
                else {
                    Map(complex1, complex_mult_2);
                    Map(complex2, complex_mult_2);
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
                printf("That's no good. ERROR.\n");
                printf("...fine, I'll give you one more chance...: ");
                scanf("%d", &choice);
            }
            getchar();

            if (choice == 1) {
                printf("Here is some stuff you can do to integers:\n");
                printf("1. Integer is more than 5\n");
                printf("2. Integer is less than 5\n");
                printf("They're both pretty boring, but still... Your decision?: ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 2)) {
                    printf("That's no good. ERROR.\n");
                    printf("...fine, I'll give you one more chance...: ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 1) {
                    int1 = where(int1, more_than_5);
                    int2 = where(int2, more_than_5);
                }
                else {
                    int1 = where(int1, less_than_5);
                    int2 = where(int2, less_than_5);
                }
            }
            else {
                printf("List of some functions for complex numbers:\n");
                printf("1. Complex number has positive Re\n");
                printf("2. Complex number has negative Re\n");
                printf("Your choice?: ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 2)) {
                    printf("Oh no, something's gone wrong!");
                    printf("Nevermind, you can try one more time...: ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 1) {
                    complex1 = where(complex1, has_positive_re);
                    complex2 = where(complex2, has_positive_re);
                }
                else {
                    complex1 = where(complex1, has_negative_re);
                    complex2 = where(complex2, has_negative_re);
                }
            }
            printf("Done\n");
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
    return 0;
}
