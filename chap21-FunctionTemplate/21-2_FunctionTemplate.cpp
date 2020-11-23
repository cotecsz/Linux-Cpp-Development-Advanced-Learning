//
// Created by dream on 2020/11/22.
//
#include <iostream>
#include <string>

using namespace std;

template < typename T >
void Swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

template < typename T >
void Sort(T a[], int len)
{
    for(int i=0; i<len; i++)
    {
        for(int j=i; j<len; j++)
        {
            if( a[i] > a[j] )
            {
                Swap<T>(a[i], a[j]);
            }
        }
    }
}

template < typename T >
void Println(T a[], int len)
{
    for(int i=0; i<len; i++)
    {
        cout << a[i] << ", ";
    }

    cout << endl;
}

int main()
{
    int a[5] = {5, 3, 2, 4, 1};

    Println<int>(a, 5);
    Sort<int>(a, 5);
    Println<int>(a, 5);

    string s[5] = {"Java", "C++", "Pascal", "Ruby", "Basic"};

    Println<string>(s, 5);
    Sort<string>(s, 5);
    Println<string>(s, 5);

    return 0;
}


