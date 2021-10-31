#include <iostream>
#include "../../src/functions.h"
#include "gtest/gtest.h"
#include <cmath>
using namespace std;

TEST(ArrayBubbleSort, test) {
    Sequence<int>* seq1 = (Sequence<int> *) new ArraySequence<int>;
    Sequence<int>* seq2 = (Sequence<int> *) new ArraySequence<int>;
    generateRandom(seq1, 100, 100);
    seq2 = seq1->Clone();
    BubbleSort<int> Sorter;
    Sorter.Sort(seq1, cmp);
    std::sort((*seq2)[0], (*seq2)[seq2->GetLength() - 1]);
    ASSERT_TRUE(seq1 == seq2);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
