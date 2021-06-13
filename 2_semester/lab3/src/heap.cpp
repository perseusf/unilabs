#include "heap.h"
#include "sequence.h"
#include "extra.h"
#include <cmath>
using namespace std;

template<class T>
Heap<T>::Heap() {
    _heap = (Sequence<T> *) new ArraySequence<T>;
}

template<class T>
Heap<T>::Heap(const Sequence<T> &seq) {
    *_heap = seq;
    if (seq.GetLength() == 0)
        return;
    for (int i = seq.GetLength(); i >= 0; --i) {
        siftDown(i);
    }
}

template<class T>
Heap<T>::Heap(Heap<T> &heap) {
    _heap = (Sequence<T> *) new ArraySequence<T>;
    for (int i = 0; i < heap.GetLength(); ++i) {
        _heap->Append(heap[i]);
    }
}

template<class T>
void Heap<T>::siftUp (int index) {
    if (index >= _heap->GetLength() || index < 0)
        throw std::out_of_range("from Heap<T>::siftUp(int index)");
    int parrent = (index - 1) / 2;
    while ((index > 0) && ((*_heap)[index] < (*_heap)[parrent])) {
        std::swap((*_heap)[index], (*_heap)[parrent]);
        index = parrent;
        parrent = (index - 1) / 2;
    }
}

template<class T>
void Heap<T>::siftDown(int index) {
    if (index >= _heap->GetLength() || index < 0)
        throw std::out_of_range("from Heap<T>::siftDown(int index)");
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int minChild = left;
    while (left < _heap->GetLength()) {
        if (right < _heap->GetLength() && (*_heap)[left] > (*_heap)[right])
            minChild = right;
        if ((*_heap)[index] <= (*_heap)[minChild])
            return;
        std::swap((*_heap)[index], (*_heap)[minChild]);
        index = minChild;
        left = 2 * index + 1;
        right = 2 * index + 2;
        minChild = left;
    }
}

template<class T>
void Heap<T>::clear() {
    while (_heap->GetLength() != 0)
        delMin();
}

template<class T>
int Heap<T>::GetLength() const {
    return _heap->GetLength();
}

template<class T>
int Heap<T>::Getheight() const {
    int len = GetLength();
    if (!len) return 0;
    int h = 1;
    int min = 1;
    int max = 1;
    while (true) {
        if (min <= len && max >= len) return h;
        ++h;
        min *= 2;
        max += min;
    }
}

template<class T>
void Heap<T>::insert(T &value) {
    _heap->Append(value);
    siftUp(_heap->GetLength() - 1);
}

template<class T>
T &Heap<T>::getMin() {
    if (_heap->GetLength() == 0)
        throw std::out_of_range("from Heap<T>::ExtractMin()");
    return (*_heap)[0];
}

template<class T>
T &Heap<T>::getByIndex(int index) {
    if (index >= _heap->GetLength() || index < 0)
        throw std::out_of_range("from Heap<T>::getByIndex(int index)");
    return (*_heap)[index];
}

template<class T>
int Heap<T>::getElementIndex(T &value) {
    int index = -1;
    for (int i = 0; i < _heap->GetLength(); ++i) {
        if ((*_heap)[i] == value) {
            index = i;
            break;
        }
    }
    return index;
}

template<class T>
void Heap<T>::setByIndex(int index, T &value) {
    _heap->Set(index, value);
}

template<class T>
T &Heap<T>::operator [](const int index) {
    if (index >= _heap->GetLength() || index < 0)
        throw std::out_of_range("from Heap<T>::operator[](const int index)");
    return (*_heap)[index];
}

template<class T>
bool Heap<T>::checkEntry(T &value) {
    if (_heap->GetLength() == 0) return false;
    for (int i = 0; i < _heap->GetLength(); ++i) {
        if ((*_heap)[i] == value) return true;
    }
    return false;
}

template<class T>
void Heap<T>::delMin() {
    if (_heap->GetLength() == 0)
        throw std::out_of_range("from Heap<T>::ExtractMax()");
    (*_heap)[0] = (*_heap)[_heap->GetLength() - 1];
    siftDown(0);
    _heap->DelByIndex(_heap->GetLength() - 1);
}

