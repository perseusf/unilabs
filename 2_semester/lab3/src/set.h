#ifndef SET_H
#define SET_H

#include "heap.h"

template<class T>
class Set
{
    Heap<T> *_elements;

public:
    Set();
    Set(const Sequence<T> &seq);
    Set(const Set<T> &set);
    Set(Heap<T> *heap);

    void clear();
    int GetLength() const;

    void insert(T &value);
    void insertRepeat(T &value);
    T &getMin();
    T &extractMin();
    bool checkEntry(T &value);
    void delByValue(T &value);
    std::string SaveInString();

    Set<T> operator + (const Set<T> &other);
    Set<T> operator * (const Set<T> &other);
    Set<T> operator - (const Set<T> &other);

    bool operator == (const Set<T> &other);
    bool operator != (const Set<T> &other);

    bool checkSubSet (Set *set);

    template<class R>
    friend std::ostream& operator << (std::ostream &out, const Set<R> &h);

    ~Set();
};

#endif // SET_H
