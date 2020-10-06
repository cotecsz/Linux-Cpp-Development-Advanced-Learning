//
// Created by Yang Shuangzhen on 2020/10/6.
//

#include "12-4_Complex.h"
#include "math.h"

Complex::Complex(double a, double b)
{
    this->a = a;
    this->b = b;
}

double Complex::getA()
{
    return a;
}

double Complex::getB()
{
    return b;
}

double Complex::getModulus()
{
    return sqrt(a * a + b * b);
}

Complex Complex::operator + (const Complex& c)
{
    double na = a + c.a;
    double nb = b + c.b;
    Complex ret(na, nb);

    return ret;
}

Complex Complex::operator - (const Complex& c)
{
    double na = a - c.a;
    double nb = b - c.b;
    Complex ret(na, nb);

    return ret;
}

Complex Complex::operator * (const Complex& c)
{
    double na = a * c.a - b * c.b;
    double nb = a * c.b + b * c.a;
    Complex ret(na, nb);

    return ret;
}

Complex Complex::operator / (const Complex& c)
{
    double cm = c.a * c.a + c.b * c.b;
    double na = (a * c.a + b * c.b) / cm;
    double nb = (b * c.a - a * c.b) / cm;
    Complex ret(na, nb);

    return ret;
}

bool Complex::operator == (const Complex& c)
{
    return (a == c.a) && (b == c.b);
}

bool Complex::operator != (const Complex& c)
{
    return !(*this == c);
}

Complex& Complex::operator = (const Complex& c)
{
    if( this != &c )
    {
        a = c.a;
        b = c.b;
    }

    return *this;
}