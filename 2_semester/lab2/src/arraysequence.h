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
    ArraySequence(const ArraySequence<T> &data);

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
    void Append(const T &data);
    void Prepend(const T &data);
    void InsertAt(const T &data, int index);
    void Set(int index, const T &data);
    Sequence<T> *Concat(Sequence <T> *sequence) const;
    Sequence<T> *Clone();

    //destructor
    ~ArraySequence();
};

#endif // ARRAYSEQUENCE_H
