#include <iostream>
#include "linkedlist.h"

template<typename T>
LinkedList<T>::LinkedList() {
    length_ = 0;
    head_ = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(T *data, int length) : LinkedList() {
    if (length < 0) {
        throw std::out_of_range("LinkedList(): INDEX_OUT_OF_RANGE");
    }
    for (int i = 0; i < length; i++)
        PushBack(data[i]);
}

//мб через pushBack реализовать.....
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) {
    Node *node = list.head_->pNext;
    for (int i = 0; i < list.length_; i++)
        InsertAt(node->data, i);
}

template<typename T>
T &LinkedList<T>::GetFront() const {
    if (length_ == 0) {
        throw std::out_of_range ("GetFront(): EMPTY_LIST");
    }
    return head_->data;
}

template<typename T>
T &LinkedList<T>::GetBack() const {
    if (length_ == 0)
        throw std::out_of_range ("GetBack(): EMPTY_LIST");
    Node *node = this->head_;
    for (int i = 0; i < length_; ++i)
    {
        node = node->pNext;
    }
    return node->data;
}

template<typename T>
T &LinkedList<T>::Get(int index) const {
    if (index >= length_ || index < 0) {
        throw std::out_of_range ("Get(): INDEX_OUT_OF_RANGE");
    }
    Node *value = head_;
    for (int i = 0; i < index; ++i) {
        value = value->pNext;
    }
    return value->data;

}

template<typename T>
void LinkedList<T>::PopFront() {
    if (length_ == 0) {
        throw std::out_of_range ("PopFront(): EMPTY_LIST");
    }
    Node* rNode = head_;
    head_ = head_->pNext;
    length_--;
    delete rNode;
}

template<typename T>
void LinkedList<T>::PopBack() {
    if (length_ == 0) {
        throw std::out_of_range ("PopBack(): EMPTY_LIST");
    }
    Node* node = head_;
    for (int i = 0; i < length_ - 1; ++i) node = node->pNext;
    Node* rNode = node->pNext;
    node->pNext = nullptr;
    length_--;
    delete rNode;
}

template<typename T>
void LinkedList<T>::DelByIndex(int index) {
    if (index < 0 || index >= length_) {
        throw std::out_of_range ("DelByIndex(): INDEX_OUT_OF_RANGE");
    }
    if (index == 0) {
        PopFront();
        return;
    }
    Node *nNode = head_;
    for (int i = 1; i < index; ++i) {
        nNode = nNode->pNext;
    }
    Node *rNode = nNode->pNext;
    nNode->pNext = nNode->pNext->pNext;
    length_--;
    delete rNode;
}

template<typename T>
void LinkedList<T>::Clear() {
    while (length_)
        PopFront();
}

template<typename T>
LinkedList<T> *LinkedList<T>::GetSubList(int start, int end) const {
    if (start < 0 || start >= length_ || end < 0 || end > length_ || start > end)
        throw std::out_of_range ("GetSubList(): INDEX_OUT_OF_RANGE");
    if (end < start) {
        std::swap(start, end);
    }
    LinkedList<T> *rList = new LinkedList<T>;
    for (int i = start; i < end; i++)
        (*rList).PushBack(this->Get(i));
    return rList;
}

template<typename T>
int LinkedList<T>::GetLength() const {
    return length_;
}

template<typename T>
void LinkedList<T>::PushFront(const T &data) {
    Node* nNode = new Node(data);
    if (length_ == 0) {
        head_ = nNode;
        length_++;
        return;
    }
    nNode->pNext = head_;
    head_ = nNode;
}

//hm
template<typename T>
void LinkedList<T>::PushBack(const T &data) {
    Node* nNode = new Node(data);
    if (!length_) {
        head_ = nNode;
        length_++;
        return;
    }
    Node *node = head_;
    for(int i = 0; i < length_ - 1; ++i) {
        node = node->pNext;
    }
    node->pNext = nNode;
    length_++;
}

template<typename T>
void LinkedList<T>::InsertAt(const T &data, int index) {
    if (index < 0 || index > this->length_)
        throw std::out_of_range ("InsertAt(): INDEX_OUT_OF_RANGE");
    if (!index) {
        this->PushFront(data);
        return;
    }
    if (index == this->length_) {
        this->PushBack(data);
        return;
    }
    Node* node = this->head_;
    for (int i = 0; i < index - 1; i++) {
        node = node->pNext;
    }
    Node* nNode = new Node(data, node->pNext);
    node->pNext = nNode;
    this->length_++;

}

template<typename T>
void LinkedList<T>::Set(int index, const T &data) {
    if (index < 0 || index > this->length_)
        throw std::out_of_range ("Set(): INDEX_OUT_OF_RANGE");
    if (index == length_) {
        this->PushBack(data);
        return;
    }
    Node* nNode = this->head_;
    for (int i = 0; i < index; i++) {
        nNode = nNode->pNext;
    }
    nNode->data = data;
}

template<typename T>
LinkedList<T> *LinkedList<T>::Concat(LinkedList<T> *list) const {
    if (list == nullptr)
        throw std::out_of_range ("Concat(): INDEX_OUT_OF_RANGE");
    LinkedList* nList = new LinkedList;
    for (int i = 0; i < length_; ++i) {
        nList->PushBack(this->Get(i));
    }
    for (int i = 0; i < list->length_; ++i) {
        nList->PushBack(list->Get(i));
    }
    return nList;
}

template<typename T>
T& LinkedList<T>::operator[](int index) {
    try {
        if (index <0 || index > length_ - 1) {
            throw "INDEX_OUT_OF_RANGE!";
        }
        Node *temp = head_;
        for (int i=0; i<index; i++) {
            temp = temp->pNext;
        }
        return temp->data;
    } catch (const char *error) {
        std::cout << error << std::endl;
    }
}

template<typename T>
LinkedList<T>::~LinkedList() {
    Clear();
}
