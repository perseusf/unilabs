#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "dynamicarray.h"

template<class T>
class Sequence {

public:
    virtual T& GetFirst() = 0;
    virtual T& GetLast() = 0;
    virtual T& Get(int index) = 0;
    virtual T& operator [] (const int index) = 0;
    virtual Sequence<T> *GetSubSequence(int start_index, int end_index) const = 0;
    virtual int GetLength() const = 0;
    virtual void DelByIndex(int index) = 0;

    virtual void Append(T& item) = 0;
    virtual void Prepend(T& item) = 0;
    virtual void InsertAt(T& item, int index) = 0;
    virtual void Set(int index, T& item) = 0;
    virtual Sequence<T> *Concat(Sequence<T> *Sequence) const = 0;

    void Sort() {
        for (int i = 0; i < GetLength() - 1; ++i)
            for (int j = 0; j < GetLength() - i - 1; ++j)
                if (this->operator[](j) > this->operator[](j + 1)) {
                    T tmp = this->operator[](j);
                    Set(j, this->operator[](j + 1));
                    Set(j + 1, tmp);
                }
    }
};

#endif // SEQUENCE_H
