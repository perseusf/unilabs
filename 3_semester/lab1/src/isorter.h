#ifndef LAB1_ISORTER_H
#define LAB1_ISORTER_H

#include "sequence.h"

template <class T>
class ISorter {
public:
    virtual Sequence<T>* Sort(Sequence<T> *seq, int (*cmp)(T, T));
};

template <typename T>
class BubbleSort : public ISorter<T> {
public:
    Sequence<T>* Sort(Sequence<T> *seq, int (*cmp)(T, T));
};

template <typename T>
class SelectionSort : public ISorter<T> {
public:
    Sequence<T>* Sort(Sequence<T> *seq, int (*cmp)(T, T));
};

template <typename T>
class InsertionSort : public ISorter<T> {
public:
    Sequence<T>* Sort(Sequence<T> *seq, int (*cmp)(T, T));
};

template <typename T>
class MergeSort : public ISorter<T> {
private:
    Sequence<T>* merge(Sequence<T> *seq, int left, int middle, int right, int (*cmp)(T, T));
    Sequence<T>* mergesort(Sequence<T> *seq, int left, int right, int (*cmp)(T, T));
public:
    Sequence<T>* Sort(Sequence<T> *seq, int (*cmp)(T, T));
};

template <typename T>
class QuickSort : public ISorter<T> {
private:
    int split (Sequence<T> *seq, int start, int end, int (*cmp)(T, T));
    void quicksort(Sequence<T> *seq, int start, int end, int (*cmp)(T, T));
public:
    Sequence<T>* Sort(Sequence<T> *seq, int (*cmp)(T, T));
};

template <class T>
class ShellSort : public ISorter<T> {
public:
    Sequence<T>* Sort(Sequence<T> *seq, int (*cmp)(T, T));
};


#endif //LAB1_ISORTER_H
