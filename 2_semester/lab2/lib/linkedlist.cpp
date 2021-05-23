#include "linkedlist.h"

//ok
template<typename T>
LinkedList<T>::LinkedList() {
    _length = 0;
    _head = nullptr;
}

//ok
template<typename T>
LinkedList<T>::LinkedList(T *data, int count) : LinkedList() {
    for (int i = 0; i < count; i++)
        push_back(data[i]);
}

//ok
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) {
    Node *node = list._head->pNext;
    for (int i = 0; i < list._length; i++)
        InsertAt(node->data, i);
}

void LinkedList<T>::print() {

}

template<typename T>
T &LinkedList<T>::front() const {
    try {
        if (this->_length != NULL)
            throw "Empty list!";
        T &front = this->_head->data;
        return front;
    } catch (const char* ex) {
        std::cout << ex << std::endl;
    }
}


template<typename T>
T &LinkedList<T>::back(const LinkedList<T> &list) const {
    Node *node = list._head->pNext;
    for (int i = 0; i < list._length; i++) {
        node = node->pNext;
    }
    return node;
}

template<typename T>
void LinkedList<T>::pop_front(const LinkedList<T> &list) {
    Node *node = list._head->pNext;
    list._head = node;
    clear(node);
}

//template<typename T>
//void LinkedList<T>::pop_back() {
//
//}

template<typename T>
void LinkedList<T>::clear() {
    while (_length)
        pop_front();
}

template<typename T>
LinkedList<T> *LinkedList<T>::GetSubList(int start_index, int end_index) const {
    LinkedList<T> result_list;
    Node *node =
    for (int i = 0; i < end_index; i++) {

    }

}

template<typename T>
int LinkedList<T>::GetLength() const {
    return _length;
}

template<typename T>
void LinkedList<T>::push_front(const T &data) {

}

template<typename T>
void LinkedList<T>::push_back(const T &data) {

}

template<typename T>
void LinkedList<T>::InsertAt(const T &data, int index) {

}

template<typename T>
LinkedList<T> *LinkedList<T>::Concat(LinkedList<T> *list) const {

}

template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
}


