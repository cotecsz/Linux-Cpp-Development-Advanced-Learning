//
// Created by dream on 2020/11/22.
//

#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base::Base()" << endl;
    }

    virtual ~Base()
    {
        cout << "Base::~Base()" << endl;
    }
};

class Derived : public Base
{
};

int main()
{
    // p 指针指向子类对象
    Base* p = new Derived;
    // p 指针指向父类对象，强制转换为子类对象，则会转换失败，所以在强制转换后，需要判断是否转换成功
//    Base* p = new Base;

    Derived* pd = dynamic_cast<Derived*>(p);

    if( pd != NULL )
    {
        cout << "pd = " << pd << endl;
    }
    else
    {
        cout << "Cast error!" << endl;
    }

    delete p;

    return 0;
}


