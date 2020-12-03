//
// Created by dream on 2020/12/3.
//

#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
    virtual string type()
    {
        return "Base";
    }
};

class Derived : public Base
{
public:
    string type()
    {
        return "Derived";
    }

    void printf()
    {
        cout << "I'm a Derived." << endl;
    }
};

class Child : public Base
{
public:
    string type()
    {
        return "Child";
    }
};

void test(Base* b)
{
    /* 危险的转换方式 */
//     Derived* d = static_cast<Derived*>(b);

    if( b->type() == "Derived" )
    {
        Derived* d = static_cast<Derived*>(b);

        d->printf();
    }

//     cout << dynamic_cast<Derived*>(b) << endl;
}


int main(int argc, char *argv[])
{
    Base b;
    Derived d;
    Child c;

    test(&b);
    test(&d);
    test(&c);

    return 0;
}

