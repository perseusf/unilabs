#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList{
private:
    class Node {
    public:
        T data;
        Node *pNext;
        explicit Node(T data = T(), Node *pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };
    Node *head_;
    int length_;
public:
    //constructors
    LinkedList();
    LinkedList(T *data, int length);
    LinkedList(const LinkedList <T> &list);

    //decomposition
    T& GetFront() const;
    T& GetBack() const;
    T& Get(int index) const;
    void PopFront();
    void PopBack();
    void DelByIndex(int index);
    void Clear();
    LinkedList<T>* GetSubList (int start, int end) const;
    [[nodiscard]] int GetLength () const;

    //operations
    void PushFront(const T &data);
    void PushBack(const T &data);
    void InsertAt(const T &data, int index);
    void Set(int index, const T &data);
    LinkedList<T>* Concat(LinkedList<T> *list) const;

    //operators
    T& operator[](int index);

    //destructor
    ~LinkedList();
};

#endif // LINKEDLIST_H