template<class T>
void Heap<T>::delByValue(T &value) {
    if (!checkEntry(value)) return;
    int index = 0;
    for (int i = 0; i < _heap->GetLength(); ++i) {
        if ((*_heap)[i] == value) index = i;
    }
    (*_heap)[index] = (*_heap)[0];
    siftUp(index);
    delMin();
}

template<class T>
void Heap<T>::delRepeat() {
    int *len = new int;
    *len = GetLength();
    for (int i = 0; i < *len; ++i) {
        for (int j = 0; j < *len; ++j) {
            if ((*_heap)[i] == (*_heap)[j] && i != j) {
                (*_heap)[j] = (*_heap)[0];
                siftUp(j);
                delMin();
                *len = GetLength();
                i = 0;
            }
        }
    }
    delete len;
}

template<class T>
string toString(T &value) {
    return "{ " + to_string(value) + " }";
}

template<class T>
string toString(T &value1, T& value2) {
    return "{ " + to_string(value1) + "; " + to_string(value2) + " }";
}

template<class T>
std::string Heap<T>::SavePairsInString() {
    if (_heap->GetLength() == 0) return "";
    std::string pairs = "";
    for (int i = 1; i < _heap->GetLength() ; ++i) {
        int parrent = (i - 1) / 2;
        pairs += toString((*_heap)[parrent], (*_heap)[i]) + " ";
    }
    return pairs;
}

template<class T>
Sequence<int>* Heap<T>::extractSubHeapIndex(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    Sequence<int>* subHeapIndex = (Sequence<int>*) new ArraySequence<int>();
    if (index < this->GetLength()) subHeapIndex->Append(index);
    if (left >= this->GetLength()) {
        return subHeapIndex;
    }
    subHeapIndex = subHeapIndex->Concat(extractSubHeapIndex(left));
    if (right < this->GetLength()) subHeapIndex = subHeapIndex->Concat(extractSubHeapIndex(right));
    subHeapIndex->Sort();
    return subHeapIndex;
}

template<class T>
Heap<T> *Heap<T>::extractSubHeap(int index) {
    Heap<T> *h = new Heap<T>;
    Sequence<int>* subHeapIndex = extractSubHeapIndex(index);
    for(int i = 0; i < subHeapIndex->GetLength(); ++i) {
        h->insert(this->operator[]((*subHeapIndex)[i]));
    }
    return h;
}

template<class T>
std::ostream& operator << (std::ostream &out, const Heap<T> &h) {
    string first = to_string((*h._heap)[0]);
    int mode = 0;
    for (int i = 0; i < h.GetLength(); ++i) {
        string element = to_string((*h._heap)[i]);
        if (element.length() > 8) mode = 1;
    }
    if (!mode) {
        for (int i = 0; i < h.Getheight(); ++i) {
            if (!i) {
                for (int j = 0; j < pow(2, (h.Getheight() - 1))  / 2 - 1; ++j) {
                    out << "\t";
                }
                out << "    " << (*h._heap)[0] << "\n\n";
                for (int k = 0; k < (int)first.length() / 2; ++k) {
                    out << " ";
                }
            }
            else {
                for (int j = 0; j < pow(2, (h.Getheight() - 1))  / 2 - pow(2, i - 1); ++j) {
                    out << "\t";
                }
                int num = pow(2, i);
                if (i == h.Getheight() - 1) {
                    int diff = 0;
                    for (int l = 0; l < i; ++l) {
                        diff += pow(2, l);
                    }
                    num = h.GetLength() - diff;
                }
                for (int k = 0; k < num; ++k) {
                    out << (*h._heap)[pow(2,i) + k - 1] << "\t";
                }
                if (i != h.Getheight() - 1) out << "\n\n";
            }
        }
        return out;
    }
    else {
        for (int i = 0; i < h.GetLength(); ++i) {
                out << (*h._heap)[i];
                if (i != h.GetLength() - 1)
                    out << ", ";
            }
            return out;
    }

}

template<class T>
Heap<T>::~Heap() {
    clear();
}
