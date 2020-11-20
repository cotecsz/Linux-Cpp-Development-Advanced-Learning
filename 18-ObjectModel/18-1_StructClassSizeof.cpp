//
// Created by dream on 2020/11/20.
//

#include <iostream>
#include <string>

using namespace std;

class A
{
    int i;
    int j;
    char c;
    double d;
public:
    void print()
    {
        cout << "i = " << i << ", "
             << "j = " << j << ", "
             << "c = " << c << ", "
             << "d = " << d << endl;
    }
};

struct B
{
    int i;
    int j;
    char c;
    double d;
};

int main()
{
    A a;

    cout << "sizeof(A) = " << sizeof(A) << endl;    // 24 bytes
    cout << "sizeof(a) = " << sizeof(a) << endl;
    cout << "sizeof(B) = " << sizeof(B) << endl;    // 24 bytes

//    a.print();

    B* p = reinterpret_cast<B*>(&a);

    p->i = 1;
    p->j = 2;
    p->c = 'c';
    p->d = 3;

    a.print();

    p->i = 100;
    p->j = 200;
    p->c = 'C';
    p->d = 3.14;

    a.print();

    return 0;
}
