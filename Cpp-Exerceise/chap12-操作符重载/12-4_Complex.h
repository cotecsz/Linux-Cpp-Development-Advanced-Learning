//
// Created by Yang Shuangzhen on 2020/10/6.
//

#ifndef CPP_EXERCEISE_12_4_COMPLEX_H
#define CPP_EXERCEISE_12_4_COMPLEX_H

#ifndef _COMPLEX_H_
#define _COMPLEX_H_

class Complex
{
    double a;
    double b;
public:
    Complex(double a = 0, double b = 0);
    double getA();
    double getB();
    double getModulus();

    Complex operator + (const Complex& c);
    Complex operator - (const Complex& c);
    Complex operator * (const Complex& c);
    Complex operator / (const Complex& c);

    bool operator == (const Complex& c);
    bool operator != (const Complex& c);

    Complex& operator = (const Complex& c);
};

#endif

#endif //CPP_EXERCEISE_12_4_COMPLEX_H
