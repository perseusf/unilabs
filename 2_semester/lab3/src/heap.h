#ifndef HEAP_H
#define HEAP_H

#include "arraysequence.h"
#include "arraysequence.cpp"
#include <iostream>

template<class T>
class Heap
{
    Sequence<T> *_heap;

    void siftUp(int index);
    void siftDown(int index);

public:
    Heap();
    Heap(const Sequence<T> &seq);
    Heap(Heap<T> &heap);

    void clear();
    int GetLength() const;
    int Getheight() const;

    void insert(T &value);
    T &getMin();
    T &getByIndex(int index);
    int getElementIndex(T &value);
    void setByIndex(int index, T &value);
    T &operator [] (const int index);
    bool checkEntry(T &value);
    void delMin();
    void delByValue(T &value);
    void delRepeat();
    std::string SavePairsInString();

    Sequence<int>* extractSubHeapIndex(int index);
    Heap<T>* extractSubHeap(int index);

    template<class R>
    friend std::ostream& operator <<(std::ostream &out, const Heap<R> &h);

    ~Heap();
};

#endif // HEAP_H
