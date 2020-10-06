//
// Created by Yang Shuangzhen on 2020/10/6.
//


#include <stdio.h>
#include "12-4_Complex.h"

int main()
{
    Complex c1(1, 2);
    Complex c2(3, 6);
    Complex c3 = c2 - c1;
    Complex c4 = c1 * c3;
    Complex c5 = c2 / c1;

    printf("c3.a = %f, c3.b = %f\n", c3.getA(), c3.getB());
    printf("c4.a = %f, c4.b = %f\n", c4.getA(), c4.getB());
    printf("c5.a = %f, c5.b = %f\n", c5.getA(), c5.getB());

    Complex c6(2, 4);

    printf("c3 == c6 : %d\n", c3 == c6);
    printf("c3 != c4 : %d\n", c3 != c4);

    (c3 = c2) = c1;

    printf("c1.a = %f, c1.b = %f\n", c1.getA(), c1.getB());
    printf("c2.a = %f, c2.b = %f\n", c2.getA(), c2.getB());
    printf("c3.a = %f, c3.b = %f\n", c3.getA(), c3.getB());

    return 0;
}
