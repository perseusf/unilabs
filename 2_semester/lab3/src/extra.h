#ifndef EXTRA_H
#define EXTRA_H

#include <iostream>
#include <string>
#include "heap.h"
#include "set.h"
#include "person.h"
#include "complex.h"
#include <cmath>
#include <ctime>
using namespace std;

string to_string(const string &str) {
    return str;
}

void enterInt(int *a) {
    int mode = 0;
    cin >> *a;
    if (!cin) {
        while (getchar() != '\n') {};
        cout << "Something's wrong. Try again.\n\n";
        mode = -1;
    }
    if (mode == 0) while (getchar() != '\n') {};
}

void enterDouble(double *a) {
    int mode = 0;
    cin >> *a;
    if (!cin) {
        while (getchar() != '\n') {};
        cout << "Something's wrong. Try again.\n\n";
        mode = -1;
    }
    if (mode == 0) while (getchar() != '\n') {};
}

void enterComplex(Complex *a) {
    int mode = 0;
    double Re, Im;
    cout << "Re = ";
    cin >> Re;
    if (!cin) {
        while (getchar() != '\n') {};
        cout << "Something's wrong. Try again.\n\n";
        mode = -1;
        return;
    }
    cout << "Im = ";
    cin >> Im;
    if (!cin) {
        while (getchar() != '\n') {};
        cout << "Something's wrong. Try again.\n\n";
        mode = -1;
        return;
    }
    a->Set(Re, Im);
    if (mode == 0) while (getchar() != '\n') {};
}

void enterString(string *a) {
    string str;
    cin  >> str;
    *a = str;
}

void enterStudent(Student *a) {
    int mode = 0;
    int ID;
    string first_name, last_name, group;
    cout << "ID : ";
    cin >> ID;
    if (!cin) {
        while (getchar() != '\n') {};
        cout << "Something's wrong. Try again.\n\n";
        mode = -1;
        return;
    }
    cout << "First name : ";
    cin >> first_name;
    cout << "Last name : ";
    cin >> last_name;
    cout << "Group : ";
    cin >> group;
    a->SetS(ID, first_name, last_name, group);
    if (mode == 0) while (getchar() != '\n') {};
}

void enterTeacher(Teacher *a) {
    int mode = 0;
    int ID;
    string first_name, last_name, subject;
    cout << "ID : ";
    cin >> ID;
    if (!cin) {
        while (getchar() != '\n') {};
        cout << "Something's wrong. Try again.\n\n";
        mode = -1;
        return;
    }
    cout << "First name : ";
    cin >> first_name;
    cout << "Last name : ";
    cin >> last_name;
    cout << "Subject : ";
    cin >> subject;
    a->SetT(ID, first_name, last_name, subject);
    if (mode == 0) while (getchar() != '\n') {};
}

void enterLength(int* length) {
    int error;

    do {
        enterInt(length);

        if (*length > 0) {
            cout << "Length = " << *length << endl << endl;
            error = 0;
        }
        else {
            cout << "Something's wrong. Try again." << endl << endl;
            error = 1;
        }
    } while (error);
}

void enterIndex(int* index) {
    int error;

    do {
        enterInt(index);

        if (*index >= 0) {
            cout << "Index = " << *index << endl << endl;
            error = 0;
        }
        else {
            cout << "Something's wrong. Try again." << endl << endl;
            error = 1;
        }
    } while (error);
}

void generateHeap(Heap<int>* heap, int* length) {
    srand(time(NULL));
    for (int i = 0; i < *length; ++i) {
        int a = rand() % 11;
        heap->insert(a);
    }
}

void generateHeap(Heap<double>* heap, int* length) {
    srand(time(NULL));
    for (int i = 0; i < *length; ++i) {
        int b = (rand() % 101);
        double a = (rand()%3-1)*sqrt(b);
        heap->insert(a);
    }
}

void generateHeap(Heap<Complex>* heap, int* length) {
    srand(time(NULL));
    for (int i = 0; i < *length; ++i) {
        Complex a(rand()%20-10, rand()%20-10);
        heap->insert(a);
    }
}

void generateHeap(Heap<string>* heap, int* length) {
    srand(time(NULL));
    for (int i = 0; i < *length; ++i) {
        int str_len = rand() % 10;
        string a = "";
        for (int j = 0; j < str_len; ++j) {
            char c('a' + rand() % ('z' - 'a'));
            a += c;
        }
        heap->insert(a);
    }
}

