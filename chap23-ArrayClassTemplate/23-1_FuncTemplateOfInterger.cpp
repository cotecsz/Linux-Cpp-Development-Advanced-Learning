//
// Created by dream on 2020/11/25.
//

#include <iostream>
#include <string>

using namespace std;

template
        < typename T, int N >
void func()
{
    T a[N] = {0};

    for(int i=0; i<N; i++)
    {
        a[i] = i;
    }

    for(int i=0; i<N; i++)
    {
        cout << a[i] << endl;
    }
}

template
        < int N >
class Sum
{
public:
    static const int VALUE = Sum<N-1>::VALUE + N;
};

template
        < >
class Sum < 1 >
{
public:
    static const int VALUE = 1;
};


int main()
{
    cout << "1 + 2 + 3 + ... + 10 = " << Sum<10>::VALUE << endl;
    cout << "1 + 2 + 3 + ... + 100 = " << Sum<100>::VALUE << endl;

    return 0;
}

