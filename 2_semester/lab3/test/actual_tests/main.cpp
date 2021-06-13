#include "../../src/heap.h"
#include "../../src/heap.cpp"
#include "../../src/set.h"
#include "../../src/set.cpp"
#include <gtest/gtest.h>
#include <future>

TEST (IntSetUnion, test1) {
    Set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    Set<int> set2;
    set2.insert(0);
    Set<int> set3;
    set3.insert(1);
    set3.insert(2);
    set3.insert(3);
    set3.insert(0);
    Set<int> setUnion = set1 + set2;
    ASSERT_TRUE(setUnion == set3);
}

TEST (IntSetUnion, test2) {
    Set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(11);
    set1.insert(22);
    set1.insert(33);
    Set<int> set2;
    set2.insert(0);
    Set<int> set3;
    set3.insert(1);
    set3.insert(2);
    set3.insert(3);
    set3.insert(11);
    set3.insert(22);
    set3.insert(33);
    set3.insert(0);
    Set<int> setUnion = set1 + set2;
    ASSERT_TRUE(setUnion == set3);
}

TEST (DoubleSetUnion, test1) {
    Set<double> set1;
    set1.insert(1.3);
    set1.insert(2);
    set1.insert(3.3);
    Set<double> set2;
    set2.insert(0);
    Set<double> set3;
    set3.insert(1.3);
    set3.insert(2);
    set3.insert(3.3);
    set3.insert(0);
    Set<double> setUnion = set1 + set2;
    ASSERT_TRUE(setUnion == set3);
}

TEST (DoubleSetUnion, test2) {
    Set<double> set1;
    set1.insert(1.3);
    set1.insert(2.3);
    set1.insert(3);
    Set<double> set2;
    set2.insert(0);
    Set<double> set3;
    set3.insert(1.3);
    set3.insert(2.3);
    set3.insert(3);
    set3.insert(0);
    Set<double> setUnion = set1 + set2;
    ASSERT_TRUE(setUnion == set3);
}





TEST (IntSetComplement, test1) {
    Set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    Set<int> set2;
    set2.insert(2);
    Set<int> set3;
    set3.insert(1);
    set3.insert(3);
    Set<int> setComplement = set1 - set2;
    ASSERT_TRUE(setComplement == set3);
}

TEST (IntSetComplement, test2) {
    Set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(11);
    set1.insert(22);
    set1.insert(33);
    Set<int> set2;
    set2.insert(33);
    Set<int> set3;
    set3.insert(1);
    set3.insert(2);
    set3.insert(3);
    set3.insert(11);
    set3.insert(22);
    Set<int> setComplement = set1 - set2;
    ASSERT_TRUE(setComplement == set3);
}

TEST (DoubleSetComplement, test1) {
    Set<double> set1;
    set1.insert(1.3);
    set1.insert(2);
    set1.insert(3.3);
    Set<double> set2;
    set2.insert(3.3);
    Set<double> set3;
    set3.insert(1.3);
    set3.insert(2);
    Set<double> setComplement = set1 - set2;
    ASSERT_TRUE(setComplement == set3);
}

TEST (DoubleSetComplement, test2) {
    Set<double> set1;
    set1.insert(1.3);
    set1.insert(2.3);
    set1.insert(3);
    Set<double> set2;
    set2.insert(3);
    Set<double> set3;
    set3.insert(1.3);
    set3.insert(2.3);
    Set<double> setComplement = set1 - set2;
    ASSERT_TRUE(setComplement == set3);
}



TEST (IntSetIntersection, test1) {
    Set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    Set<int> set2;
    set2.insert(1);
    set2.insert(3);
    Set<int> set3;
    set3.insert(1);
    set3.insert(3);
    Set<int> setIntersection= set1 * set2;
    ASSERT_TRUE(setIntersection== set3);
}

TEST (IntSetIntersection, test2) {
    Set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(11);
    set1.insert(22);
    set1.insert(33);
    Set<int> set2;
    set2.insert(22);
    Set<int> set3;
    set3.insert(22);
    Set<int> setIntersection= set1 * set2;
    ASSERT_TRUE(setIntersection== set3);
}

TEST (DoubleSetIntersection, test1) {
    Set<double> set1;
    set1.insert(1.3);
    set1.insert(2);
    set1.insert(3.3);
    Set<double> set2;
    set2.insert(2);
    Set<double> set3;
    set3.insert(2);
    Set<double> setIntersection= set1 * set2;
    ASSERT_TRUE(setIntersection== set3);
}

TEST (DoubleSetIntersection, test2) {
    Set<double> set1;
    set1.insert(1.3);
    set1.insert(2.3);
    set1.insert(3);
    Set<double> set2;
    set2.insert(3);
    Set<double> set3;
    set3.insert(3);
    Set<double> setIntersection= set1 * set2;
    ASSERT_TRUE(setIntersection== set3);
}





TEST (IntSetEquality, test1) {
    Set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    Set<int> set2;
    set2.insert(1);
    set2.insert(2);
    set2.insert(3);
    ASSERT_TRUE(set1 == set2);
}

TEST (IntSetEquality, test2) {
    Set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(8);
    set1.insert(3);
    Set<int> set2;
    set2.insert(1);
    set2.insert(2);
    set2.insert(8);
    set2.insert(3);
    ASSERT_TRUE(set1 == set2);
}

TEST (DoubleSetEquality, test1) {
    Set<double> set1;
    set1.insert(1);
    set1.insert(2.4);
    set1.insert(8);
    set1.insert(3.56);
    Set<double> set2;
    set2.insert(1);
    set2.insert(2.4);
    set2.insert(8);
    set2.insert(3.56);
    ASSERT_TRUE(set1 == set2);
}

TEST (DoubleSetEquality, test2) {
    Set<double> set1;
    set1.insert(1);
    set1.insert(2.4);
    set1.insert(8);
    set1.insert(3.56);
    set1.insert(8);
    set1.insert(3.56);
    Set<double> set2;
    set2.insert(1);
    set2.insert(2.4);
    set2.insert(8);
    set2.insert(3.56);
    set2.insert(8);
    set2.insert(3.56);
    ASSERT_TRUE(set1 == set2);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
