#include "listsequence.h"


template<typename T>
ListSequence<T>::ListSequence(): list_(new LinkedList <T>()) {}

template<typename T>
ListSequence<T>::ListSequence(T *data, int length) {
    list_ = new LinkedList<T>(data, length);
}

template<typename T>
ListSequence<T>::ListSequence(const ListSequence<T> &list) {
    list_ = new LinkedList<T>(list);
}

template<typename T>
T &ListSequence<T>::GetFirst() {
    if (!list_->GetLength())
        throw std::out_of_range ("GetFirst(): LIST_IS_EMPTY");
    return list_->GetFront();
}

template<typename T>
T &ListSequence<T>::GetLast() {
    if (!list_->GetLength())
        throw std::out_of_range ("GetLast(): LIST_IS_EMPTY");
    return list_->GetBack();
}

template<typename T>
T &ListSequence<T>::Get(int index) {
    if (index >= list_->GetLength() || index < 0)
        throw std::out_of_range ("Get(): INDEX_OUT_OF_RANGE");
    return list_->Get(index);
}

template<class T>
T &ListSequence<T>::operator[](const int index) {
    if (index >= list_->GetLength() || index < 0)
        throw std::out_of_range ("operator[]: LIST_IS_EMPTY");
    return this->Get(index);
}

template<typename T>
Sequence<T> *ListSequence<T>::GetSubSequence(int start, int end) const {
    if (start < 0 || start >= list_->GetLength() || end < 0 || end > list_->GetLength())
        throw std::out_of_range ("GetSubSequence(): INDEX_OUT_OF_RANGE");
    return (Sequence<T> *) list_->GetSubList(start, end);
}

template<typename T>
int ListSequence<T>::GetLength() const {
    return list_->GetLength();
}

template<class T>
void ListSequence<T>::DelByIndex(int index) {
    if (index < 0 || index >= this->GetLength())
        throw std::out_of_range ("DelByIndex(): INDEX_OUT_OF_RANGE");
    list_->DelByIndex(index);
}

template<typename T>
void ListSequence<T>::Append(const T &data) {
    list_->PushBack(data);
}

template<typename T>
void ListSequence<T>::Prepend(const T &data) {
    list_->PushFront(data);
}

template<typename T>
void ListSequence<T>::InsertAt(const T &data, int index) {
    if (index < 0 || index > list_->GetLength())
        throw std::out_of_range ("InsertAt(): INDEX_OUT_OF_RANGE");
    list_->InsertAt(data, index);
}


template<class T>
void ListSequence<T>::Set(int index, const T& data) {
    if (index < 0 || index > list_->GetLength())
        throw std::out_of_range ("Set(): INDEX_OUT_OF_RANGE");
    list_->Set(index, data);
}

template<typename T>
Sequence<T> *ListSequence<T>::Concat(Sequence<T> *sequence) const {
    if (sequence == nullptr)
        throw std::out_of_range ("Concat(): INDEX_OUT_OF_RANGE");
    ListSequence<T> *sList = new ListSequence<T>();
    for (int i = 0; i < sequence->GetLength(); i++) {
        sList->Append(sequence->Get(i));
    }
    return (Sequence<T> *) list_->Concat(sList->list_);
}

template <typename T>
void ListSequence<T>::Swap(T& first, T& second) {
    T temporary = first;
    first = second;
    second = temporary;
}

template<class T>
Sequence<T> *ListSequence<T>::Clone() {
    auto *newList = new ListSequence<T>();
    for (int i = 0; i < GetLength(); i++)
    newList->Append(list_->Get(i));
    return newList;
}

template<typename T>
ListSequence<T>::~ListSequence() {
    list_->~LinkedList<T>();
    delete list_;
}



