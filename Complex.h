#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

using namespace std;

class Complex
{
    double re, im;
public:
    Complex(double a = 0, double b = 0);
    Complex(const Complex &ob);
    virtual ~Complex();

    void set_Complex(double a, double b);
    double get_real();
    double get_imaginar();

    friend istream& operator>>(istream&, Complex&);
    friend ostream& operator<<(ostream&, const Complex&);

    Complex& operator=(const Complex& z);
    friend bool operator!=(const Complex &, const Complex &);
    friend Complex operator*(const Complex &, const Complex &);
    friend Complex operator-(const Complex &, const Complex &);
    friend Complex operator+(const Complex &, const Complex &);
};

#endif // COMPLEX_H
