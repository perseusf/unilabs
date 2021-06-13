#include "heap.h"
#include "sequence.h"
#include "functions.h"
#include <cmath>
using namespace std;

template<class T>
Heap<T>::Heap() {
    heapdata_ = (Sequence<T>*) new ArraySequence<T>;
}

template<class T>
Heap<T>::Heap(const Sequence<T> &sequence) {
    *heapdata_ = sequence;
    int lenofsequence = sequence.GetLength();
    if (lenofsequence == 0)
        return;
    for (int i = lenofsequence; i >= 0; i--) {
        DrownDown(i);
    }
}

template<class T>
Heap<T>::Heap(Heap<T> &heap) {
    int heaplen = heap.GetLength();
    heapdata_ = (Sequence<T>*) new ArraySequence<T>;
    for (int i = 0; i < heaplen; i++) {
        heapdata_->Append(heap[i]);
    }
}

template<class T>
void Heap<T>::FloatTop (int index) {
    int parent = (index - 1) / 2;
    while ((index > 0) && ((*heapdata_)[index] < (*heapdata_)[parent])) {
        std::swap((*heapdata_)[index], (*heapdata_)[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

template<class T>
void Heap<T>::DrownDown(int index) {
    int heaplen = heapdata_->GetLength();
    if (index >= heaplen || index < 0)
        throw std::out_of_range("DrownDown(int index)");
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int minChild = left;
    while (left < heaplen) {
        if (right < heaplen && (*heapdata_)[left] > (*heapdata_)[right])
            minChild = right;
        if ((*heapdata_)[index] <= (*heapdata_)[minChild])
            return;
        std::swap((*heapdata_)[index], (*heapdata_)[minChild]);
        index = minChild;
        left = 2 * index + 1;
        right = 2 * index + 2;
        minChild = left;
    }
}

template<class T>
void Heap<T>::clear() {
    while (heapdata_->GetLength() != 0)
        DeleteMinimum();
}

template<class T>
int Heap<T>::GetLength() const {
    return heapdata_->GetLength();
}

template<class T>
void Heap<T>::insert(T &value) {
    heapdata_->Append(value);
    int heaplen = heapdata_->GetLength();
    FloatTop(heaplen - 1);
}

template<class T>
T &Heap<T>::GetMinimum() {
    int heaplen = heapdata_->GetLength();
    if (heaplen == 0)
        throw std::out_of_range("GetMinimum()");
    return (*heapdata_)[0];
}

template<class T>
T &Heap<T>::GetMaximum() {
    int heaplen = heapdata_->GetLength();
    if (heaplen == 0)
        throw std::out_of_range("GetMaximum()");
    return (*heapdata_)[heaplen];
}

template<class T>
T &Heap<T>::GetElemByIndex(int index) {
    int heaplen = heapdata_->GetLength();
    if (index >= heaplen || index < 0)
        throw std::out_of_range("GetElemByIndex(int index)");
    return (*heapdata_)[index];
}

template<class T>
int Heap<T>::GetIndexByElem(T &value) {
    int index = -1;
    int heaplen = heapdata_->GetLength();
    for (int i = 0; i < heaplen; ++i) {
        if ((*heapdata_)[i] == value) {
            index = i;
            break;
        }
    }
    return index;
}

template<class T>
void Heap<T>::SetElemByIndex(int index, T &value) {
    heapdata_->Set(index, value);
}

template<class T>
T &Heap<T>::operator [](const int indextoget) {
    return (*heapdata_)[indextoget];
}

template<class T>
Heap<T> &Heap<T>::operator=(Heap<T>& heaptocopy) {
    heapdata_ = heaptocopy.heapdata_;
    return *this;
}

template<class T>
bool Heap<T>::Find(T &value) {
    int heaplen = heapdata_->GetLength();
    if (heaplen == 0) return false;
    for (int i = 0; i < heaplen; ++i) {
        if ((*heapdata_)[i] == value)
            return true;
    }
    return false;
}

template<class T>
void Heap<T>::DeleteMinimum() {
    if (heapdata_->GetLength() == 0)
        throw std::out_of_range("DeleteMinimum()");
    (*heapdata_)[0] = (*heapdata_)[heapdata_->GetLength() - 1];
    DrownDown(0);
    heapdata_->DelByIndex(heapdata_->GetLength() - 1);
}

template<class T>
void Heap<T>::DeleteByValue(T &value) {
    int heaplen = heapdata_->GetLength();
    if (!Find(value)) return;
    int index = 0;
    for (int i = 0; i < heaplen; ++i) {
        if ((*heapdata_)[i] == value)
            index = i;
    }
    (*heapdata_)[index] = (*heapdata_)[0];
    FloatTop(index);
    DeleteMinimum();
}

template<class T>
void Heap<T>::DeleteRepeated() {
    int heaplen;
    heaplen = GetLength();
    for (int i = 0; i < heaplen; ++i) {
        for (int j = 0; j < heaplen; ++j) {
            if ((*heapdata_)[i] == (*heapdata_)[j] && i != j) {
                (*heapdata_)[j] = (*heapdata_)[0];
                FloatTop(j);
                DeleteMinimum();
                heaplen = GetLength();
                i = 0;
            }
        }
    }
}

template<class T>
Sequence<int>* Heap<T>::GetIndexOfSubHeap(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    Sequence<int>* subHeapIndex = (Sequence<int>*) new ArraySequence<int>();
    if (index < this->GetLength()) subHeapIndex->Append(index);
    if (left >= this->GetLength()) {
        return subHeapIndex;
    }
    subHeapIndex = subHeapIndex->Concat(GetIndexOfSubHeap(left));
    if (right < this->GetLength()) subHeapIndex = subHeapIndex->Concat(GetIndexOfSubHeap(right));
    subHeapIndex->Sort();
    return subHeapIndex;
}

//returns pointer to the subheap
template<class T>
Heap<T> *Heap<T>::GetSubHeap(int index) {
    Heap<T> *resultingheap = new Heap<T>;
    Sequence<int>* indexofsubheap = GetIndexOfSubHeap(index);
    for(int i = 0; i < indexofsubheap->GetLength(); i++) {
        resultingheap->insert(this->operator[]((*indexofsubheap)[i]));
    }
    return resultingheap;
}

//print
template<class T>
std::ostream& operator<<(std::ostream &out, const Heap<T> &heaptoprint) {
    for (int i = 0; i < heaptoprint.GetLength(); ++i) {
        out << (*heaptoprint.heapdata_)[i];
        if (i != heaptoprint.GetLength() - 1)
            out << ", ";
    }
    return out;
}

//destructor
template<class T>
Heap<T>::~Heap() {
    clear();
}
