#include "vector.h"
#include <iostream>
#include <cmath>
//основан на linked list



template<class T>
Vector<T>::Vector() {
    data_ = (Sequence<T>*) new ListSequence<T>();
    dimension_ = 0;
}

template<class T>
Vector<T>::Vector(int dimension) {
    data_ = (Sequence<T>*) new ListSequence<T>();
    this->dimension_ = dimension;
}

template<class T>
Vector<T>::Vector(Sequence<T> *data) {
    data_ = (Sequence<T>*) new ListSequence<T>();
    this->dimension_ = data->GetLength();
    for (int i = 0; i < dimension_; ++i)
        data_->Append(data->Get(i));
}

template<class T>
Vector<T>::Vector(const Vector<T> &vector) {
    data_ = (Sequence<T>*) new ListSequence<T>();
    this->dimension_ = vector.dimension_;
    for (int i = 0; i < dimension_; ++i)
        data_->Append(vector.data_->Get(i));
}

template<class T>
int Vector<T>::GetDimension() const {
    return this->dimension_;
}

template<class T>
T &Vector<T>::Get(int index) {
    return data_->Get(index);
}

template<class T>
void Vector<T>::Set(int index, T& value) {
    if (index == data_->GetLength())
        data_->Append(value);
    else
        data_->Set(index, value);
}

template<class T>
Vector<T> Vector<T>::Addition(Vector<T> v) {
    if (v.dimension_ != dimension_)
        throw std::exception();
    Vector<T> VectorSum(dimension_);
    for (int i = 0; i < dimension_; ++i) {
        T value = Get(i) + v.Get(i);
        VectorSum.Set(i, value);
    }
    return VectorSum;
}

template<class T>
Vector<T> Vector<T>::Subtraction(Vector<T> v) {
    if (v.dimension_ != dimension_)
        throw std::exception();
    Vector<T> VectorDiff(dimension_);
    for (int i = 0; i < dimension_; ++i) {
        T value = Get(i) - v.Get(i);
        VectorDiff.Set(i, value);
    }
    return VectorDiff;
}

template<class T>
Vector<T> Vector<T>::ScalarMultiplication(T number) {
    Vector<T> MultipliedVector(dimension_);
    for (int i = 0; i < dimension_; ++i) {
        T value = Get(i) * number;
        MultipliedVector.Set(i, value);
    }
    return MultipliedVector;
}

template<class T>
T Vector<T>::DotProduct(Vector<T> vector) {
    if (vector.dimension_ != dimension_)
        throw std::exception();
    T result = Get(0) * vector.Get(0);
    for (int i = 1; i < dimension_; ++i) {
        result = result + Get(i) * vector.Get(i);
    }
    return result;
}

template<class T>
double Vector<T>::Norm() {
    double value = fabs(this->Get(0));
    double norm_squared = value * value;
    for (int i = 1; i < dimension_; ++i) {
        value = fabs(this->Get(i));
        norm_squared += value * value;
    }
    return sqrt(norm_squared);
}

template<class T>
Vector<T> &Vector<T>:: operator = (Vector<T> *vector) {
    data_ = vector->data_->Clone();
    return *this;
}

template<class T>
std::ostream& operator << (std::ostream &out, const Vector<T> &v) {
    std::cout << "( ";
    for (int i = 0; i < v.dimension_; ++i) {
        out << (*v.data_)[i];
        if (i == v.dimension_ - 1)
            break;
        out << ", ";
    }
    std::cout << " )";
    return out;
}

template<typename T>
Vector<T>::~Vector() {
    dimension_ = 0;
    data_->~Sequence<T>();
    delete data_;
}
