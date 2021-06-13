#include "set.h"

using namespace std;

template<class T>
Set<T>::Set() {
    _elements = new Heap<T>;
}

template<class T>
Set<T>::Set(const Sequence<T> &seq) {
    _elements = new Heap<T>(seq);
    _elements->delRepeat();;
}

template<class T>
Set<T>::Set(const Set<T> &set) {
    _elements = new Heap<T>(*set._elements);
    _elements->delRepeat();
}

template<class T>
Set<T>::Set(Heap<T> *heap) {
    _elements = new Heap<T>(*heap);
}

template<class T>
void Set<T>::clear() {
    _elements->clear();
}

template<class T>
int Set<T>::GetLength() const {
    return _elements->GetLength();
}

template<class T>
void Set<T>::insert(T &value) {
    if (!(_elements->checkEntry(value))) {
        _elements->insert(value);
        _elements->delRepeat();
    }
}

template<class T>
void Set<T>::insertRepeat(T &value) {
    if (!(_elements->checkEntry(value))) {
        _elements->insert(value);
    }
}

template<class T>
T &Set<T>::getMin() {
    return _elements->getMin();
}

template<class T>
bool Set<T>::checkEntry(T &value) {
    return _elements->checkEntry(value);
}

template<class T>
void Set<T>::delByValue(T &value) {
    if (_elements->checkEntry(value))
        _elements->delByValue(value);
}

template<class T>
string Set<T>::SaveInString() {
    if (_elements->GetLength() == 0) return "";
    string str = "";
    for(int i = 0; i < _elements->GetLength(); ++i) {
        str += to_string((*_elements)[i]);
        if (i != _elements->GetLength() - 1)
            str += ", ";
    }
    return str;
}

template<class T>
Set<T> Set<T>::operator + (const Set<T> &other) {
    Set<T>* Union = new Set<T>(_elements);
    for (int i = 0; i < other.GetLength(); ++i) {
        Union->insert((*other._elements)[i]);
    }
    return *Union;
}

template<class T>
Set<T> Set<T>::operator * (const Set<T> &other) {
    Set<T>* Intersection = new Set<T>;
    for (int i = 0; i < other.GetLength(); ++i) {
        if (checkEntry((*other._elements)[i])) {
            Intersection->insertRepeat((*other._elements)[i]);
        }
    }
    return *Intersection;
}

template<class T>
Set<T> Set<T>::operator - (const Set<T> &other) {
    Set<T>* Complement = new Set<T>(_elements);
    for (int i = 0; i < other.GetLength(); ++i) {
        Complement->delByValue((*other._elements)[i]);
    }
    return *Complement;
}

template<class T>
bool Set<T>::operator == (const Set<T> &other) {
    if (GetLength() != other.GetLength()) return false;
    for (int i = 0; i < GetLength(); ++i) {
        if (!checkEntry((*other._elements)[i])) return false;
    }
    return true;
}

template<class T>
bool Set<T>::operator != (const Set<T> &other) {
    if (GetLength() != other.GetLength()) return true;
    for (int i = 0; i < GetLength(); ++i) {
        if (!checkEntry((*other._elements)[i])) return true;
    }
    return false;
}

template<class T>
bool Set<T>::checkSubSet (Set *set) {
    if (GetLength() < set->GetLength()) return false;
    for (int i = 0; i < set->GetLength(); ++i) {
        if (!checkEntry((*set->_elements)[i])) return false;
    }
    return true;
}

template<class T>
std::ostream& operator << (std::ostream &out, const Set<T> &s) {
    out << "{ ";
    for (int i = 0; i < s.GetLength(); ++i) {
            out << (*s._elements)[i];
            if (i != s.GetLength() - 1)  out << ", ";
        }
    out << " }";
    return out;
}

template<class T>
Set<T>::~Set() {
    clear();
    _elements->~Heap<T>();
}
