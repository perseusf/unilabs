#ifndef EXTRA_H
#define EXTRA_H

using namespace std;
#include <iostream>
#include "heap.h"
#include "set.h"
#include <cmath>
#include <chrono>

Heap<int> keyboardIntHeap(int size) {
    Heap<int> heap;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        heap.insert(element);
    }
    return heap;
}
Heap<double> keyboardDoubleHeap(int size) {
    Heap<double> heap;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        double element;
        cin >> element;
        heap.insert(element);
    }
    return heap;
}
Heap<int> randomIntHeap(int size) {
    Heap<int> heap;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int element = rand() % 20;
        heap.insert(element);
    }
    return heap;
}
Heap<double> randomDoubleHeap(int size) {
    Heap<double> heap;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        double element = sqrt(rand() % 1000);
        heap.insert(element);
    }
    return heap;
}

Set<int> keyboardIntSet(int size) {
    Set<int> set;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        set.insert(element);
    }
    return set;
}
Set<double> keyboardDoubleSet(int size) {
    Set<double> set;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        double element;
        cin >> element;
        set.insert(element);
    }
    return set;
}
Set<int> randomIntSet(int size) {
    Set<int> set;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int element = rand() % 100;
        set.insert(element);
    }
    return set;
}
Set<double> randomDoubleSet(int size) {
    Set<double> set;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        double element = sqrt(rand() % 1000);
        set.insert(element);
    }
    return set;
}

int enterChoice(int numofvariants) {
    int choice, flag;
    do {
        cin >> choice;
        if (choice <= numofvariants && choice > 0) flag = 0;
        else {
            cout << "Try again." << endl;
            flag = 1;
        }
    } while (flag);
    return choice;
}
int enterSize() {
    int dim, flag;
    do {
        cin >> dim;
        if (dim > 0) flag = 0;
        else {
            cout << "Try again." << endl;
            flag = 1;
        }
    } while (flag);
    return dim;
}
int enterIndex() {
    int index, flag;
    do {
        cin >> index;
        if (index >= 0) flag = 0;
        else {
            cout << "Try again." << endl;
            flag = 1;
        }
    } while (flag);
    return index;
}


void testIntUnionSet(int n) {
    int resulttime;
    Set<int> set1;
    for (int i = 0; i < n; i++) {
        set1.insert(i);
    }
    Set<int> set2;
    for (int i = 0; i < n; i++) {
        set2.insert(n + 2 - i);
    }
    auto start_time = chrono::steady_clock::now();
    Set<int> unionresult = set1 + set2;
    auto end_time = chrono::steady_clock::now();
    resulttime = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    cout << "Union time: " << resulttime << " milliseconds." << endl << endl;
}

void testDoubleUnionSet(int n) {
    int resulttime;
    Set<double> set1;
    for (int i = 0; i < n; i++) {
        set1.insert(i);
    }
    Set<double> set2;
    for (int i = 0; i < n; i++) {
        set2.insert(n + 2 - i);
    }
    auto start_time = chrono::steady_clock::now();
    Set<double> unionresult = set1 + set2;
    auto end_time = chrono::steady_clock::now();
    resulttime = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    cout << "Union time: " << resulttime << " milliseconds." << endl << endl;
}

void testIntComplementSet(int n) {
    int resulttime;
    Set<int> set1;
    for (int i = 0; i < n; i++) {
        set1.insert(i);
    }
    Set<int> set2;
    for (int i = 0; i < n; i++) {
        set2.insert(n + 2 - i);
    }
    auto start_time = chrono::steady_clock::now();
    Set<int> complementresult = set1 - set2;
    auto end_time = chrono::steady_clock::now();
    resulttime = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    cout << "Union time: " << resulttime << " milliseconds." << endl << endl;
}

void testDoubleComplementSet(int n) {
    int resulttime;
    Set<double> set1;
    for (int i = 0; i < n; i++) {
        set1.insert(i);
    }
    Set<double> set2;
    for (int i = 0; i < n; i++) {
        set2.insert(n + 2 - i);
    }
    auto start_time = chrono::steady_clock::now();
    Set<double> somplementresult = set1 - set2;
    auto end_time = chrono::steady_clock::now();
    resulttime = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    cout << "Union time: " << resulttime << " milliseconds." << endl << endl;
}

void testIntIntersectionSet(int n) {
    int resulttime;
    Set<int> set1;
    for (int i = 0; i < n; i++) {
        set1.insert(i);
    }
    Set<int> set2;
    for (int i = 0; i < n; i++) {
        set2.insert(n + 2 - i);
    }
    auto start_time = chrono::steady_clock::now();
    Set<int> unionresult = set1 * set2;
    auto end_time = chrono::steady_clock::now();
    resulttime = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    cout << "Union time: " << resulttime << " milliseconds." << endl << endl;
}

void testDoubleIntersectionSet(int n) {
    int resulttime;
    Set<double> set1;
    for (int i = 0; i < n; i++) {
        set1.insert(i);
    }
    Set<double> set2;
    for (int i = 0; i < n; i++) {
        set2.insert(n + 2 - i);
    }
    auto start_time = chrono::steady_clock::now();
    Set<double> unionresult = set1 * set2;
    auto end_time = chrono::steady_clock::now();
    resulttime = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    cout << "Union time: " << resulttime << " milliseconds." << endl << endl;
}


#endif // EXTRA_H
