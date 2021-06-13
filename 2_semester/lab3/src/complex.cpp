#include "complex.h"
#include <iostream>

Complex::Complex() {
    Re = Im = 0;
}

Complex::Complex(int Re, int Im) {
    this->Re = Re;
    this->Im = Im;
}

int Complex::GetRe() {
    return this->Re;
}

int Complex::GetIm() {
    return this->Im;
}

void Complex::Set(int Re, int Im) {
    this->Re = Re;
    this->Im = Im;
}

Complex Complex::conjugate() {
    Complex a(this->Re, - this->Im);
    return a;
}

Complex Complex::operator + (const Complex& other) {
    Complex Sum;
    Sum.Re = this->Re + other.Re;
    Sum.Im = this->Im + other.Im;
    return Sum;
}

Complex Complex::operator - (const Complex& other) {
    Complex Diff;
    Diff.Re = this->Re - other.Re;
    Diff.Im = this->Im - other.Im;
    return Diff;
}

Complex Complex::operator * (const Complex& other) {
    Complex Mul;
    Mul.Re = this->Re * other.Re - this->Im * other.Im;
    Mul.Im = this->Re * other.Im + this->Im * other.Re;
    return Mul;
}

bool Complex::operator == (const Complex& other) {
    return this->Re == other.Re && this->Im == other.Im;
}

bool Complex::operator != (const Complex& other) {
    return !(this->Re == other.Re && this->Im == other.Im);
}

bool Complex::operator < (const Complex& other) {
    double a = this->Re*this->Re + this->Im*this->Im;
    double b = other.Re*other.Re + other.Im*other.Im;
    return a < b;
}

bool Complex::operator > (const Complex& other) {
    double a = this->Re*this->Re + this->Im*this->Im;
    double b = other.Re*other.Re + other.Im*other.Im;
    return a > b;
}

bool Complex::operator <= (const Complex& other) {
    double a = this->Re*this->Re + this->Im*this->Im;
    double b = other.Re*other.Re + other.Im*other.Im;
    return a <= b;
}

bool Complex::operator >= (const Complex& other) {
    double a = this->Re*this->Re + this->Im*this->Im;
    double b = other.Re*other.Re + other.Im*other.Im;
    return a >= b;
}

std::ostream& operator << (std::ostream &out, const Complex a) {
    if (a.Re != 0 && a.Im > 0 && a.Im != 1) std::cout << a.Re << "+" << a.Im << "i";
    if (a.Re == 0 && a.Im > 0 && a.Im != 1) std::cout << a.Im << "i";
    if (a.Re != 0 && a.Im == 1) std::cout << a.Re << "+i";
    if (a.Re == 0 && a.Im == 1) std::cout << "i";

    if (a.Re != 0 && a.Im == 0) std::cout << a.Re;
    if (a.Re == 0 && a.Im == 0) std::cout << "0";

    if (a.Re != 0 && a.Im < 0 && a.Im != -1) std::cout << a.Re << a.Im << "i";
    if (a.Re == 0 && a.Im < 0 && a.Im != -1) std::cout << a.Im << "i";
    if (a.Re != 0 && a.Im == -1) std::cout << a.Re << "-i";
    if (a.Re == 0 && a.Im == -1) std::cout << "-i";
    return out;
}

std::string to_string(Complex &a) {
    if (a.GetRe() != 0 && a.GetIm() > 0 && a.GetIm() != 1) return std::to_string(a.GetRe()) + "+" + std::to_string(a.GetIm()) + "i";
    if (a.GetRe() == 0 && a.GetIm() > 0 && a.GetIm() != 1) return std::to_string(a.GetIm()) + "i";
    if (a.GetRe() != 0 && a.GetIm() == 1) return std::to_string(a.GetRe()) + "+i";
    if (a.GetRe() == 0 && a.GetIm() == 1) return "i";

    if (a.GetRe() != 0 && a.GetIm() == 0) return std::to_string(a.GetRe());
    if (a.GetRe() == 0 && a.GetIm() == 0) return "0";

    if (a.GetRe() != 0 && a.GetIm() < 0 && a.GetIm() != -1) return std::to_string(a.GetRe()) + std::to_string(a.GetIm()) + "i";
    if (a.GetRe() == 0 && a.GetIm() < 0 && a.GetIm() != -1) return std::to_string(a.GetIm()) + "i";
    if (a.GetRe() != 0 && a.GetIm() == -1) return std::to_string(a.GetRe()) + "-i";
    if (a.GetRe() == 0 && a.GetIm() == -1) return "-i";
    return "";
}
