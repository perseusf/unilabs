#include "arraysequence.h"

template<typename T>
ArraySequence<T>::ArraySequence(): array_(new DynamicArray <T>()) {}

template<typename T>
ArraySequence<T>::ArraySequence(T* data, int length) {
    array_ = new DynamicArray<T>(data, length);
}

template<typename T>
ArraySequence<T>::ArraySequence(const ArraySequence<T> &data) {
    this->array_ = new DynamicArray<T>(data.GetLength());
    for (int i = 0; i < array_->GetLength(); ++i) {
        array_->Set(i, data.Get(i));
    }
}

template<typename T>
T &ArraySequence<T>::GetFirst() {
    if (array_->GetLength() <= 0)
        throw std::out_of_range("GetFirst(): INVALID_LENGTH");
    return array_->Get(0);
}

template<typename T>
T &ArraySequence<T>::GetLast() {
    if (array_->GetLength() <= 0)
        throw std::out_of_range("GetLast(): INVALID_LENGTH");
    return array_->Get(this->GetLength());
}

template<typename T>
T &ArraySequence<T>::Get(int index) {
    if (index < 0 || index >= array_->GetLength())
        throw std::out_of_range("Get(): INDEX_OUT_OF_RANGE");
    return array_->Get(index);
}

template<class T>
T &ArraySequence<T>::operator[](const int index) {
    if (index < 0 || index >= array_->GetLength())
        throw std::out_of_range("operator[]: INDEX_OUT_OF_RANGE");
    return this->Get(index);
}

template<typename T>
Sequence<T> *ArraySequence<T>::GetSubSequence(int start, int end) const {
    if (start > end || start < 0 || end < 0 || start >= this->GetLength() || end > this->GetLength())
        throw std::out_of_range("GetSubSequence(): INVALID_RANGE");
    Sequence<T> *rArray = (Sequence<T> *) new DynamicArray<T>(end - start);
    for (int i = start; i < end; ++i)
        rArray->Set(i - start, array_->Get(i));
    return rArray;
}

template<typename T>
int ArraySequence<T>::GetLength() const {
    return array_->GetLength();
}

template<class T>
void ArraySequence<T>::DelByIndex(int index) {
    if (index < 0 || index >= array_->GetLength())
        throw std::out_of_range("DelByIndex(): INDEX_OUT_OF_RANGE");
    array_->DelByIndex(index);
}

template<class T>
void ArraySequence<T>::Resize(int length) {
    array_->Resize(length);
}

template<typename T>
void ArraySequence<T>::Append(const T &data) {
    array_->Resize(this->GetLength() + 1);
    array_->Set(this->GetLength() - 1, data);
}

template<typename T>
void ArraySequence<T>::Prepend(const T &data) {
    array_->Resize(this->GetLength() + 1);
    array_->Set(0, data);
}

template<typename T>
void ArraySequence<T>::InsertAt(const T &data, int index) {
    if (index > this->GetLength())
        throw std::out_of_range("InsertAt(): INDEX_OUT_OF_RANGE");
    array_->Resize(this->GetLength() + 1);
    array_->Set(index, data);
    if (index == this->GetLength()) {
        this->Append(data);
        return;
    }
    array_->Resize(this->GetLength() + 1);
    for (int i = this->GetLength() - 1; i > index; --i)
        array_->Set(i, this->Get(i - 1));
    array_->Set(index, data);
}

template<class T>
void ArraySequence<T>::Set(int index, const T &data) {
    if (index >= this->GetLength())
        throw std::out_of_range("Set(): INDEX_OUT_OF_RANGE");
    array_->Set(index, data);
}

template<typename T>
Sequence<T> *ArraySequence<T>::Concat(Sequence<T> *sequence) const {
    if (sequence == nullptr)
        throw std::out_of_range("Concat(): NO_SEQUENCE");
    Sequence<T> *rArray = (Sequence<T> *) new DynamicArray<T>(array_->GetLength() + sequence->GetLength());
    for (int i = 0; i < rArray->GetLength(); ++i)
        rArray->Append(array_->Get(i));
    for (int i = 0; i < sequence->GetLength(); ++i)
        rArray->Append(sequence->Get(i));
    return rArray;
}

template<class T>
Sequence<T> *ArraySequence<T>::Clone() {
    auto *new_items = new ArraySequence<T>();
    new_items->Resize(GetLength());
    for (int i = 0; i < GetLength(); i++)
    (*new_items)[i] = array_->Get(i);
    return new_items;
}

template<typename T>
ArraySequence<T>::~ArraySequence() {
    array_->~DynamicArray<T>();
    delete array_;
}
