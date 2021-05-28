//
// Created by bzavo on 5/26/2021.
//

#include "vector.h"
#include "arraysequence.h"

template<class T>
Vector<T>::Vector() : array_(new ArraySequence<T>) {}

template<typename T>
Vector<T>::Vector(int length) : array_(new ArraySequence<T>(length)) {}

template<class T>
Vector<T>::Vector(const T *data, int length):
        array_(new ArraySequence<T>(data, length)) {}

template<class T>
T &Vector<T>::operator[](int index) {
    if (index >= this->size())
        throw std::out_of_range("out of range");
    return array_->Get(index);
}

template<class T>
T &Vector<T>::at(int index) {
    if (index >= this->size())
        throw std::out_of_range("out of range");
    return array_->Get(index);
}

template<class T>
T &Vector<T>::at(int index) const {
    if (index >= this->size())
        throw std::out_of_range("out of range");
    return array_->Get(index);
}

template<class T>
void Vector<T>::push_back(const T &value) {
    array_->Append(value);
}

template<class T>
Vector<T>::Vector(const Vector<T> &vector):
        array_(new ArraySequence<T>(*((ArraySequence<T> *) vector.array_))) {}

template<class T>
Vector<T>::~Vector() {
    delete (ArraySequence<T> *) array_;
}

template<typename T>
size_t Vector<T>::size() const {
    return array_->GetLength();
}

template<class T>
bool Vector<T>::empty() const {
    return (array_->GetLength() == 0);
}

template<class T>
void Vector<T>::resize(int length) {
    array_->Resize(length);
}

template<class T>
Vector<T> &operator+(const Vector<T> &v1, const Vector<T> &v2) {
    int size_max = std::max(v1.size(), v2.size());
    int size_min = std::min(v1.size(), v2.size());
    T *v3_data = new T[size_max];
    for (int i = 0; i < size_max; ++i) {
        if (i < size_min) v3_data[i] = v1.array_->Get(i) + v2.array_->Get(i);
        else if (v1.size() > v2.size()) v3_data[i] = v1.array_->Get(i);
        else v3_data[i] = v2.array_->Get(i);
    }
    return *(new Vector<T>(v3_data, size_max));
}

template<class T>
Vector<T> &operator*(T lambda, const Vector<T> &v) {
    T *new_data = new T[v.size()];
    for (int i = 0; i < v.size(); ++i) {
        new_data[i] = lambda * v.at(i);
    }
    return *(new Vector<T>(new_data, v.size()));
}

template<class T>
T operator*(const Vector<T> &v1, const Vector<T> &v2) {
    int size_min = std::min(v1.size(), v2.size());
    T answer = 0;
    for (int i = 0; i < size_min; ++i) {
        answer += v1.at(i) * v2.at(i);
    }
    return answer;
}

template<class T>
T Vector<T>::CalculatingTheNormOfVector() {
    T norma = 0;
    for (int i = 0; i < this->size(); ++i) {
        norma += this->at(i) * this->at(i);
    }
    return sqrt(norma);
}