//
// Created by dream on 2020/11/19.
//

#include <iostream>
#include <string>

using namespace std;

class Parent
{
protected:
    int mv;
public:
    Parent()
    {
        mv = 100;
    }

    int value()
    {
        return mv;
    }
};

class Child : public Parent
{
public:
    int addValue(int v)
    {
        mv = mv + v;
    }
};

int main()
{
    Parent p;

    cout << "p.mv = " << p.value() << endl;

    // p.mv = 1000;    // error

    Child c;

    cout << "c.mv = " << c.value() << endl;

    c.addValue(50);

    cout << "c.mv = " << c.value() << endl;

    // c.mv = 10000;  // error

    return 0;
}
