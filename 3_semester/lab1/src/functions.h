#ifndef LAB1_FUNCTIONS_H
#define LAB1_FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <chrono>
#include "isorter.h"
#include "isorter.cpp"

template <typename T>
int cmp(T a, T b) {
    int result = 0;
    if (a < b) {
        result = -1;
    } else if (a > b) {
        result = 1;
    }
    return result;
}

template <class T>
void generateRandom(Sequence<T> *seq, int seq_len, int maxValue) {
    srand(time(nullptr));
    for (int i = 0; i < seq_len; i++)
        seq->Append(std::rand() % maxValue);
}

template <class T>
void generateRandomDouble(Sequence<T> *seq, int seq_len, int maxValue) {
    srand(time(nullptr));
    for (int i = 0; i < seq_len; i++) {
        double a = (double)std::rand() / maxValue;
        seq->Append(a);
    }
}

template <class T>
void generateRandomChar(Sequence<T> *seq, int seq_len) {
    srand(time(nullptr));
    for (int i = 0; i < seq_len; i++) {
        int r = std::rand() % 26;
        char a = 'a' + r;
        seq->Append(a);
    }
}

template <class T>
void generateWorstCase(Sequence<T> *seq, int seq_len) {
    for (int i = 0; i < seq_len; i++) {
        seq->Append(seq_len - i - 1);
    }
}

template <class T>
void generateBestCase(Sequence<T> *seq, int seq_len) {
    for (int i = 0; i < seq_len; ++i) {
        seq->Append(i);
    }
}

template <class T>
bool isSorted(Sequence<T>* seq, int (*cmp)(T, T)) {
    int counter = 0;
    for (int i = 0; i < seq->GetLength() - 1; i++) {
        if (cmp((*seq)[i], (*seq)[i + 1]) <= 0) counter++;
    }
    if (counter == (seq->GetLength() - 1)) {
        return true;
    } else {
        return false;
    }
}

template <class T>
void exportTXT(Sequence<T> *seq, int (*cmp)(T, T), const std::string& sort_name) {
    std::ofstream file;
    file.open("sorts/" + sort_name + ".txt");
    if (file.is_open()) {
        file << "Unsorted array: ";
        for (int i = 0; i < seq->GetLength(); ++i)
            file << (*seq)[i] << " ";
    }
    file << std::endl;

    if ((sort_name == "arrayBubbleSort") || (sort_name == "listBubbleSort")) {
        BubbleSort<int> Sorter;
        auto time1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto time2 = std::chrono::high_resolution_clock::now();
        if (file.is_open()) {
            file << "Sorted array: ";
            for (int i = 0; i < seq->GetLength(); ++i)
                file << (*seq)[i] << " ";
        }
        file << std::endl << "Number of elements: " << seq->GetLength() << std::endl;
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        if (file.is_open()) {
            file << "Time: ";
            file << duration << " microseconds" << std::endl;
        }
        file.close();
    } else if ((sort_name == "arraySelectionSort") || (sort_name == "listSelectionSort")) {
        SelectionSort<int> Sorter;
        auto time1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto time2 = std::chrono::high_resolution_clock::now();
        if (file.is_open()) {
            file << "Sorted array: ";
            for (int i = 0; i < seq->GetLength(); ++i)
                file << (*seq)[i] << " ";
        }
        file << std::endl << "Number of elements: " << seq->GetLength() << std::endl;

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        if (file.is_open()) {
            file << "Time: ";
            file << duration << " microseconds" << std::endl;
        }
        file.close();
    } else if ((sort_name == "arrayInsertionSort") || (sort_name == "listInsertionSort")) {
        InsertionSort<int> Sorter;
        auto time1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto time2 = std::chrono::high_resolution_clock::now();
        if (file.is_open()) {
            file << "Sorted array: ";
            for (int i = 0; i < seq->GetLength(); ++i)
                file << (*seq)[i] << " ";
        }
        file << std::endl << "Number of elements: " << seq->GetLength() << std::endl;

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        if (file.is_open()) {
            file << "Time: ";
            file << duration << " microseconds" << std::endl;
        }
        file.close();
    } else if ((sort_name == "arrayMergeSort") || (sort_name == "listMergeSort")) {
        MergeSort<int> Sorter;
        auto time1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto time2 = std::chrono::high_resolution_clock::now();
        if (file.is_open()) {
            file << "Sorted array: ";
            for (int i = 0; i < seq->GetLength(); ++i)
                file << (*seq)[i] << " ";
        }
        file << std::endl << "Number of elements: " << seq->GetLength() << std::endl;

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        if (file.is_open()) {
            file << "Time: ";
            file << duration << " microseconds" << std::endl;
        }
        file.close();
    } else if ((sort_name == "arrayQuickSort") || (sort_name == "listQuickSort")) {
        QuickSort<int> Sorter;
        auto time1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto time2 = std::chrono::high_resolution_clock::now();
        if (file.is_open()) {
            file << "Sorted array: ";
            for (int i = 0; i < seq->GetLength(); ++i)
                file << (*seq)[i] << " ";
        }
        file << std::endl << "Number of elements: " << seq->GetLength() << std::endl;

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        if (file.is_open()) {
            file << "Time: ";
            file << duration << " microseconds" << std::endl;
        }
        file.close();
    } else if ((sort_name == "arrayShellSort") || (sort_name == "listShellSort")) {
        ShellSort<int> Sorter;
        auto time1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto time2 = std::chrono::high_resolution_clock::now();
        if (file.is_open()) {
            file << "Sorted array: ";
            for (int i = 0; i < seq->GetLength(); ++i)
                file << (*seq)[i] << " ";
        }
        file << std::endl << "Number of elements: " << seq->GetLength() << std::endl;

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        if (file.is_open()) {
            file << "Time: ";
            file << duration << " microseconds" << std::endl;
        }
        file.close();
    }
}

