#include <iostream>
#include "dynamicarray.h"



template<typename T>
DynamicArray<T>::DynamicArray() {
    length_ = 0;
    data_ = nullptr;
}

template<typename T>
DynamicArray<T>::DynamicArray(T *array, int size) {
    length_ = size;
    if(size)
        data_ = new T[size];
    else
        data_ = nullptr;
    for (int i = 0; i < length_; i++)
        data_[i] = array[i];
}

template<typename T>
DynamicArray<T>::DynamicArray (int size) {
    length_ = size;
    if (size > 0)
        data_ = new T[size];
    else
        data_ = nullptr;
}

template<typename T>
DynamicArray<T>::DynamicArray (const DynamicArray<T> &array) {
    length_ = array->length_;
    if (length_ > 0)
        data_ = new T[length_];
    else
        data_ = nullptr;
    for (int i = 0; i < length_; i++)
        data_[i] = array.data_[i];
}

template<typename T>
T &DynamicArray<T>::Get(int index) {
    if (index < 0 || index >= length_)
        throw std::out_of_range ("Get(): INDEX_OUT_OF_RANGE");
    return data_[index];
}

template<class T>
void DynamicArray<T>::DelByIndex(int index) {
    if (index >= length_ || index < 0)
        throw std::out_of_range ("DelByIndex(): INDEX_OUT_OF_RANGE");
    for (int i = 0; i < length_ - 1; ++i) {
        if (i < index) continue;
        else data_[i] = data_[i + 1];
    }
    this->Resize(length_ - 1);
}

template<typename T>
int DynamicArray<T>::GetLength() const {
    return length_;
}

template<typename T>
void DynamicArray<T>::Set(int index, const T &value) {
    if (index < 0 || index >= length_)
        throw std::out_of_range ("Set(): INDEX_OUT_OF_RANGE");
    data_[index] = value;
}

template<typename T>
void DynamicArray<T>::Resize(int length) {
    if (length < 0)
        throw std::out_of_range ("Resize(): NEGATIVE_INDEX");
    if (!length) {
        delete[] data_;
        data_ = nullptr;
        length_ = 0;
        return;
    }
    T *array = new T [length];
    for (int i = 0; i < std::min(length, length_); i++) {
        array[i] = this->Get(i);
    }
    delete[] data_;
    data_ = array;
    length_ = length;
}

//ok
template<typename T>
T &DynamicArray<T>::operator[](const int index) {
    try {
        if (index < 0 || index >= length_) {
            throw "operator[]: INDEX_OUT_OF_RANGE";
        }
    } catch (const char *error) {
        std::cout << error << std::endl;
    }
    return Get(index);
}

//ok
template<typename T> bool DynamicArray<T>::operator==(const DynamicArray<T> &arr) {
    if (length_ != arr.length) {
        return false;
    }
    for (int i = 0; i < this->length; i++) {
        if (Get(i) != arr.Get(i)) {
            return false;
        }
    }
    return true;
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    length_ = 0;
    delete[] data_;
}
