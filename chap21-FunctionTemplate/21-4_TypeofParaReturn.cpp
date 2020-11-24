//
// Created by dream on 2020/11/24.
//

#include <iostream>
#include <string>

using namespace std;

template
        < typename T1, typename T2, typename T3 >
T1 Add(T2 a, T3 b)
{
    return static_cast<T1>(a + b);
}


int main()
{
    // T1 = int, T2 = double, T3 = double
    int r1 = Add<int>(0.5, 0.8);

    // T1 = double, T2 = float, T3 = double
    double r2 = Add<double, float>(0.5, 0.8);

    // T1 = float, T2 = float, T3 = float
    float r3 = Add<float, float, float>(0.5, 0.8);

    cout << "r1 = " << r1 << endl;     // r1 = 1
    cout << "r2 = " << r2 << endl;     // r2 = 1.3
    cout << "r3 = " << r3 << endl;     // r3 = 1.3

    return 0;
}

