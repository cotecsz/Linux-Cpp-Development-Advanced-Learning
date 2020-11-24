//
// Created by dream on 2020/11/24.
//

#include <iostream>
#include <string>

using namespace std;


template < typename T >
T Max(T a, T b)
{
    cout << "T Max(T a, T b)" << endl;

    return a > b ? a : b;
}

int Max(int a, int b)
{
    cout << "int Max(int a, int b)" << endl;

    return a > b ? a : b;
}

template < typename T >
T Max(T a, T b, T c)
{
    cout << "T Max(T a, T b, T c)" << endl;

    return Max(Max(a, b), c);
}

int main()
{
    int a = 1;
    int b = 2;

    cout << Max(a, b) << endl;                   // 普通函数 Max(int, int)

    cout << Max<>(a, b) << endl;                 // 函数模板 Max<int>(int, int)

    cout << Max(3.0, 4.0) << endl;               // 普通函数 V.S 函数模板1 ： 函数模板 Max<double>(double, double)

    cout << Max(5.0, 6.0, 7.0) << endl;          // 普通函数 V.S 函数模板2 ： 函数模板 Max<double>(double, double, double)

    cout << Max('a', 100) << endl;               // 函数模板不会进行隐式类型转换， 普通函数 Max(int, int)

    return 0;
}

