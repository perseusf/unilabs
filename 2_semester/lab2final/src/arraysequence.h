#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H

#include "sequence.h"
#include "dynamicarray.h"
#include "dynamicarray.cpp"
#include "iostream"

template <class T>
class ArraySequence: public Sequence<T> {
private:
    DynamicArray<T> *array;

public:
    //Constructors
    ArraySequence();
    ArraySequence(T* data, int length);
    ArraySequence(ArraySequence<T> &data);

    //Decomposition
    T& GetFirst();
    T& GetLast();
    T& Get(int index);
    T& operator[] (const int index);
    Sequence<T>* GetSubSequence(int start, int end) const;
    int GetLength() const;
    void DelByIndex(int index);
    void Resize(int length);

    //Operations
    void Append(const T& value);
    void Prepend(const T& value);
    void InsertAt(const T& value, int index);
    void Set(const T& value, int index);
    Sequence<T>* Concat(Sequence <T> *seq) const;

    //Destructor
    ~ArraySequence();
};


#endif // ARRAYSEQUENCE_H

