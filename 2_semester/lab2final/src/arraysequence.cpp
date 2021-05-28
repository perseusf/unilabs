#include "arraysequence.h"
#include "dynamicarray.h"
//#include "dynamicarray.cpp"
//ok
template<class T>
ArraySequence<T>::ArraySequence(): array(new DynamicArray <T>()) {}

//ok
template<class T>
ArraySequence<T>::ArraySequence(T* data, int length) {
    array = new DynamicArray<T>(data, length);
}

//ok
template<class T>
ArraySequence<T>::ArraySequence(ArraySequence<T> &data) {
    this->array = new DynamicArray<T>(data.GetLength());
    for (int i = 0; i < data->GetLength(); ++i) {
        this->array->Set(data.Get(i), i);
    }
}

//ok
template<class T>
T &ArraySequence<T>::GetFirst() {
    try {
        if (GetLength() <= 0)
            throw "INVALID_LENGTH!";
        return Get(0);
    }  catch (const char *error) {
        std::cout << error << std::endl;
    }
}

//ok
template<class T>
T &ArraySequence<T>::GetLast() {
    try {
        if (GetLength() <= 0)
            throw "INVALID_LENGTH!";
        return Get(GetLength() - 1);
    }  catch (const char *error) {
        std::cout << error << std::endl;
    }
}

//ok
template<class T>
T &ArraySequence<T>::Get(int index) {
    try {
        if (index < 0 || index >= GetLength())
            throw "INDEX_OUT_OF_RANGE!";
        return Get(index);
    }  catch (const char *error) {
        std::cout << error << std::endl;
    }
}

//ok
template<class T>
T &ArraySequence<T>::operator[](const int index) {
    try {
        if (index < 0 || index >= GetLength())
            throw "INDEX_OUT_OF_RANGE!";
        return Get(index);
    }  catch (const char *error) {
        std::cout << error << std::endl;
    }
}

//ok
template<class T>
Sequence<T> *ArraySequence<T>::GetSubSequence(int start, int end) const {
    try {
        if (start > end || start < 0 || end < 0 || start >= GetLength() || end > GetLength())
            throw "INVALID_INDEX!";
        Sequence<T> *rArray = (Sequence<T> *) new DynamicArray<T>(end - start);
        for (int i = start; i < end; ++i)
            rArray->Set(array->Get(i), i - start);
        return rArray;
    }  catch (const char *error) {
        std::cout << error << std::endl;
    }
}

//ok
template<class T>
int ArraySequence<T>::GetLength() const {
    return array->GetLength();
}

//ok
template<class T>
void ArraySequence<T>::DelByIndex(int index) {
    try {
        if (index < 0 || index >= array->GetLength())
            throw "INDEX_OUT_OF_RANGE";
        array->DelByIndex(index);
    }  catch (const char *error) {
        std::cout << error << std::endl;
    }
}

template<class T>
void ArraySequence<T>::Resize(int length) {
    array->Resize(length);
}

//ok rewrite
template<class T>
void ArraySequence<T>::Prepend(const T &value){
    Resize(GetLength() + 1);
    for (int i = GetLength() - 1; i > 0; --i)
        Set(Get(i - 1), i);
    Set(value, 0);
}

//or rewrite
template<class T>
void ArraySequence<T>::Append(const T &value) {
    array->Resize(this->GetLength() + 1);
    array->Set(value, this->GetLength() - 1);
}

//ok rewrite
template<class T>
void ArraySequence<T>::InsertAt(const T &value, int index) {
    if (index == this->GetLength()) {
        this->Append(value);
        return;
    }
    if (index > this->GetLength()) {
        array->Resize(index);
        this->Append(value);
        return;
    }
    array->Resize(this->GetLength() + 1);
    for (int i = this->GetLength() - 1; i > index; --i)
        array->Set(this->Get(i - 1), i);
    array->Set(value, index);
}

//rewrite
template<class T>
void ArraySequence<T>::Set(const T &value, int index) {
    if (index >= this->GetLength())
        array->Resize(index + 1);
    array->Set(value, index);
}

//rewrite
template<class T>
Sequence<T> *ArraySequence<T>::Concat(Sequence<T> *seq) const {
    try {
        if (seq == nullptr)
            throw "There is no sequence to contact!";
        Sequence<T> *array = (Sequence<T> *) new DynamicArray<T>(array->GetLength() + seq->GetLength());
        for (int i = 0; i < -array->GetLength(); ++i)
            array->Append(array->Get(i));
        for (int i = 0; i < seq->GetLength(); ++i)
            array->Append(seq->Get(i));
        return array;
    }  catch (const char *error) {
        std::cout << error << std::endl;
    }
}

//rewrite
template<class T>
ArraySequence<T>::~ArraySequence() {
    array->~DynamicArray<T>();
    delete array;
}