void generateHeap(Heap<Student>* heap, int* length) {
    srand(time(NULL));
    string first_names[] = {"Ivan", "Petr", "Aleksandr", "Aleksey", "Sergey"};
    string last_names[] = {"Ivanov", "Petrov", "Aleksandrov", "Alekseev", "Sergeev"};
    string groups[] = {"B20-201", "B20-202", "B20-203", "B20-204", "B20-205", "B20-211", "B20-215"};
    for (int i = 0; i < *length; ++i) {
        int ID = rand() % 9000 + 1000;
        string first_name = first_names[rand() % (sizeof(first_names) / sizeof(first_names[0]))];
        string last_name = last_names[rand() % (sizeof(last_names) / sizeof(last_names[0]))];
        string group = groups[rand() % (sizeof(groups) / sizeof(groups[0]))];
        Student a(ID, first_name, last_name, group);
        heap->insert(a);
    }
}

void generateHeap(Heap<Teacher>* heap, int* length) {
    srand(time(NULL));
    string first_names[] = {"Ivan", "Petr", "Aleksandr", "Aleksey", "Sergey"};
    string last_names[] = {"Ivanov", "Petrov", "Aleksandrov", "Alekseev", "Sergeev"};
    string subjects[] = {"Mathematical analysis", "Linear algebra", "General physics", "Discrete mathematics", "Programming"};
    for (int i = 0; i < *length; ++i) {
        int ID = rand() % 9000 + 1000;
        string first_name = first_names[rand() % (sizeof(first_names) / sizeof(first_names[0]))];
        string last_name = last_names[rand() % (sizeof(last_names) / sizeof(last_names[0]))];
        string subject = subjects[rand() % (sizeof(subjects) / sizeof(subjects[0]))];
        Teacher a(ID, first_name, last_name, subject);
        heap->insert(a);
    }
}

void generateSet(Set<int>* set, int* length) {
    srand(time(NULL));
    set->clear();
    for (int i = 0; i < *length; ++i) {
        int a = rand() % (2 * (*length + 1));
        if (i) {
            if (set->checkEntry(a)) {
                --i;
                continue;
            }
        }
        set->insert(a);
    }
}

void generateSetRepeat(Set<int>* set, int* length) {
    srand(time(NULL));
    set->clear();
    for (int i = 0; i < *length; ++i) {
        int max = 10e8;
        int a = rand() % max;
        set->insertRepeat(a);
    }
}

void generateSet(Set<double>* set, int* length) {
    srand(time(NULL));
    for (int i = 0; i < *length; ++i) {
        int b = (rand() % (4 * *length));
        double a = (rand()%3-1)*sqrt(b);
        if (i) {
            if (set->checkEntry(a)) {
                --i;
                continue;
            }
        }
        set->insert(a);
    }
}

void generateSetRepeat(Set<double>* set, int* length) {
    srand(time(NULL));
    for (int i = 0; i < *length; ++i) {
        int max = 10e5;
        int del = rand() % max;
        while (del == 0) del = rand() % 7;
        double a = (rand() % max) * 1.0 / del;
        set->insertRepeat(a);
    }
}

void generateSet(Set<Complex>* set, int* length) {
    srand(time(NULL));
    for (int i = 0; i < *length; ++i) {
        Complex a(rand()%(2 * (*length + 1 )) - *length/2, rand()%(2 * (*length + 1 )) - *length/2);
        if (i) {
            if (set->checkEntry(a)) {
                --i;
                continue;
            }
        }
        set->insert(a);
    }
}

void generateSetRepeat(Set<Complex>* set, int* length) {
    srand(time(NULL));
    for (int i = 0; i < *length; ++i) {
        int max = 10e8;
        Complex a(rand() % max, rand() % max);
        set->insertRepeat(a);
    }
}

void generateSet(Set<string>* set, int* length) {
    srand(time(NULL));
    for (int i = 0; i < *length; ++i) {
        int str_len = rand() % 10;
        string a = "";
        for (int j = 0; j < str_len; ++j) {
            char c('a' + rand() % ('z' - 'a'));
            a += c;
        }
        if (i) {
            if (set->checkEntry(a)) {
                --i;
                continue;
            }
        }
        set->insert(a);
    }
}

void generateSetRepeat(Set<string>* set, int* length) {
    srand(time(NULL));
    for (int i = 0; i < *length; ++i) {
        int str_len = rand() % 10;
        string a = "";
        for (int j = 0; j < str_len; ++j) {
            char c('a' + rand() % ('z' - 'a'));
            a += c;
        }
        set->insertRepeat(a);
    }
}

void generateSet(Set<Student>* set, int* length) {
    srand(time(NULL));
    string first_names[] = {"Ivan", "Petr", "Aleksandr", "Aleksey", "Sergey"};
    string last_names[] = {"Ivanov", "Petrov", "Aleksandrov", "Alekseev", "Sergeev"};
    string groups[] = {"B20-201", "B20-202", "B20-203", "B20-204", "B20-205", "B20-211", "B20-215"};
    for (int i = 0; i < *length; ++i) {
        int ID = rand() % (2 * (*length + 1));
        string first_name = first_names[rand() % (sizeof(first_names) / sizeof(first_names[0]))];
        string last_name = last_names[rand() % (sizeof(last_names) / sizeof(last_names[0]))];
        string group = groups[rand() % (sizeof(groups) / sizeof(groups[0]))];
        Student a(ID, first_name, last_name, group);
        if (i) {
            if (set->checkEntry(a)) {
                --i;
                continue;
            }
        }
        set->insert(a);
    }
}

