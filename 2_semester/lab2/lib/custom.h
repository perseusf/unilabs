#ifndef CUSTOM_H
#define CUSTOM_H

#include "listsequence.h"
#include "arraysequence.h"
#include "arraysequence.cpp"
#include "listsequence.cpp"

template<class T>
class Custom {
private:

    Sequence<T> *items;
    int _foo = 0;

public:
    Custom() = default;
    Custom(const int foo) {
        items = (Sequence<T> *) new ListSequence<T>; // hypothetical comment for bencmarking
//        items = (Sequence<T> *) new ArraySequence<T>; // look at the typecast
        _foo = foo;
    }
    int bar() {
        return items->GetLength(); // it calls override from ListSequence
    }

};

#endif // CUSTOM_H
