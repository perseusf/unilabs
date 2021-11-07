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
int QuickSort<T>::split(Sequence<T> *seq, int start, int end, int (*cmp)(T, T)) {
    int pivot = (*seq)[end]; //с одинаковой вероятностью, что элемент будет стоять в середине
    int i = (start - 1); //индекс элемента который больше пивота, отслеживаем
    for (int j = start; j <= end - 1; j++) {
        if (cmp((*seq)[j], pivot) <= 0) {
            i++;
            seq->Swap((*seq)[i], (*seq)[j]);
        }
    }
    //меняем пивот(end) с первым большим элементом(i+1)
    seq->Swap((*seq)[i + 1], (*seq)[end]);
    return (i + 1);
}

template <class T>
void QuickSort<T>::quicksort(Sequence<T> *seq, int start, int end, int (*cmp)(T, T)) {
    if (start < end) {
        int pivot = split(seq, start, end, cmp);
        quicksort(seq, start, pivot - 1, cmp); //левая часть
        quicksort(seq, pivot + 1, end, cmp); //правая часть
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
    //рассматриваем элементы на расстоянии gap друг от друга и уменьшаем его вдвое каждый раз
    for (int gap = seq_len / 2; gap > 0; gap /= 2){
        for (int i = gap; i < seq_len; i++) {
            //копируем в tmp текущий элемент
            tmp = (*seq)[i];
            for (k = i; k >= gap; k -= gap) {
                //сравниваем элементы на расстоянии gap друг от друга
                if (cmp(tmp, (*seq)[k - gap]) < 0)
                    (*seq)[k] = (*seq)[k - gap];
                else
                    break;
            }
            (*seq)[k] = tmp;
        }
    }
    return seq;
}