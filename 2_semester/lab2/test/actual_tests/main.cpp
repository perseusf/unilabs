#include <iostream>
#include "../../src/vector.h"
#include "../../src/vector.cpp"
#include <complex>
#include "gtest/gtest.h"
#include <cmath>
using namespace std;

TEST(IntAddition, test) {
    int dim = 0;
    int value = 0;
    Vector<int> Vector1(dim);
    Vector<int> Vector2(dim);
    for (int i = 0; i < dim; i++) {
        Vector1.Set(i, i);
        int a = 10 * i * i;
        Vector2.Set(i, a);
    }
    Vector<int> Vector3(Vector2);
    for (int i = 0; i < dim; i++) {
        if (Vector3.Get(i) == i + 10 * i * i)
            value++;
    }
    ASSERT_TRUE(value == dim);
}

TEST(DoubleAddition, test) {
    int dim = 3;
    Vector<double> Vector1(dim);
    Vector<double> Vector2(dim);
    for (int i = 0; i < dim; ++i) {
        double a = i;
        Vector1.Set(i, a);
        double b = 100 * i;
        Vector2.Set(i, b);
    }
    Vector<double> Vector3(dim);
    Vector3 = Vector1.Addition(&Vector2);
    int value = 0;
    for (int i = 0; i < dim; ++i) {
        if (Vector3.Get(i) == i + 100 * i)
            value++;
    }
    ASSERT_TRUE(value == dim);
}

TEST(ComplexAddition, test) {
    int dim = 60;
    Vector<complex<int>> Vector1(dim);
    Vector<complex<int>> Vector2(dim);
    for (int i = 0; i < dim; i++) {
        complex<int> a(10*i, 2*i);
        Vector1.Set(i, a);
        complex<int> b(i, i*i);
        Vector2.Set(i, b);
    }
    Vector<complex<int>> Vector3(dim);
    Vector3 = Vector1.Addition(&Vector2);
    int value = 0;
    for (int i = 0; i < dim; ++i) {
        complex<int> c(11*i, 2*i + i*i);
        if (Vector3.Get(i) == c)
            value++;
    }
    ASSERT_TRUE(value == dim);
}

TEST(IntScalarMultiplication, test) {
    int dim = 543;
    int number = 2;
    Vector<int> Vector1(dim);
    for (int i = 0; i < dim; i++) {
        int a = i;
        Vector1.Set(i, a);
    }
    Vector<int> Vector2(dim);
    Vector2 = Vector1.ScalarMultiplication(number);
    int value = 0;
    for (int i = 0; i < dim; ++i) {
        if (Vector2.Get(i) == number * i)
            value++;
    }
    ASSERT_TRUE(value == dim);
}

TEST(DoubleScalarMultiplication, test) {
    int dim = 321;
    double number = 1;
    Vector<double> Vector1(dim);
    for (int i = 0; i < dim; i++) {
        double a = sqrt(i*i*i);
        Vector1.Set(i, a);
    }
    Vector<double> Vector2(dim);
    Vector2 = Vector1.ScalarMultiplication(number);
    int value = 0;
    for (int i = 0; i < dim; i++) {
        if (Vector2.Get(i) == number * sqrt(i*i*i))
            value++;
    }
    ASSERT_TRUE(value == dim);
}

TEST(ComplexScalarMultiplication, test) {
    int dim = 432;
    complex<int> compnumber(1, 1);
    Vector<complex<int>> Vector1(dim);
    for (int i = 0; i < dim; ++i) {
        complex<int> a(i, i * i);
        Vector1.Set(i, a);
    }
    Vector<complex<int>> Vector2(dim);
    Vector2 = Vector1.ScalarMultiplication(compnumber);
    int value = 0;
    for (int i = 0; i < dim; ++i) {
        complex<int> c(i, i*i);
        if (Vector2.Get(i) == compnumber * c)
            value++;
    }
    ASSERT_TRUE(value == dim);
}

TEST(IntDotProduct, test) {
    int dim = 1342;
    Vector<int> Vector1(dim);
    Vector<int> Vector2(dim);
    for (int i = 0; i < dim; ++i) {
        Vector1.Set(i, i);
        int a = i * i;
        Vector2.Set(i, a);
    }
    int prod = Vector1.DotProduct(&Vector2);
    int value = 0;
    for (int i = 0; i < dim; ++i) {
        value += i * i * i;
    }
    ASSERT_TRUE(value == prod);
}

TEST(DoubleDotProduct, test) {
    int dim = 352;
    Vector<double> Vector1(dim);
    Vector<double> Vector2(dim);
    for (int i = 0; i < dim; ++i) {
        double a = sqrt(2*i);
        Vector1.Set(i, a);
        double b = sqrt(2 * i);
        Vector2.Set(i, b);
    }
    double prod = Vector1.DotProduct(&Vector2);
    double count = 0;
    for (int i = 0; i < dim; ++i) {
        count += i*2;
    }
    ASSERT_TRUE(count == prod);
}

TEST(ComplexDotProduct, test) {
    int dim = 1;
    Vector<complex<int>> Vector1(dim);
    Vector<complex<int>> Vector2(dim);
    for (int i = 0; i < dim; ++i) {
        complex<int> a(i, 2*i);
        Vector1.Set(i, a);
        complex<int> b(i, i*i);
        Vector2.Set(i, b);
    }
    complex<int> prod = Vector1.DotProduct(&Vector2);
    complex<int> count;
    for (int i = 0; i < dim; ++i) {
        complex<int> c(i*i - 2*i*i*i, i*i*i + 2*i*i);
        count = count + c;
    }
    ASSERT_TRUE(count == prod);
}

TEST(IntNorm, test) {
    int dim = 5;
    Vector<int> Vector1(dim);
    for (int i = 0; i < dim; ++i) {
        int a = i;
        Vector1.Set(i, a);
    }
    double Norm = Vector1.Norm();
    int count = 0;
    for (int i = 0; i < dim; ++i) {
        count += i*i;
    }
    ASSERT_TRUE(sqrt(count) == Norm);
}

TEST(DoubleNorm, test) {
    int dim = 1;
    Vector<double> Vector1(dim);
    for (int i = 0; i < dim; ++i) {
        double a = sqrt(100*i);
        Vector1.Set(i, a);
    }
    double norm = Vector1.Norm();
    double value = 0;
    for (int i = 0; i < dim; ++i) {
        value += 0.1 * i;
    }
    ASSERT_TRUE(sqrt(value) == norm);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