void generateSetRepeat(Set<Student>* set, int* length) {
    srand(time(NULL));
    string first_names[] = {"Ivan", "Petr", "Aleksandr", "Aleksey", "Sergey"};
    string last_names[] = {"Ivanov", "Petrov", "Aleksandrov", "Alekseev", "Sergeev"};
    string groups[] = {"B20-201", "B20-202", "B20-203", "B20-204", "B20-205", "B20-211", "B20-215"};
    for (int i = 0; i < *length; ++i) {
        int ID = rand() % (2 * (*length + 1));
        string first_name = first_names[rand() % (sizeof(first_names) / sizeof(first_names[0]))];
        string last_name = last_names[rand() % (sizeof(last_names) / sizeof(last_names[0]))];
        string group = groups[rand() % (sizeof(groups) / sizeof(groups[0]))];
        Student a(ID, first_name, last_name, group);
        set->insertRepeat(a);
    }
}

void generateSet(Set<Teacher>* set, int* length) {
    srand(time(NULL));
    string first_names[] = {"Ivan", "Petr", "Aleksandr", "Aleksey", "Sergey"};
    string last_names[] = {"Ivanov", "Petrov", "Aleksandrov", "Alekseev", "Sergeev"};
    string subjects[] = {"Mathematical analysis", "Linear algebra", "General physics", "Discrete mathematics", "Programming"};
    for (int i = 0; i < *length; ++i) {
        int ID = rand() % (2 * (*length + 1));
        string first_name = first_names[rand() % (sizeof(first_names) / sizeof(first_names[0]))];
        string last_name = last_names[rand() % (sizeof(last_names) / sizeof(last_names[0]))];
        string subject = subjects[rand() % (sizeof(subjects) / sizeof(subjects[0]))];
        Teacher a(ID, first_name, last_name, subject);
        if (i) {
            if (set->checkEntry(a)) {
                --i;
                continue;
            }
        }
        set->insert(a);
    }
}

void generateSetRepeat(Set<Teacher>* set, int* length) {
    srand(time(NULL));
    string first_names[] = {"Ivan", "Petr", "Aleksandr", "Aleksey", "Sergey"};
    string last_names[] = {"Ivanov", "Petrov", "Aleksandrov", "Alekseev", "Sergeev"};
    string subjects[] = {"Mathematical analysis", "Linear algebra", "General physics", "Discrete mathematics", "Programming"};
    for (int i = 0; i < *length; ++i) {
        int ID = rand() % (2 * (*length + 1));
        string first_name = first_names[rand() % (sizeof(first_names) / sizeof(first_names[0]))];
        string last_name = last_names[rand() % (sizeof(last_names) / sizeof(last_names[0]))];
        string subject = subjects[rand() % (sizeof(subjects) / sizeof(subjects[0]))];
        Teacher a(ID, first_name, last_name, subject);
        set->insertRepeat(a);
    }
}

void fillSet(Set<int>* set, int* length) {
    srand(time(NULL));
    set->clear();
    for (int i = 0; i < *length; ++i) {
        int a;
        enterInt(&a);
        set->insert(a);
    }
}

void fillSet(Set<double>* set, int* length) {
    srand(time(NULL));
    set->clear();
    for (int i = 0; i < *length; ++i) {
        double a;
        enterDouble(&a);
        set->insert(a);
    }
}

void fillSet(Set<Complex>* set, int* length) {
    srand(time(NULL));
    set->clear();
    for (int i = 0; i < *length; ++i) {
        Complex a;
        enterComplex(&a);
        set->insert(a);
    }
}

void fillSet(Set<string>* set, int* length) {
    srand(time(NULL));
    set->clear();
    for (int i = 0; i < *length; ++i) {
        string a;
        enterString(&a);
        set->insert(a);
    }
}

void fillSet(Set<Student>* set, int* length) {
    srand(time(NULL));
    set->clear();
    for (int i = 0; i < *length; ++i) {
        Student a;
        enterStudent(&a);
        set->insert(a);
    }
}

void fillSet(Set<Teacher>* set, int* length) {
    srand(time(NULL));
    set->clear();
    for (int i = 0; i < *length; ++i) {
        Teacher a;
        enterTeacher(&a);
        set->insert(a);
    }
}


#endif // EXTRA_H
