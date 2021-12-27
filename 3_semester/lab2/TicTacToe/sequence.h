#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "linkedlist.h"
#include "dynamicarray.h"


template<typename T>
class Sequence {
public:
    virtual T& GetFirst() = 0;
    virtual T& GetLast() = 0;
    virtual T& Get(int index) = 0;
    virtual T& operator[] (const int index) = 0;
    virtual Sequence<T> *GetSubSequence(int start_index, int end_index) const = 0;
    virtual int GetLength() const = 0;
    virtual void DelByIndex(int index) = 0;

    virtual void Append(const T& item) = 0;
    virtual void Prepend(const T& item) = 0;
    virtual void InsertAt(const T& item, int index) = 0;
    virtual void Set(int index, const T& item) = 0;
    virtual Sequence<T> *Concat(Sequence<T> *Sequence) const = 0;
    virtual Sequence<T> *Clone() = 0;
    virtual void Swap(T& first, T&second) = 0;
};

#endif // SEQUENCE_H
