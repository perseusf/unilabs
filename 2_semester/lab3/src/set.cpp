#include "set.h"
using namespace std;

template<class T>
Set<T>::Set() {
    data_ = new Heap<T>;
}

template<class T>
Set<T>::Set(const Sequence<T> &sequence) {
    data_ = new Heap<T>(sequence);
    data_->DeleteRepeated();;
}

template<class T>
Set<T>::Set(const Set<T> &set) {
    data_ = new Heap<T>(*set.data_);
    data_->DeleteRepeated();
}

template<class T>
Set<T>::Set(Heap<T> heap) {
    data_ = new Heap<T>(heap);
}

template<class T>
Heap<T> *Set<T>::GetHeap() {
    return data_;
}

template<class T>
int Set<T>::GetSize() const {
    return data_->GetLength();
}

template<class T>
void Set<T>::insert(T val) {
    if (!(data_->Find(val))) {
        data_->insert(val);
    }
}

template<class T>
T &Set<T>::GetMin() {
    return data_->GetMinimum();
}

template<class T>
T &Set<T>::GetMax() {
    return data_->GetMaximum();
}

template<class T>
bool Set<T>::Find(T &val) {
    return data_->Find(val);
}

template<class T>
void Set<T>::DeleteValue(T &val) {
    if (data_->Find(val))
        data_->DeleteByValue(val);
}


template<class T>
bool Set<T>::operator==(const Set<T> &set) {
    int setlen = set.GetSize();
    if (GetSize() != setlen)
        return false;
    for (int i = 0; i < GetSize(); ++i) {
        if (!Find((*set.data_)[i]))
            return false;
    }
    return true;
}

template<class T>
bool Set<T>::operator!=(const Set<T> &set) {
    int setlen = set.GetSize();
    if (GetSize() != setlen)
        return true;
    for (int i = 0; i < GetSize(); ++i) {
        if (!Find((*set.data_)[i]))
            return true;
    }
    return false;
}

template<class T>
Set<T> Set<T>::operator+(const Set<T> &set) {
    int setlen = set.GetSize();
    Set<T> Union(*data_);
    for (int i = 0; i < setlen; ++i) {
        Union.insert((*set.data_)[i]);
    }
    return Union;
}

template<class T>
Set<T> Set<T>::operator*(const Set<T> &set) {
    int setlen = set.GetSize();
    Set<T> Intersection;
    for (int i = 0; i < setlen; i++) {
        if (Find((*set.data_)[i])) {
            Intersection.insert((*set.data_)[i]);
        }
    }
    return Intersection;
}

template<class T>
Set<T> Set<T>::operator-(const Set<T> &set) {
    int setlen = set.GetSize();
    Set<T> Complement(*data_);
    for (int i = 0; i < setlen; i++) {
        Complement.DeleteValue((*set.data_)[i]);
    }
    return Complement;
}

template<class T>
bool Set<T>::FindSubSet(Set set) {
    int setlen = set.GetSize();
    if (GetSize() < setlen)
        return false;
    for (int i = 0; i < setlen; i++) {
        if (!Find((set.data_)[i]))
            return false;
    }
    return true;
}

template<class U>
std::ostream& operator<<(std::ostream &out, const Set<U> &settoprint) {
    int setlen = settoprint.GetSize();
    for (int i = 0; i < setlen; i++) {
            out << (*settoprint.data_)[i];
            if (i != setlen - 1)
                out << ", ";
        }
    return out;
}

template<class T>
void Set<T>::Clear() {
    data_->clear();
}

template<class T>
Set<T>::~Set() {
    Clear();
    data_->~Heap<T>();
}
