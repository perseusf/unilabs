#ifndef VECTOR_H
#define VECTOR_H

#include "listsequence.h"
#include "listsequence.cpp"
#include "arraysequence.h"
#include "arraysequence.cpp"

template<class T>
class Vector {
private:
    Sequence<T> *data_;
    int dimension_;
public:
    //constructors
    Vector();
    explicit Vector(int dimension);
    explicit Vector(Sequence<T> *data);
    Vector(const Vector<T> &vector);

    //operations
    [[nodiscard]] int GetDimension() const;
    T &Get(int index);
    void Set(int index, T& value);

    //operators
    T &operator[](int index); //implement
    Vector<T> &operator=(Vector<T> *vector);
    template<class W>
    friend std::ostream& operator <<(std::ostream &out, const Vector<W> &v);

    //some math
    Vector<T> Addition(Vector<T> v);
    Vector<T> Subtraction(Vector<T> v);
    Vector<T> ScalarMultiplication(T number);
    T DotProduct(Vector<T> vector);
    double Norm();

    //destructor
    ~Vector();
};

#endif // VECTOR_H
