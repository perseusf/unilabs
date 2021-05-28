//
// Created by bzavo on 5/26/2021.
//
#ifndef LAB2FINAL_VECTOR_H
#define LAB2FINAL_VECTOR_H

#pragma once

#include "listsequence.h"
#include "arraysequence.h"
#include <cmath>

template<class T>
class Vector {

private:
    Sequence<T> *array_;

public:
    //Constrictor
    Vector();
    Vector(int length);
    Vector(const T *data, int length);
    Vector(const Vector<T> &vector);

    //Operation
    [[nodiscard]] size_t size() const;
    [[nodiscard]] bool empty() const;
    T &operator[](int index);
    T &at(int index);
    T &at(int index) const;
    void resize(int length);
    void push_back(const T &value);

    //Task operations
    template<class U>
    friend Vector<U>& operator+(const Vector<U>& v1, const Vector<U>& v2);
    template<class U>
    friend Vector<U>& operator*(U lambda, const Vector<U>& v);
    template<class U>
    friend U operator*(const Vector<U>& v1, const Vector<U>& v2);
    T CalculatingTheNormOfVector();

    //Destructor
    ~Vector();
};

#endif //LAB2FINAL_VECTOR_H
