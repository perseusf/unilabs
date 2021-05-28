#include <iostream>
#include "linkedlist.h"

//ok
template<class T>
LinkedList<T>::LinkedList() {
    length = 0;
    head = nullptr;
}

//check
template<class T>
LinkedList<T>::LinkedList(T *data, int length) : LinkedList() {
    try {
        if (length < 0) {
            throw "LENGTH_NEGATIVE!";
        } for (int i = 0; i < length; i++)
            PushBack(data[i]);
    } catch (const char *error) {
        std::cout << error << std::endl;
    }
}

//ok
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) : LinkedList() {
    Node *node = list.head;
    for (int i = 0; i < list.length; i++) {
        PushBack(node->data);
        node = node->pNext;
    }
}

//ok
template<class T>
T &LinkedList<T>::GetFront() const {
    try {
        if (!length)
            throw "EMPTY_LIST!";
        T &front = head->data;
        return front;
    }  catch (const char* error) {
        std::cout << error << std::endl;
    }
}

//ok
template<class T>
T &LinkedList<T>::GetBack() const {
    try {
        if (!length)
            throw "EMPTY_LIST!";
        Node *node = head;
        for (int i = 0; i < length; i++) {
            node = node->pNext;
        }
        T &back = node->data;
        return back;
    } catch (const char* error) {
        std::cout << error << std::endl;
    }
}

//ok
template<class T>
T &LinkedList<T>::GetByIndex(int index) const {
    try {
        if (index >= length || index < 0)
            throw "INDEX_OUT_OF_RANGE!";
        Node *node = head;
        for (int i = 0; i < index; ++i) {
            node = node->pNext;
        }
        T &value = node->data;
        return value;
    } catch (const char* error) {
        std::cout << error << std::endl;
    }
}


//template<class T>
//void LinkedList<T>::PopFront() {
//    try {
//        if (!this->length)
//            throw "EMPTY LIST!";
//        Node* del_node = this->head;
//        this->head = this->head->pNext;
//        delete del_node;
//        --this->length;
//    }  catch (const char* error) {
//        std::cout << error << std::endl;
//    }
//}

//template<class T>
//void LinkedList<T>::PopBack() {
//    try {
//        if (!this->length)
//            throw "EMPTY LIST!";
//        Node* node = this->head;
//        for (int i = 0; i < this->length - 1; ++i) node = node->pNext;
//        Node* del_node = node->pNext;
//        node->pNext = nullptr;
//        delete del_node;
//        --this->length;
//    }  catch (const char* error) {
//        std::cout << error << std::endl;
//    }
//}

//check
template<class T>
void LinkedList<T>::Clear() {
    while (length)
        DelByIndex(0); //0 or 1 or the last????
}

//ok rewrite
template<class T>
void LinkedList<T>::DelByIndex(int index) {
    try {
        if (index < 0 || index >= length)
            throw "INDEX_OUT_OF_RANGE!";
        if (!index) {
            Node *n_del = head;
            head = head->pNext;
            delete n_del;
            length--;
            return;
        }
        Node *n = head;
        for (int i = 1; i < index; ++i) {
            n = n->pNext;
        }
        Node *n_del = n->pNext;
        n->pNext = n->pNext->pNext;
        delete n_del;
        length--;
    }  catch (const char *error) {
        std::cout << error << std::endl;
    }
}

//ok but check this->GetByIndex(i) can we delete this-> ???
template<class T>
LinkedList<T> *LinkedList<T>::GetSubList(int start, int end) const {
    try {
        if (start < 0 || start >= length || end < 0 || end > length)
            throw "INDEX_OUT_OF_RANGE!";
        if (start > end)
            std::swap(start, end);
        LinkedList<T> *list = new LinkedList<T>;
        for (int i = start; i < end; ++i)
            (*list).PushBack(this->GetByIndex(i));
        return list;
    }  catch (const char* error) {
        std::cout << error << std::endl;
    }
}

//ok
template<class T>
int LinkedList<T>::GetLength() const {
    return length;
}

//check!!!
template<class T>
void LinkedList<T>::PushFront(const T &data) {
    Node* nNode = new Node;
    *nNode = Node(data); //??????
    if (!length) {
        head = nNode;
        length++;
        return;
    }
    nNode->pNext = head;
    head = nNode;
}

//ok maybe rewrite?
template<class T>
void LinkedList<T>::PushBack(const T &data) {
    Node* nNode = new Node;
    nNode->data = data;
    nNode->pNext = nullptr;
    if (!length) {
        head = nNode;
        length++;
        return;
    }
    Node *node = head;
    for(int i = 0; i < length - 1; ++i) {
        node = node->pNext;
    }
    node->pNext = nNode;
    length++;
}

//ok but research
template<class T>
void LinkedList<T>::InsertAt(const T &data, int index) {
    try {
        if (index < 0 || index > length)
            throw "INDEX_OUT_OF_RANGE!";
        if (!index) {
            PushFront(data);
            return;
        }
        if (index == length) {
            PushBack(data);
            return;
        }
        Node* node = head;
        for (int i = 0; i < index - 1; ++i) {
            node = node->pNext;
        }
        Node* nNode = new Node;
        *nNode = Node(data, node->pNext);
        node->pNext = nNode;
        length++;
    }  catch (const char* error) {
        std::cout << error << std::endl;
    }
}

//ok
template<class T>
void LinkedList<T>::Set(const T &data, int index) {
    try {
        if (index < 0 || index > length)
            throw "INDEX_OUT_OF_RANGE!";
        if (index == length) {
            PushBack(data);
            return;
        }
        Node* node = head;
        for (int i = 0; i < index; ++i) {
            node = node->pNext;
        }
        node->data = data;
    }  catch (const char* error) {
        std::cout << error << std::endl;
    }
}

//ok
template<class T>
LinkedList<T> *LinkedList<T>::Concat(LinkedList<T> *list) const {
    try {
        if (list == nullptr)
            throw "INVALID_LIST!";
        LinkedList* nList = new LinkedList;
        for (int i = 0; i < GetLength(); ++i) {
            nList->PushBack(GetByIndex(i));
        }
        for (int i = 0; i < list->GetLength(); ++i) {
            nList->PushBack(list->GetByIndex(i));
        }
        return nList;
    }  catch (const char *error) {
        std::cout << error << std::endl;
    }
}

template<typename T>
T& LinkedList<T>::operator[](int index) {
    try {
        if (index <0 || index > length - 1) {
            throw "INDEX_OUT_OF_RANGE!";
        }
        Node *temp = head;
        for (int i=0; i<index; i++) {
            temp = temp->pNext;
        }
        return temp->data;
    } catch (const char *error) {
        std::cout << error << std::endl;
    }
}

template<class T>
LinkedList<T>::~LinkedList() {
    Clear();
}

