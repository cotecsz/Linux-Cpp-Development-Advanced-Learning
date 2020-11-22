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
        cout << "Base()" << endl;

        func();
    }

    virtual void func()
    {
        cout << "Base::func()" << endl;
    }

    virtual  ~Base()
    {
        func();

        cout << "~Base()" << endl;
    }
};


class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived()" << endl;

        func();
    }

    virtual void func()
    {
        cout << "Derived::func()" << endl;
    }

    ~Derived()
    {
        func();

        cout << "~Derived()" << endl;
    }
};


int main()
{
    Base* p = new Derived();

    // ...

    // 没有将析构函数声明为virtual ，编译器直接调用声明的父类的析构函数，不调用子类的析构函数
    // 如果将析构函数声明为virtual ，编译器会根据指针p指向的实际对象调用析构函数，所以先调用父类的析构函数，再调用子类的析构函数（多态）
    delete p;

    return 0;
}
