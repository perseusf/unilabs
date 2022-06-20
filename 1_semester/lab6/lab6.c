//Сортировать столбцы матрицы, согласно значению элементов данных столбцов, расположенных в первой строке матрицы
//выбор

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int count_lines(FILE* file);
int** matrix_keyboard(int *numstringsa, int *numcolumnsa);
int** matrix_file(int *numstringsa, int *numcolumnsa, char* name);
int** matrix_rand(int *numstringsa, int *numcolumnsa);
void selectionsort(int **data, int numstringsa, int numcolumnsa);
void bubblesort(int **data, int numstringsa, int numcolumnsa);
void matrix_print(int **data, int numstringsa, int numcolumnsa);
void matrix_write(int** arr, int numstr, int numcol, char* name);
int** matrix_copy(int** source, int numstringsa, int numcolumnsa);
void timemeausurement(int** arr_b, int** arr_s, int numstr, int numcol);
char* get_str();

int main() {
    int item;
    int status = 0;
    int **arr = NULL;
    int **arr_s = NULL;
    int **arr_b = NULL;
    int numcol = 0;
    int numstr = 0;
    do{
        srand(time(NULL));
        printf("\n1. Input from keyboard.\n");
        printf("2. Input from text file.\n");
        printf("3. Input randomly.\n");
        printf("4. Time measurement.\n");
        printf("5. Sort.\n");
        printf("6. Save into the file.\n");
        printf("7. Exit.\n");
        scanf("%d", &item);
        FILE *outputfile;
        switch (item)
        {
            case 1: {
                if (status == 1) {
                    for (int i = 0; i < numstr; i++){
                        free(arr[i]);
                    }
                    free(arr);
                    for (int i = 0; i < numstr; i++){
                        free(arr_s[i]);
                    }
                    free(arr_s);
                    for (int i = 0; i < numstr; i++){
                        free(arr_b[i]);
                    }
                    free(arr_b);
                }
                arr = matrix_keyboard(&numstr, &numcol);
                arr_s = matrix_copy(arr, numstr, numcol);
                arr_b = matrix_copy(arr, numstr, numcol);
                if (!arr)
                    break;
                status = 1;
                break;
            }
            case 2: {
                if (status == 1) {
                    for (int i = 0; i < numstr; i++){
                        free(arr[i]);
                    }
                    free(arr);
                    for (int i = 0; i < numstr; i++){
                        free(arr_s[i]);
                    }
                    free(arr_s);
                    for (int i = 0; i < numstr; i++){
                        free(arr_b[i]);
                    }
                    free(arr_b);
                }
                printf("Please, enter the name of the file:\n");
                scanf("%*c");
                char* name1 = get_str();
                arr = matrix_file(&numstr, &numcol, name1);
                arr_s = matrix_copy(arr, numstr, numcol);
                arr_b = matrix_copy(arr, numstr, numcol);
                if (!arr)
                    break;
                status = 1;
                free(name1);
                break;
            }
            case 3: {
                if (status == 1) {
                    for (int i = 0; i < numstr; i++){
                        free(arr[i]);
                    }
                    free(arr);
                    for (int i = 0; i < numstr; i++){
                        free(arr_s[i]);
                    }
                    free(arr_s);
                    for (int i = 0; i < numstr; i++){
                        free(arr_b[i]);
                    }
                    free(arr_b);
                }
                arr = matrix_rand(&numstr, &numcol);
                arr_s = matrix_copy(arr, numstr, numcol);
                arr_b = matrix_copy(arr, numstr, numcol);
                if (!arr)
                    break;
                status = 1;
                break;
            }

            case 4:
                printf("Please, enter the name of the output file:\n");
                scanf("%*c");
                char* name = get_str();
                printf("Enter the number of strings:\n");
                scanf("%d", &numstr);
                printf("Enter MAX number of columns:\n");
                int numcolmax;
                scanf("%d", &numcolmax);
                printf("Enter the step:\n");
                int step;
                scanf("%d", &step);
                outputfile = fopen(name, "a+");
                printf("Selection sort:      Bubble sort:\n");
                fprintf(outputfile, "Selection sort:      Bubble sort:\n");
                for (int numcol = 1; numcol <= numcolmax; numcol += step) {
                    clock_t timeselection = 0, timebubble = 0;
                    double tselection = 0, tbubble = 0;
                    for (int t = 0; t < 15; t++) {
                        arr_s = calloc(numstr, sizeof(int*));
                        arr_b = calloc(numstr, sizeof(int*));
                        for (int i = 0; i < numstr; i++) {
                            arr_s[i] = calloc(numcol, sizeof(int));
                            arr_b[i] = calloc(numcol, sizeof(int));
                            for (int j = 0; j < numcol; j++) {
                                arr_s[i][j] = rand() % 100;
                                arr_b[i][j] = rand() % 100;
                            }
                        }
                        timeselection = clock();
                        selectionsort(arr_s, numstr, numcol);
                        timeselection = clock() - timeselection;
                        timebubble = clock();
                        bubblesort(arr_b, numstr, numcol);
                        timebubble = clock() - timebubble;
                        //free matrices
                        for (int i = 0; i < numstr; i++) {
                            free(arr_s[i]);
                        }
                        free(arr_s);
                        for (int i = 0; i < numstr; i++) {
                            free(arr_b[i]);
                        }
                        free(arr_b);
                        tselection += timeselection;
                        tbubble += timebubble;
                    }
                    tselection = (double) (timeselection / 15) / CLOCKS_PER_SEC;
                    printf("%.8lf   ", tselection);
                    fprintf(outputfile, "%.8lf   ", tselection);
                    tbubble = (double) (timebubble / 15) / CLOCKS_PER_SEC;
                    printf("  %.8lf\n", tbubble);
                    fprintf(outputfile, "%.8lf\n", tbubble);
                }
                free(name);
                fclose(outputfile);
                break;
            case 5:
                printf("\nInput data:\n");
                matrix_print(arr, numstr, numcol);
                selectionsort(arr, numstr, numcol);
                printf("\nOutput data:\n");
                matrix_print(arr, numstr, numcol);
                timemeausurement(arr_b, arr_s, numstr, numcol);
                break;
            case 6:
                printf("Please, enter the name of the file:\n");
                scanf("%*c");
                char* namewrite = get_str();
                matrix_write(arr, numstr, numcol, namewrite);
                free(namewrite);
                break;
            case 7:
				if (status == 1) {
                	for (int i = 0; i < numstr; i++){
                	    free(arr[i]);
                	}
                	free(arr);
                	for (int i = 0; i < numstr; i++){
                	    free(arr_s[i]);
                	}
                	free(arr_s);
                	for (int i = 0; i < numstr; i++){
                	    free(arr_b[i]);
                	}
                	free(arr_b);
				}
                break;
            default:
                printf("RELOAD.\n");
                break;
        }
    } while (item != 7);
    return 0;
}
int count_lines(FILE* file) {
    int counter = 0;
    if(!file) {
        printf("file can't be opened");
        return 0;
    }
    while(!feof(file)) {
        fscanf(file, "%*[^\n]%*c");
        counter++;
    }
    rewind(file);
    return counter;
}
int** matrix_keyboard(int *numstringsa, int *numcolumnsa) {
    int numcolumns, numstrings;
    printf("Enter the number of strings:\n");
    scanf("%d", &numstrings);
    int **matrix = calloc(numstrings, sizeof(int *));
    printf("Enter the number of columns:\n");
    scanf("%d", &numcolumns);
    if ((numstrings <= 0) || (numcolumns <= 0)){
        printf("\nThe number of strings or columns isn`t valid! Please, try again!\n");
        return NULL;
    }
    printf("Enter %d integers\n", numstrings * numcolumns);
    for (int i = 0; i < numstrings; i++) {
        matrix[i] = calloc(numcolumns, sizeof(int));
        for (int k = 0; k < numcolumns; k++) {
            printf("A[%d][%d]=", i, k);
            scanf("%d", &matrix[i][k]);
        }
    }
    printf("\nReceived data from keyboard!\n");
    *numstringsa = numstrings;
    *numcolumnsa = numcolumns;
    return matrix;
}
int** matrix_file(int *numstringsa, int *numcolumnsa, char* name) {
    int numcolumns, numstrings;
    int numelements;
    FILE* inputfile = fopen(name, "r");
    if (!inputfile) {
        printf("ERROR. NO FILE FOUND.\n");
        return NULL;
    }
    numelements = count_lines(inputfile);
    printf("Possible variants are\n");
    for (int i = 1; i <= numelements; ++i)
        if (numelements%i == 0)
            printf("%d x %d\n", i, numelements/i);
    printf("Enter the number of strings:\n");
    scanf("%d", &numstrings);
    int **matrix = (int**)calloc(numstrings, sizeof(int *));
    printf("Enter the number of columns:\n");
    scanf("%d", &numcolumns);

    if ((numstrings <= 0) || (numcolumns <= 0)){
        printf("\nThe number of strings or columns isn`t valid! Please, try again!\n");
        return NULL;
    }

    if(!feof(inputfile)) {
        for (int i = 0; i < numstrings; i++) {
            matrix[i] = (int*)calloc(numcolumns, sizeof(int));
            for (int k = 0; k < numcolumns; k++) {
                fscanf(inputfile, "%d\n", &matrix[i][k]);
            }
        }
    }
    fclose(inputfile);
    printf("Received data from file!\n");
    *numstringsa = numstrings;
    *numcolumnsa = numcolumns;
    return matrix;
}
int** matrix_rand(int *numstringsa, int *numcolumnsa){
    int numcolumns, numstrings;
    printf("Enter the number of strings:\n");
    scanf("%d", &numstrings);
    printf("Enter the number of columns:\n");
    scanf("%d", &numcolumns);
    if ((numstrings <= 0) || (numcolumns <= 0)){
        printf("\nThe number of strings or columns isn`t valid! Please, try again!\n");
        return NULL;
    }
    int** matrix = (int**)malloc(numstrings*sizeof(int*));
    for (int i = 0; i < numstrings; i++) {
        matrix[i] = (int*)malloc(numcolumns*sizeof(int));
        for (int j = 0; j < numcolumns; j++) {
            int r = rand() % 100;
            matrix[i][j] = r;
        }
    }
    *numstringsa = numstrings;
    *numcolumnsa = numcolumns;
    return matrix;
}
void selectionsort(int **data, int numstringsa, int numcolumnsa){
    int minid;
    for (int i = 0; i < numcolumnsa - 1; i++){
        minid = i;
        for (int j = i + 1; j < numcolumnsa; j++) {
            if (data[0][j] < data[0][minid]) {
                minid = j;
            }
        }
        for (int k = 0; k < numstringsa; k++){
            int temp = data[k][minid];
            data[k][minid] = data[k][i];
            data[k][i] = temp;
        }
        }
    }
