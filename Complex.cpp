#include "Complex.h"
#include <iostream>
#include <cmath>
using namespace std;


Complex::Complex(double a, double b): re(a), im(b){}  ///Initializare

Complex::Complex(const Complex &ob)  ///Copy Constructor
{
    re = ob.re;
    im = ob.im;
}

Complex::~Complex()
{
    cout << "Distruge Complex\n";
}

void Complex::set_Complex(double a, double b)
{
    re = a;
    im = b;
}

double Complex::get_real()
{
    return re;
}

double Complex::get_imaginar()
{
    return im;
}

istream& operator>>(istream& in, Complex &z)
{
    in >> z.re >> z.im;
    return in;
}

ostream& operator<<(ostream& out, const Complex &z)
{
    if(z.re == 0)
    {
        if(z.im > 0)
            out << "i*" << z.im;
        else if(z.im < 0)
            out << "-i*" <<-z.im;
        else
            out << 0;
    }
    else if(z.re > 0)
    {
        if(z.im == 0)
            out << z.re;
        else if(z.im < 0)
            out << z.re << "-i*" << z.im;
        else
            out << z.re << "+i*" << z.im;
    }
    out << '\n';
    return out;
}

Complex& Complex::operator=(const Complex& z)
{
    re = z.re;
    im = z.im;
    return *this;
}

bool operator!=(const Complex &z1, const Complex &z2)
{
    if(z1.re == z2.re || z1.im == z2.im)
        return 0;
    return 1;
}

Complex operator*(const Complex &z1, const Complex &z2)
{
    Complex z;
    z.re = z1.re * z2.re - z1.im * z2.re;
    z.im = z1.re * z2.im + z1.im * z2.re;
    return z;
}

Complex operator-(const Complex &z1, const Complex &z2)
{
    Complex z;
    z.re = z1.re - z2.re;
    z.im = z1.im - z2.im;
    return z;
}

Complex operator+(const Complex &z1, const Complex &z2)
{
    Complex z;
    z.re = z1.re + z2.re;
    z.im = z1.im + z2.im;
    return z;
}

//


