#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mystring.h"

char* trimleft(char* str);
char* moveright(char* str);
char* finalstr(char** sentences, int numOfSentences);
char* get_str();
void selectionsort(char** sentences, int numOfSentences);

int main() {
    char delims[4] = ".,;";
	char* s = NULL;
    do {
	    char* piece = NULL;
	    char** sentences = NULL;
	    printf("%s\n", "Enter a string:");
	    clock_t time;
	    time = clock();
	    s = get_str();
	    if (s) {
		    char* buffer = calloc(strlen(s) + 1, sizeof(char));
		    buffer = strcpy(buffer, s);
		    int numOfSentences = 0;
		    piece = strtok(buffer, delims);
		    while (piece != NULL) {
		        piece = moveright(piece);
		        piece = trimleft(piece);
		        if (*piece != '\0') { //если вдруг предложение состоит из пробелов только
		            numOfSentences++;
		            sentences = realloc(sentences, numOfSentences*sizeof(*sentences));
		            sentences[numOfSentences-1] = calloc(strlen(piece) + 1, sizeof(char));
		            sentences[numOfSentences-1] = strcpy(sentences[numOfSentences-1], piece);
		        }
		        piece = strtok(NULL, delims);
		    }
		    selectionsort(sentences, numOfSentences);
		    char* finalstring = finalstr(sentences, numOfSentences);
		    printf("%s\n", "Sentences are sorted in the alphabetical order");
		    printf("%s\n", finalstring);
		    time = clock() - time;
		    printf("Time = %f  seconds\n", ((double)time)/CLOCKS_PER_SEC);
		    //free everything
		    free(finalstring);
		    free(piece);
		    free(s);
		    free(buffer);
		    for (int i = 0; i < numOfSentences; i++) {
		        free(sentences[i]);
		    }
		    free(sentences);
	    }
    } while (s);
	free(s);
    return 0;
}
//trim spaces on the left side
char* trimleft(char* str) {
    str += strspn(str, " \t");
    return str;
}
//trim spaces on the right side
char* moveright(char* str) {
    int len = strlen(str);
    str += len - 1;
    int counter = 0;
    while (*str == ' ' || *str == '\t'){
        str--;
        counter++;
    }
    str = str - len + counter + 1;
    if (counter == 0)
        return str;
    for (int i = len - counter - 1; i >= 0; i--) {
        str[i+counter] = str[i];
        str[i] = ' ';
    }
    return str;
}
//selection sort (for pointers)
void selectionsort(char** sentences, int numOfSentences) {
    int minid = 0;
    for (int i = 0; i < numOfSentences - 1; i++){
        minid = i;
        for (int j = i + 1; j < numOfSentences; j++) {
            if (*sentences[j] < *sentences[minid]) {
                minid = j;
            }
        }
        char* temp = sentences[minid];
        sentences[minid] = sentences[i];
        sentences[i] = temp;
    }
}
//convert an array of strings into a string
char* finalstr(char** sentences, int numOfSentences) {
    int finalsize = 0;
    for (int i = 0; i < numOfSentences; i++) {
        finalsize += strlen(sentences[i]);
    }
    char* final = calloc((finalsize + numOfSentences * 2 + 1), sizeof(char));
    for (int i = 0; i < numOfSentences; i++) {
        final = strcat(final, sentences[i]);
        final = strcat(final, ". ");
    }
    return final;
}
//input
char *get_str() {
    char buf[128] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = scanf("%127[^\n]", buf);
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