template <class T>
void exportTXTall(Sequence<T> *seq, int (*cmp)(T, T), const std::string& filename) {
    Sequence<T> *seq_copy = seq->Clone();
    std::ofstream file;
    file.open("sorts/" + filename + ".txt");
    if (file.is_open()) {
        file << "Unsorted array: ";
        for (int i = 0; i < seq->GetLength(); ++i)
            file << (*seq)[i] << " ";
    }
    file << std::endl;

    BubbleSort<int> Sorter1;
    auto time1 = std::chrono::high_resolution_clock::now();
    Sorter1.Sort(seq_copy, cmp);
    auto time2 = std::chrono::high_resolution_clock::now();

    if (file.is_open()) {
        file << "Sorted array: ";
        for (int i = 0; i < seq_copy->GetLength(); ++i)
            file << (*seq_copy)[i] << " ";
    }
    file << std::endl << "Number of elements: " << seq->GetLength() << std::endl;

    auto durationBubble = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();

    SelectionSort<int> Sorter2;
    seq_copy = seq->Clone();
    time1 = std::chrono::high_resolution_clock::now();
    Sorter2.Sort(seq_copy, cmp);
    time2 = std::chrono::high_resolution_clock::now();
    auto durationSelection = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();

    InsertionSort<int> Sorter3;
    seq_copy = seq->Clone();
    time1 = std::chrono::high_resolution_clock::now();
    Sorter3.Sort(seq_copy, cmp);
    time2 = std::chrono::high_resolution_clock::now();
    auto durationInsertion = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();

    MergeSort<int> Sorter4;
    seq_copy = seq->Clone();
    time1 = std::chrono::high_resolution_clock::now();
    Sorter4.Sort(seq_copy, cmp);
    time2 = std::chrono::high_resolution_clock::now();
    auto durationMerge = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();

    QuickSort<int> Sorter5;
    seq_copy = seq->Clone();
    time1 = std::chrono::high_resolution_clock::now();
    Sorter5.Sort(seq_copy, cmp);
    time2 = std::chrono::high_resolution_clock::now();
    auto durationQuick = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();

    ShellSort<int> Sorter6;
    seq_copy = seq->Clone();
    time1 = std::chrono::high_resolution_clock::now();
    Sorter6.Sort(seq_copy, cmp);
    time2 = std::chrono::high_resolution_clock::now();
    auto durationShell = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();

    if (file.is_open()) {
        file << "Time BubbleSort: ";
        file << durationBubble << " microseconds" << std::endl;

        file << "Time SelectionSort: ";
        file << durationSelection << " microseconds" << std::endl;

        file << "Time InsertionSort: ";
        file << durationInsertion << " microseconds" << std::endl;

        file << "Time MergeSort: ";
        file << durationMerge << " microseconds" << std::endl;

        file << "Time QuickSort: ";
        file << durationQuick << " microseconds" << std::endl;

        file << "Time ShellSort: ";
        file << durationShell << " microseconds" << std::endl;
    }
    file.close();
}

