//
// Created by dream on 2020/12/3.
//

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Base
{
public:
    virtual ~Base()
    {
    }
};

class Derived : public Base
{
public:
    void printf()
    {
        cout << "I'm a Derived." << endl;
    }
};

void test(Base* b)
{
    const type_info& tb = typeid(*b);

    cout << tb.name() << endl;
}

int main(int argc, char *argv[])
{
    int i = 0;

    const type_info& tiv = typeid(i);
    const type_info& tii = typeid(int);

    cout << (tiv == tii) << endl;

    Base b;
    Derived d;

    test(&b);
    test(&d);

    return 0;
}

