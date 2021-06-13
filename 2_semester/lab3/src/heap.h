#ifndef HEAP_H
#define HEAP_H

#include "arraysequence.h"
#include "arraysequence.cpp"
#include <iostream>

template<class T>
class Heap
{
    Sequence<T> *heapdata_;

    void FloatTop(int index);
    void DrownDown(int index);

public:
    //constructors
    Heap();
    Heap(const Sequence<T> &sequence);
    Heap(Heap<T> &heap);

    //decomposition
    int GetLength() const;
    T &GetMinimum();
    T &GetMaximum();
    T &GetElemByIndex(int index);
    void SetElemByIndex(int index, T &value);
    int GetIndexByElem(T &value);
    void insert(T &value);
    bool Find(T &value);
    void DeleteMinimum();
    void DeleteByValue(T &value);
    void DeleteRepeated();
    Sequence<int>* GetIndexOfSubHeap(int index);
    Heap<T>* GetSubHeap(int index);

    //operators
    T &operator [] (const int indextoget);
    Heap<T> &operator=(Heap<T> &heaptocopy);
    template<class R>
    friend std::ostream& operator <<(std::ostream &out, const Heap<R> &heaptoprint);

    //destruction
    void clear();
    ~Heap();
};

#endif // HEAP_H
