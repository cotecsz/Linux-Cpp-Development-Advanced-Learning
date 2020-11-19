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
};

class Child : public Parent
{
public:
    int mv;

    void add(int x, int y, int z)
    {
        mv += (x + y + z);
    }
};

int main()
{
    Parent p;
    Child c;

    p = c;

    Parent p1(c);


    Parent& rp = c;
    Parent* pp = &c;

    rp.mi = 100;
    rp.add(5);             // 没有发生同名覆盖?  子类对象退化为父类对象， 可以直接调用父类成员
    rp.add(10, 10);        // 没有发生同名覆盖?

    /* 为什么编译不过? */
    // pp->mv = 1000;
    // pp->add(1, 10, 100);

    return 0;
}