void bubblesort(int **data, int numstringsa, int numcolumnsa){
    int i, j, k, temp;
    for (i = 0; i < numcolumnsa - 1; i++) {
        for (j = 0; j < numcolumnsa - i - 1; j++) {
            if (data[0][j] > data[0][j + 1]) {
                for (k = 0; k < numstringsa; k++) {
                    temp = data[k][j];
                    data[k][j] = data[k][j + 1];
                    data[k][j + 1] = temp;
                }
            }
        }
    }
}
void matrix_print(int **matrix, int numstringsa, int numcolumnsa){
    for (int i = 0; i < numstringsa; i++) {
        for (int k = 0; k < numcolumnsa; k++) {
            printf("%5d", matrix[i][k]);
        }
        printf("\n");
    }
    printf("\n");
}
void matrix_write(int** arr, int numstr, int numcol, char* name){
    FILE *outputfile;
    outputfile = fopen(name, "a+");
    if(!feof(outputfile)) {
        fprintf(outputfile, "\n");
        for (int i = 0; i < numstr; i++) {
            for (int k = 0; k < numcol; k++) {
                fprintf(outputfile, "%5d", arr[i][k]);
            }
            fprintf(outputfile, "\n");
        }
    }
    fclose(outputfile);
    printf("Data has been written into the file!\n");
}
int** matrix_copy(int** source, int numstringsa, int numcolumnsa) {
    int** dest = (int**)calloc(numstringsa, sizeof(int*));
    for ( int i = 0; i < numstringsa; ++i ){
        dest[i] = (int*)calloc(numcolumnsa, sizeof(int));
        memcpy(dest[i], source[i], numcolumnsa);
    }
    return dest;
}
void timemeausurement(int** arr_b, int** arr_s, int numstr, int numcol){
    clock_t t = clock();
    bubblesort(arr_b, numstr, numcol);
    t = clock() - t;
    double time = (double)t / (CLOCKS_PER_SEC);
    printf("Bubble sort time: %.10lf seconds\n", time);
    t = clock();
    selectionsort(arr_s, numstr, numcol);
    t = clock() - t;
    time = (double)t / (CLOCKS_PER_SEC);
    printf("Selection sort time: %.10lf seconds\n", time);
}
char *get_str() {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else {
            scanf("%*c");
        }
    } while (n > 0);
    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }
    return res;
}
