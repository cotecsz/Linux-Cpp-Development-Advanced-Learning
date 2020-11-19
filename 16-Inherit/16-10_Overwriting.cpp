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

    void add(int i)
    {
        mi += i;
    }

    void add(int a, int b)
    {
        mi += (a + b);
    }

    void print()
    {
        cout << "I'm Parent." << endl;
    }
};

class Child : public Parent
{
public:
    int mv;

    void add(int x, int y, int z)
    {
        mv += (x + y + z);
    }

    void print()
    {
        cout << "I'm Child." << endl;
    }
};

void how_to_print(Parent* p)
{
    p->print();
}

int main()
{
    Parent p;
    Child c;

    how_to_print(&p);    // Expected to print: I'm Parent.
    how_to_print(&c);    // Expected to print: I'm Child.

    return 0;
}
