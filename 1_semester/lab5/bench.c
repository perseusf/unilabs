#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Item {
    char data;
    struct Item* next;
} Item;

typedef struct List {
    Item* head;
    Item* tail;
} List;

List *list_new() {
    return (List *) calloc(1, sizeof(List));
}

void list_delete(List *list) {
    Item *ptr = list->head, *ptr_prev;
    while (ptr) {
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev);
    }
    free(list);
}

void list_print(const List *list) {
    Item *ptr = list->head;
    printf("\"");
    while (ptr) {
        printf("%c", ptr->data);
        ptr = ptr->next;
    }
    printf("\"\n");
}

int list_push_back(List *list, char data) {
    Item *ptr = (Item*) malloc(sizeof(Item));
    if (!ptr) {
        return -1;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (!list->head) {
        list->head = ptr;
        list->tail = ptr;
    } else {
        list->tail->next = ptr;
        list->tail = ptr;
    }
    return 0;
}

void list_clean(List *list) {
    Item *ptr = list->head, *ptr1, *ptr2, *freeptr;
    if (ptr && ((ptr->data == ' ') || (ptr->data == '\t'))) {
        while (ptr && ((ptr->data == ' ') || (ptr->data == '\t'))) {
            freeptr = ptr;
            ptr = ptr->next;
            free(freeptr);
        }
        list->head = ptr;
    }
    while (ptr) {
        while (ptr && (ptr->data != ' ') && (ptr->data != '\t')) {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        if (ptr) ptr = ptr->next;
        while (ptr && ((ptr->data == ' ') || (ptr->data == '\t'))) {
            freeptr = ptr;
            ptr = ptr->next;
            free(freeptr);
        }
        ptr2 = ptr;
        if (ptr) {
            ptr1->next->next = ptr2;
            ptr = ptr->next;
            ptr1 = ptr2;
        } else {
            free(ptr1->next);
            ptr1->next = NULL;
            list->tail = ptr1;
        }
    }
}

void del_word(List *list, Item *start, Item *pointer) {
    if (start == list->head && pointer == list->tail) { //если ввели одно слово, которое не палиндром
        Item *ptr = list->head;
        while (ptr) {
            Item *temp = ptr;
            ptr = ptr->next;
            temp->data = ' ';
        }
    } else {
        while (start != pointer) {
            if (start == list->head) { //если первая буква в списке
                if (start == NULL) { //если лист пустой
                    printf("The list is already empty!");
                } else {
                    Item *temp = start;
                    list->head = list->head->next;
                    start = start->next;
                    free(temp);
                }
            } else {
                Item *ptr_prev = list->head;
                while (ptr_prev->next != start) { //элемент до первой буквы слова (start)
                    ptr_prev = ptr_prev->next;
                }
                Item *temp = start;
                ptr_prev->next = start->next;
                start = start->next;
                free(temp);
            }
        }
        if (start->next == NULL) { //удаление последней буквы непалиндрома, если он последний в строчке
            start->data = ' ';
        }
    }
}

void reverse_words(List *list) {
    Item *pointer = list->head; //пробел после слова или последняя буква (если непалиндром последний в строке)
    Item *start = list->head; //первая буква слова
    Item *pointer1, *pointer2;
    int wordlen = 1, k;
    while (pointer) {
        if (pointer->data == ' ' || (!pointer->next)) { //идём в конец слова
            if (pointer->data == ' ') { //не конец списка
                pointer1 = start;
                wordlen--;
            } else { //конец списка
                pointer1 = start;
            }
            k = wordlen / 2;
            for (int j = 0; j < k; j++){
                pointer2 = start;
                for (int p = 0; p < wordlen - j - 1; p++) {
                    if (pointer2 && pointer2->next)
                        pointer2 = pointer2->next;
                }
                if (pointer1 && (pointer1->data == pointer2->data)) {
                    pointer1 = pointer1->next;
                } else {
                    del_word(list, start, pointer);
                    break;
                }
            }
            wordlen = 0;
            if (start != NULL) start = pointer->next;
        }
        wordlen++;
        if (pointer == list->tail) break;
        if (pointer != NULL) pointer = pointer->next;
    }
}

List * list_scan() {
    char c = getchar();
    if (c == EOF) {
        return 0;
    }
    List *list = list_new();
    while (c != '\n') {
        list_push_back(list, c);
        c = getchar();
    }
    return list;
}

List* list_generate(int len) {
    List* list = list_new();
    for (int j = 0; j < len; j++) {
        int group1 = rand() % 3;
        switch (group1) {
            case 0: //слово
                list_push_back(list, 'a' + rand() % 25);
                break;
            case 1: //слово
                list_push_back(list, 'A' + rand() % 25);
                break;
            case 2: //пробел
                list_push_back(list, ' ');
                break;
        }
    }
    return list;
}

int main() {
    int numstrings, numsymbols, m;
    printf("Number of strings: ");
    scanf("%d", &numstrings);
    printf("Number of symbols in string: ");
    scanf("%d", &numsymbols);
    printf("Output intermediate values yes(1)/no(0): ");
    scanf("%d", &m);
    double time_avr;
    List * list_str;
    for (int i = 0; i < numstrings; i++) {
        list_str = list_generate(numsymbols);
        if (!list_str) {
            return 0;
        }
        if (m == 1) {
            printf("\nList: ");
            list_print(list_str);
        }
        clock_t t = clock();
        list_clean(list_str);
        reverse_words(list_str);
        list_clean(list_str);
        t = clock() - t;
        if (m == 1) {
            printf("Processed: ");
            list_print(list_str);
        }
        double time = (double) t / CLOCKS_PER_SEC;
        if (m == 1) {
            printf("Time: %.8lf seconds\n", time);
        }
        time_avr += time;
        list_delete(list_str);
    }
    time_avr /= numstrings;
    printf("The number of symbols: %d\nThe average time: %.8lf\n", numsymbols, time_avr);
    return 0;
}