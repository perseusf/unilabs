#include <iostream>
#include "dynamicarray.h"

//ok
template<class T>
DynamicArray<T>::DynamicArray() {
    data = nullptr;
    length = 0;
}

//ok
template<class T>
DynamicArray<T>::DynamicArray(T *array, int size) {
    length = size;
    if (size)
        data = new T[size];
    else
        data = nullptr;
    for (int i = 0; i < length; i++)
        data[i] = array[i];
}
//ok
template<class T>
DynamicArray<T>::DynamicArray (int size) {
    length = size;
    if (length != 0)
        data = new T[length];
    else
        data = nullptr;
}

//ok
template<class T>
DynamicArray<T>::DynamicArray (const DynamicArray<T> &array) {
    length = array->length;
    if (length != 0)
        data = new T[length];
    else
        data = nullptr;
    for (int i = 0; i < length; i++)
        data[i] = array->data[i];
}

//ok
template<class T>
T &DynamicArray<T>::Get(int index) {
    try {
        if (index < 0 || index >= length)
            throw "INDEX_OUT_OF_RANGE!";
        return data[index];
    }  catch (const char *error) {
        std::cout << error << std::endl;
    }
    return data[0];
}


//template<class T>
//T &DynamicArray<T>::Get(int index, const T &error) {
//    try {
//        if (index < 0 || index >= length)
//            throw "Index is out of range!";
//        return data[index];
//    }  catch (const char *error) {
//        std::cout << error << std::endl;
//    }
//    return error;
//}

//rewrite! or check
template<class T>
void DynamicArray<T>::DelByIndex(int index) {
    try {
        if (index >= length || index < 0)
            throw "INDEX_OUT_OF_RANGE!";
        for (int i = 0; i < length - 1; i++) {
            if (i < index) continue;
            else data[i] = data[i + 1];
        }
        this->Resize(length - 1); //rewrite this carefully
    }  catch (const char *error) {
        std::cout << error << std::endl;
    }
}

//ok
template<class T>
int DynamicArray<T>::GetLength() const {
    return length;
}

//ok
template<class T>
void DynamicArray<T>::Set(int index, const T &value) {
    try {
        if (index < 0 || index >= length)
            throw "INDEX_OUT_OF_RANGE!";
        data[index] = value;
    }  catch (const char* error) {
        std::cout << error << std::endl;
    }
}

//rewrite!!!!! repeated
template<class T>
void DynamicArray<T>::Resize(int length) {
    try {
        if (length < 0)
            throw "LENGTH_NEGATIVE!";
        if (!length) {
            delete[] data;
            data = nullptr;
            length = 0;
            return;
        }
        T *array = new T [length];
        for (int i = 0; i < std::min(length, length); ++i) {
            array[i] = this->Get(i);
        }
        delete[] data;
        data = array;
        length = length;
    }  catch (const char* error) {
        std::cout << error << std::endl;
    }
}

//ok
template<typename T>
T &DynamicArray<T>::operator[](const int index) {
    try {
        if (index < 0 || index >= length) {
            throw "INDEX_OUT_OF_RANGE";
        }
    } catch (const char *error) {
        std::cout << error << std::endl;
    }
    return Get(index);
}

//ok
template<typename T> bool DynamicArray<T>::operator==(const DynamicArray<T> &arr) {
    if (length != arr.length) {
        return false;
    }
    for (int i = 0; i < this->length; i++) {
        if (Get(i) != arr.Get(i)) {
            return false;
        }
    }
    return true;
}


//ok
template<class T>
DynamicArray<T>::~DynamicArray() {
    length = 0;
    delete[] data;
}
