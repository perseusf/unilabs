#ifndef SET_H
#define SET_H
#include "heap.h"

template<class T>
class Set {
    Heap<T> *data_;

public:
    //constructors
    Set();
    explicit Set(const Sequence<T> &sequence);
    Set(const Set<T> &set);
    explicit Set(Heap<T> heap);

    //decomposition
    Heap<T> *GetHeap();
    [[nodiscard]] int GetSize() const;
    void insert(T val);
    T &GetMin();
    T &GetMax();
    bool Find(T &val);
    bool FindSubSet(Set set);
    void DeleteValue(T &val);

    //operators and operations
    bool operator==(const Set<T> &set);
    template<class U>
    friend std::ostream& operator<<(std::ostream &out, const Set<U> &settoprint);
    Set<T> operator+(const Set<T> &set);
    Set<T> operator*(const Set<T> &set);
    Set<T> operator-(const Set<T> &set);

    //destructors
    void Clear();
    ~Set();
};
#endif // SET_H
