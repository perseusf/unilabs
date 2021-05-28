#ifndef LISTSEQUENCE_H
#define LISTSEQUENCE_H

#include "sequence.h"
#include "linkedlist.h"
#include "linkedlist.cpp"
#include "iostream"

template <typename T>
class ListSequence: public Sequence<T> {
private:
    LinkedList<T> *list_;
public:
    //constructors
    ListSequence();
    ListSequence(T *data, int length);
    ListSequence(const ListSequence<T> &list);

    //decomposition
    T &GetFirst();
    T &GetLast();
    T &Get(int index);
    Sequence<T> *GetSubSequence(int start, int end) const;
    [[nodiscard]] int GetLength() const;
    void DelByIndex(int index);

    //operations
    void Append(const T &data);
    void Prepend(const T &data);
    void InsertAt(const T &data, int index);
    void Set(int index, const T &data);
    Sequence<T> *Concat(Sequence <T> *sequence) const;
    Sequence<T> *Clone();

    //operators
    T &operator[] (int index);

    ~ListSequence();
};

#endif // LISTSEQUENCE_H
