//
// Created by dream on 2020/11/25.
//
#include <iostream>
#include <string>

using namespace std;

template
        < typename T1, typename T2 >
class Test
{
public:
    void add(T1 a, T2 b)
    {
        cout << "void add(T1 a, T2 b)" << endl;
        cout << a + b << endl;
    }
};

/*
template
<  >
class Test < void*, void* >    // 当 T1 == void* 并且 T2 == void* 时
{
public:
    void add(void* a, void* b)
    {
        cout << "void add(void* a, void* b)" << endl;
        cout << "Error to add void* param..." << endl;
    }
};
*/

class Test_Void
{
public:
    void add(void* a, void* b)
    {
        cout << "void add(void* a, void* b)" << endl;
        cout << "Error to add void* param..." << endl;
    }
};

template
        < typename T >
bool Equal(T a, T b)
{
    cout << "bool Equal(T a, T b)" << endl;

    return a == b;
}

template
        < >
bool Equal<double>(double a, double b)
{
    const double delta = 0.00000000000001;
    double r = a - b;

    cout << "bool Equal<double>(double a, double b)" << endl;

    return (-delta < r) && (r < delta);
}

bool Equal(double a, double b)
{
    const double delta = 0.00000000000001;
    double r = a - b;

    cout << "bool Equal(double a, double b)" << endl;

    return (-delta < r) && (r < delta);
}

int main()
{
    cout << Equal( 1, 1 ) << endl;
    cout << Equal( 0.001, 0.001 ) << endl;

    cout << Equal<>( 0.001, 0.001 ) << endl;

    return 0;
}


