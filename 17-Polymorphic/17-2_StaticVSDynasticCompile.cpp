//
// Created by dream on 2020/11/20.
//

#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
    virtual void func()
    {
        cout << "void func()" << endl;
    }

    virtual void func(int i)
    {
        cout << "void func(int i) : " << i << endl;
    }

    virtual void func(int i, int j)
    {
        cout << "void func(int i, int j) : " << "(" << i << ", " << j << ")" << endl;
    }
};

class Child : public Parent
{
public:
    void func(int i, int j)
    {
        cout << "void func(int i, int j) : " << i + j << endl;
    }

    void func(int i, int j, int k)
    {
        cout << "void func(int i, int j, int k) : " << i + j + k << endl;
    }
};

void run(Parent* p)
{
    p->func(1, 2);     // 展现多态的特性
    // 动态联编
}


int main()
{
    Parent p;

    p.func();         // 静态联编
    p.func(1);        // 静态联编
    p.func(1, 2);     // 静态联编

    cout << endl;

    Child c;

    c.func(1, 2);     // 静态联编

    cout << endl;

    run(&p);
    run(&c);

    return 0;
}
