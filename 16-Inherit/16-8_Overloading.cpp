//
// Created by dream on 2020/11/19.
//

#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
    int mi;

    void add(int v)
    {
        mi += v;
    }

    void add(int a, int b)
    {
        mi += (a + b);
    }
};

class Child : public Parent
{
public:
    int mi;

    void add(int v)
    {
        mi += v;
    }

    void add(int a, int b)
    {
        mi += (a + b);
    }

    void add(int x, int y, int z)
    {
        mi += (x + y + z);
    }
};

int main()
{
    Child c;

    c.mi = 100;

    c.Parent::mi = 1000;

    cout << "c.mi = " << c.mi << endl;

    cout << "c.Parent::mi = " << c.Parent::mi << endl;

    c.add(1);
    c.add(2, 3);
    c.add(4, 5, 6);

    cout << "c.mi = " << c.mi << endl;

    cout << "c.Parent::mi = " << c.Parent::mi << endl;

    return 0;
}