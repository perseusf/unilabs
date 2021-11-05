#include <iostream>
#include "../../src/functions.h"
#include "gtest/gtest.h"
using namespace std;

int seqlen = 1000;
int maxvalue = 1000;

//int array
TEST(ArrayBubbleSort, test) {
    Sequence<int>* seq = (Sequence<int> *) new ArraySequence<int>;
    generateRandom(seq, seqlen, maxvalue);
    BubbleSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ArraySelectionSort, test) {
    Sequence<int>* seq = (Sequence<int> *) new ArraySequence<int>;
    generateRandom(seq, seqlen, maxvalue);
    SelectionSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ArrayInsertionSort, test) {
    Sequence<int>* seq = (Sequence<int> *) new ArraySequence<int>;
    generateRandom(seq, seqlen, maxvalue);
    InsertionSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ArrayMergeSort, test) {
    Sequence<int>* seq = (Sequence<int> *) new ArraySequence<int>;
    generateRandom(seq, seqlen, maxvalue);
    MergeSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ArrayQuickSort, test) {
    Sequence<int>* seq = (Sequence<int> *) new ArraySequence<int>;
    generateRandom(seq, seqlen, maxvalue);
    QuickSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ArrayShellSort, test) {
    Sequence<int>* seq = (Sequence<int> *) new ArraySequence<int>;
    generateRandom(seq, seqlen, maxvalue);
    ShellSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}


//intlist
TEST(ListBubbleSort, test) {
    Sequence<int>* seq = (Sequence<int> *) new ListSequence<int>;
    generateRandom(seq, seqlen, maxvalue);
    BubbleSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ListSelectionSort, test) {
    Sequence<int>* seq = (Sequence<int> *) new ListSequence<int>;
    generateRandom(seq, seqlen, maxvalue);
    SelectionSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ListInsertionSort, test) {
    Sequence<int>* seq = (Sequence<int> *) new ListSequence<int>;
    generateRandom(seq, seqlen, maxvalue);
    InsertionSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ListMergeSort, test) {
    Sequence<int>* seq = (Sequence<int> *) new ListSequence<int>;
    generateRandom(seq, seqlen, maxvalue);
    MergeSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ListQuickSort, test) {
    Sequence<int>* seq = (Sequence<int> *) new ListSequence<int>;
    generateRandom(seq, seqlen, maxvalue);
    QuickSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ListShellSort, test) {
    Sequence<int> *seq = (Sequence<int> *) new ListSequence<int>;
    generateRandom(seq, seqlen, maxvalue);
    ShellSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}





//double array
TEST(ArrayDoubleBubbleSort, test) {
    Sequence<double>* seq = (Sequence<double> *) new ArraySequence<double>;
    generateRandomDouble(seq, seqlen, maxvalue);
    BubbleSort<double> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ArrayDoubleSelectionSort, test) {
    Sequence<double>* seq = (Sequence<double> *) new ArraySequence<double>;
    generateRandomDouble(seq, seqlen, maxvalue);
    SelectionSort<double> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ArrayDoubleInsertionSort, test) {
    Sequence<double>* seq = (Sequence<double> *) new ArraySequence<double>;
    generateRandomDouble(seq, seqlen, maxvalue);
    InsertionSort<double> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ArrayDoubleMergeSort, test) {
    Sequence<double>* seq = (Sequence<double> *) new ArraySequence<double>;
    generateRandomDouble(seq, seqlen, maxvalue);
    MergeSort<double> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ArrayDoubleQuickSort, test) {
    Sequence<double>* seq = (Sequence<double> *) new ArraySequence<double>;
    generateRandomDouble(seq, seqlen, maxvalue);
    QuickSort<double> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ArrayDoubleShellSort, test) {
    Sequence<double>* seq = (Sequence<double> *) new ArraySequence<double>;
    generateRandomDouble(seq, seqlen, maxvalue);
    ShellSort<double> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}


//double list
TEST(ListDoubleBubbleSort, test) {
    Sequence<double>* seq = (Sequence<double> *) new ListSequence<double>;
    generateRandomDouble(seq, seqlen, maxvalue);
    BubbleSort<double> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ListDoubleSelectionSort, test) {
    Sequence<double>* seq = (Sequence<double> *) new ListSequence<double>;
    generateRandomDouble(seq, seqlen, maxvalue);
    SelectionSort<double> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ListDoubleInsertionSort, test) {
    Sequence<double>* seq = (Sequence<double> *) new ListSequence<double>;
    generateRandomDouble(seq, seqlen, maxvalue);
    InsertionSort<double> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ListDoubleMergeSort, test) {
    Sequence<double>* seq = (Sequence<double> *) new ListSequence<double>;
    generateRandomDouble(seq, seqlen, maxvalue);
    MergeSort<double> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ListDoubleQuickSort, test) {
    Sequence<double>* seq = (Sequence<double> *) new ListSequence<double>;
    generateRandomDouble(seq, seqlen, maxvalue);
    QuickSort<double> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ListDoubleShellSort, test) {
    Sequence<double> *seq = (Sequence<double> *) new ListSequence<double>;
    generateRandomDouble(seq, seqlen, maxvalue);
    ShellSort<double> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}





//char array
TEST(ArrayCharBubbleSort, test) {
    Sequence<char>* seq = (Sequence<char> *) new ArraySequence<char>;
    generateRandomChar(seq, seqlen);
    BubbleSort<char> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ArrayCharSelectionSort, test) {
    Sequence<char>* seq = (Sequence<char> *) new ArraySequence<char>;
    generateRandomChar(seq, seqlen);
    SelectionSort<char> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ArrayCharInsertionSort, test) {
    Sequence<char>* seq = (Sequence<char> *) new ArraySequence<char>;
    generateRandomChar(seq, seqlen);
    InsertionSort<char> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ArrayCharMergeSort, test) {
    Sequence<char>* seq = (Sequence<char> *) new ArraySequence<char>;
    generateRandomChar(seq, seqlen);
    MergeSort<char> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ArrayCharQuickSort, test) {
    Sequence<char>* seq = (Sequence<char> *) new ArraySequence<char>;
    generateRandomChar(seq, seqlen);
    QuickSort<char> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ArrayCharShellSort, test) {
    Sequence<char>* seq = (Sequence<char> *) new ArraySequence<char>;
    generateRandomChar(seq, seqlen);
    ShellSort<char> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}


//char list
TEST(ListCharBubbleSort, test) {
    Sequence<char>* seq = (Sequence<char> *) new ListSequence<char>;
    generateRandomChar(seq, seqlen);
    BubbleSort<char> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ListCharSelectionSort, test) {
    Sequence<char>* seq = (Sequence<char> *) new ListSequence<char>;
    generateRandomChar(seq, seqlen);
    SelectionSort<char> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ListCharInsertionSort, test) {
    Sequence<char>* seq = (Sequence<char> *) new ListSequence<char>;
    generateRandomChar(seq, seqlen);
    InsertionSort<char> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ListCharMergeSort, test) {
    Sequence<char>* seq = (Sequence<char> *) new ListSequence<char>;
    generateRandomChar(seq, seqlen);
    MergeSort<char> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ListCharQuickSort, test) {
    Sequence<char>* seq = (Sequence<char> *) new ListSequence<char>;
    generateRandomChar(seq, seqlen);
    QuickSort<char> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

TEST(ListCharShellSort, test) {
    Sequence<char> *seq = (Sequence<char> *) new ListSequence<char>;
    generateRandomChar(seq, seqlen);
    ShellSort<char> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
