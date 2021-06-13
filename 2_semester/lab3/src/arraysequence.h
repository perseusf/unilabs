#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H

#include "sequence.h"
#include "dynamicarray.h"
#include "dynamicarray.cpp"
#include "iostream"

template <typename T>
class ArraySequence: public Sequence<T> {
private:
    DynamicArray<T> *array_;

public:
    //constructors
    ArraySequence();
    ArraySequence(T* data, int length);
    ArraySequence(ArraySequence<T> &data);

    //decomposition
    T& GetFirst();
    T& GetLast();
    T& Get(int index);
    T& operator[] (int index);
    Sequence<T>* GetSubSequence(int start, int end) const;
    [[nodiscard]] int GetLength() const;
    void DelByIndex(int index);
    void Resize(int length);

    //operations
    void Append(T &data);
    void Prepend(T &data);
    void InsertAt(T &data, int index);
    void Set(int index, T &data);
    Sequence<T> *Concat(Sequence <T> *sequence) const;
    Sequence<T> *Clone();

    //destructor
    ~ArraySequence();
};

#endif // ARRAYSEQUENCE_H
