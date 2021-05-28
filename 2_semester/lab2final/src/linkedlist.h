#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList {
private:
    class Node {
    public:
        T data;
        Node *pNext;
        Node(T data = T(), Node *pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };
    Node *head;
    int length;
public:
    //Constructors
    LinkedList();
    LinkedList(T* data, int length);
    LinkedList(const LinkedList <T> &list);

    //Decomposition
    T& GetFront() const;
    T& GetBack() const;
    T& GetByIndex(int index) const;
//    void PopFront();
//    void PopBack();
    void DelByIndex(int index);
    void Clear();
    LinkedList<T>* GetSubList(int start, int end) const;
    int GetLength() const;

    //Operations
    void PushFront(const T& data);
    void PushBack(const T& data);
    void InsertAt(const T& data, int index);
    void Set(const T& data, int index);
    LinkedList<T>* Concat(LinkedList<T> *list) const;

    //OPERATORS
    T& operator[](int index);

    //Destructor
    ~LinkedList();
};

#endif // LINKEDLIST_H
