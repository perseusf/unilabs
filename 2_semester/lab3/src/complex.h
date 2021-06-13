#ifndef COMPLEX_H
#define COMPLEX_H


#include <iostream>

class Complex
{
    int Re;
    int Im;

public:
    Complex();
    Complex(int Re, int Im);

    int GetRe();
    int GetIm();

    void Set(int Re, int Im);
    Complex conjugate();

    Complex operator + (const Complex& other);
    Complex operator - (const Complex& other);
    Complex operator * (const Complex& other);

    bool operator == (const Complex& other);
    bool operator != (const Complex& other);
    bool operator < (const Complex& other);
    bool operator > (const Complex& other);
    bool operator <= (const Complex& other);
    bool operator >= (const Complex& other);

    friend std::ostream& operator << (std::ostream &out, const Complex a);

};

std::string to_string(Complex &a);

#endif // COMPLEX_H