template <class T>
void exportCSV(Sequence<T> *seq, int (*cmp)(T, T), int max_value, int step, const std::string& filename) {
    std::ofstream file;
    file.open("sortscomparison/" + filename + ".csv");
    Sequence<T> *seq_copy;
    int avg_number = 3;

    BubbleSort<int> BubbleSorter;
    file << "BubbleSort,,," << std::endl;
    file << ",Time,," << std::endl;
    file << "Elements,Best,Random,Worst" << std::endl;
    for (int i = 0; i <= max_value; i += step) {
        //best time
        long avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateBestCase(seq_copy, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            BubbleSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_best = avg_duration/avg_number;

        //random time
        avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateRandom(seq_copy, i, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            BubbleSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_random = avg_duration/avg_number;

        //worst time
        avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateWorstCase(seq_copy, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            BubbleSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_worst = avg_duration/avg_number;

        file << i << "," << avg_duration_best << "," << avg_duration_random << "," << avg_duration_worst << std::endl;
    }
    file << ",,," << std::endl;



    SelectionSort<int> SelectionSorter;
    file << "SelectionSort,,," << std::endl;
    file << ",Time,," << std::endl;
    file << "Elements,Best,Random,Worst" << std::endl;
    for (int i = 0; i <= max_value; i += step) {
        //best time
        long avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateBestCase(seq_copy, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            SelectionSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_best = avg_duration/avg_number;

        //random time
        avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateRandom(seq_copy, i, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            SelectionSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_random = avg_duration/avg_number;

        //worst time
        avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateWorstCase(seq_copy, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            SelectionSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_worst = avg_duration/avg_number;

        file << i << "," << avg_duration_best << "," << avg_duration_random << "," << avg_duration_worst << std::endl;
    }
    file << ",,," << std::endl;



    InsertionSort<int> InsertionSorter;
    file << "InsertionSort,,," << std::endl;
    file << ",Time,," << std::endl;
    file << "Elements,Best,Random,Worst" << std::endl;
    for (int i = 0; i <= max_value; i += step) {
        //best time
        long avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateBestCase(seq_copy, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            InsertionSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_best = avg_duration/avg_number;

        //random time
        avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateRandom(seq_copy, i, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            InsertionSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_random = avg_duration/avg_number;

        //worst time
        avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateWorstCase(seq_copy, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            InsertionSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_worst = avg_duration/avg_number;

        file << i << "," << avg_duration_best << "," << avg_duration_random << "," << avg_duration_worst << std::endl;
    }
    file << ",,," << std::endl;


    MergeSort<int> MergeSorter;
    file << "MergeSort,,," << std::endl;
    file << ",Time,," << std::endl;
    file << "Elements,Best,Random,Worst" << std::endl;
    for (int i = 0; i <= max_value; i += step) {
        //best time
        long avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateBestCase(seq_copy, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            MergeSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_best = avg_duration/avg_number;

        //random time
        avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateRandom(seq_copy, i, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            MergeSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_random = avg_duration/avg_number;

        //worst time
        avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateWorstCase(seq_copy, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            MergeSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_worst = avg_duration/avg_number;

        file << i << "," << avg_duration_best << "," << avg_duration_random << "," << avg_duration_worst << std::endl;
    }
    file << ",,," << std::endl;



    QuickSort<int> QuickSorter;
    file << "QuickSort,,," << std::endl;
    file << ",Time,," << std::endl;
    file << "Elements,Best,Random,Worst" << std::endl;
    for (int i = 0; i <= max_value; i += step) {
        //best time
        long avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateBestCase(seq_copy, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            QuickSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_best = avg_duration/avg_number;

        //random time
        avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateRandom(seq_copy, i, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            QuickSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_random = avg_duration/avg_number;

        //worst time
        avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateWorstCase(seq_copy, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            QuickSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_worst = avg_duration/avg_number;

        file << i << "," << avg_duration_best << "," << avg_duration_random << "," << avg_duration_worst << std::endl;
    }
    file << ",,," << std::endl;


    ShellSort<int> ShellSorter;
    file << "ShellSort,,," << std::endl;
    file << ",Time,," << std::endl;
    file << "Elements,Best,Random,Worst" << std::endl;
    for (int i = 0; i <= max_value; i += step) {
        //best time
        long avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateBestCase(seq_copy, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            ShellSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_best = avg_duration/avg_number;

        //random time
        avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateRandom(seq_copy, i, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            ShellSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_random = avg_duration/avg_number;

        //worst time
        avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            seq_copy = seq->Clone();
            generateWorstCase(seq_copy, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            ShellSorter.Sort(seq_copy, cmp);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_worst = avg_duration/avg_number;

        file << i << "," << avg_duration_best << "," << avg_duration_random << "," << avg_duration_worst << std::endl;
    }
    file << ",,," << std::endl;
    file.close();
}

#endif //LAB1_FUNCTIONS_H