//
// Created by dream on 2020/11/22.
//

#include <iostream>
#include <string>

using namespace std;

class BaseA
{
public:
    virtual void funcA()
    {
        cout << "BaseA::funcA()" << endl;
    }
};

class BaseB
{
public:
    virtual void funcB()
    {
        cout << "BaseB::funcB()" << endl;
    }
};

class Derived : public BaseA, public BaseB
{

};

int main()
{
    Derived d;
    BaseA* pa = &d;
    BaseB* pb = &d;

    cout << "sizeof(d) = " << sizeof(d) << endl;

    cout << "Using pa to call funcA()..." << endl;

    pa->funcA();

    cout << "Using pb to call funcB()..." << endl;

    pb->funcB();

    BaseB* pbe = (BaseB*)pa;    // oops!!
    BaseB* pbc = dynamic_cast<BaseB*>(pa);

    cout << "Using pbc to call funcB()..." << endl;

    pbc->funcB();

    cout << endl;

    cout << "pa = " << pa << endl;
    cout << "pb = " << pb << endl;
    cout << "pbe = " << pbe << endl;
    cout << "pbc = " << pbc << endl;

    return 0;
}
