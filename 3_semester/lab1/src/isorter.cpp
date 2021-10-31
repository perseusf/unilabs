#include "isorter.h"
#include "arraysequence.cpp"
#include "listsequence.cpp"

template <class T>
Sequence<T>* BubbleSort<T>::Sort(Sequence<T> *seq, int (*cmp)(T, T)) {
    for (int i = 0; i < seq->GetLength() - 1; i++)
        for (int k = 0; k < seq->GetLength() - i - 1; k++)
            if (cmp((*seq)[k], (*seq)[k + 1]) > 0) seq->Swap((*seq)[k], (*seq)[k + 1]);
    return seq;
}

template <class T>
Sequence<T>* SelectionSort<T>::Sort(Sequence<T> *seq, int (*cmp)(T, T)) {
    for (int i = 0; i < seq->GetLength() - 1; i++) {
        T min = (*seq)[i];
        int min_id = i;
        for (int k = i + 1; k < seq->GetLength(); k++) {
            if (cmp((*seq)[k], (*seq)[min_id]) < 0) {
                min_id = k;
            }
        }
        if (i != min_id) {
            seq->Swap((*seq)[i], (*seq)[min_id]);
        }
    }
    return seq;
}

template <class T>
Sequence<T>* InsertionSort<T>::Sort(Sequence<T> *seq, int (*cmp)(T, T)) {
    int key, k;
    for (int i = 1; i < seq->GetLength(); i++) {
        key = (*seq)[i];
        k = i - 1;
        while (k >= 0 && (cmp((*seq)[k], key) > 0)) {
            (*seq)[k + 1] = (*seq)[k];
            k = k - 1;
        }
        (*seq)[k + 1] = key;
    }
    return seq;
}

template <class T>
Sequence<T>* MergeSort<T>::merge(Sequence<T> *seq, int left, int middle, int right, int (*cmp)(T, T)) {
    int seq1_start = left;
    int seq2_start = middle + 1;
    Sequence<T> *seq_temp = (Sequence<T> *) new ArraySequence<T>;

    while (seq1_start <= middle && seq2_start <= right) {
        if (cmp((*seq)[seq1_start], (*seq)[seq2_start]) < 0){
            seq_temp->Append((*seq)[seq1_start]);
            seq1_start++;
        } else {
            seq_temp->Append((*seq)[seq2_start]);
            seq2_start++;
        }
    }

    while (seq2_start <= right) {
        seq_temp->Append((*seq)[seq2_start]);
        seq2_start++;
    }
    while (seq1_start <= middle) {
        seq_temp->Append((*seq)[seq1_start]);
        seq1_start++;
    }

    for (int i = 0; i < seq_temp->GetLength(); i++)
        (*seq)[left + i] = (*seq_temp)[i];
    return seq;
}

template <class T>
Sequence<T>* MergeSort<T>::mergesort(Sequence<T> *seq, int left, int right, int (*cmp)(T, T)) {
    int middle;
    if (left < right) {
        middle = (left + right) / 2;
        mergesort(seq, left, middle, cmp);
        mergesort(seq, middle + 1, right, cmp);
        merge(seq, left, middle, right, cmp);
    }
    return seq;
}

template<typename T>
Sequence<T>* MergeSort<T>::Sort(Sequence<T> *seq, int (*cmp)(T, T)) {
    return mergesort(seq, 0, seq->GetLength() - 1, cmp);
}

template <class T>
int QuickSort<T>::partition(Sequence<T> *seq, int low, int high, int (*cmp)(T, T)) {
    int pivot = (*seq)[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (cmp((*seq)[j], pivot) <= 0) {
            i++; // increment index of smaller element
            seq->Swap((*seq)[i], (*seq)[j]);
        }
    }
    seq->Swap((*seq)[i + 1], (*seq)[high]);
    return (i + 1);
}

template <class T>
void QuickSort<T>::quicksort(Sequence<T> *seq, int low, int high, int (*cmp)(T, T)) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(seq, low, high, cmp);

        // Separately sort elements before
        // partition and after partition
        quicksort(seq, low, pi - 1, cmp);
        quicksort(seq, pi + 1, high, cmp);
    }
}

template <class T>
Sequence<T>* QuickSort<T>::Sort(Sequence<T> *seq, int (*cmp)(T, T)) {
    quicksort(seq, 0, seq->GetLength() - 1, cmp);
    return seq;
}

template <class T>
Sequence<T>* ShellSort<T>::Sort(Sequence<T> *seq, int (*cmp)(T, T)) {
    int tmp, k;
    int seq_len = seq->GetLength();
    for (int step = seq_len / 2; step > 0; step /= 2){
        for (int i = step; i < seq_len; i++) {
            tmp = (*seq)[i];
            for (k = i; k >= step; k -= step) {
                if (tmp < (*seq)[k - step])
                    (*seq)[k] = (*seq)[k - step];
                else
                    break;
            }
            (*seq)[k] = tmp;
        }
    }
    return seq;
}