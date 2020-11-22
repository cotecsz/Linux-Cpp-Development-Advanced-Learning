//
// Created by dream on 2020/11/22.
//

#include <iostream>
#include <string>

using namespace std;

class BaseA
{
    int ma;
public:
    BaseA(int a)
    {
        ma = a;
    }
    int getA()
    {
        return ma;
    }
};

class BaseB
{
    int mb;
public:
    BaseB(int b)
    {
        mb = b;
    }
    int getB()
    {
        return mb;
    }
};

class Derived : public BaseA, public BaseB
{
    int mc;
public:
    Derived(int a, int b, int c) : BaseA(a), BaseB(b)
    {
        mc = c;
    }
    int getC()
    {
        return mc;
    }
    void print()
    {
        cout << "ma = " << getA() << ", "
             << "mb = " << getB() << ", "
             << "mc = " << mc << endl;
    }
};

int main()
{
    // 继承的本质是子类与父类成员变量的叠加
    cout << "sizeof(Derived) = " << sizeof(Derived) << endl;    // 12

    Derived d(1, 2, 3);

    d.print();

    // 子类继承父类的成员函数
    cout << "d.getA() = " << d.getA() << endl;
    cout << "d.getB() = " << d.getB() << endl;
    cout << "d.getC() = " << d.getC() << endl;

    cout << endl;

    // 父类指针指向子类对象，调用子类成员函数
    BaseA* pa = &d;
    BaseB* pb = &d;

    cout << "pa->getA() = " << pa->getA() << endl;
    cout << "pb->getB() = " << pb->getB() << endl;

    cout << endl;

    // 判断是否指向同一个对象
    void* paa = pa;
    void* pbb = pb;

    // 指针值不同
    if( paa == pbb )
    {
        cout << "Pointer to the same object!" << endl;
    }
    else
    {
        cout << "Error" << endl;
    }

    // pa 与 pb 指向同一个对象，但地址值不同
    cout << "pa = " << pa << endl;
    cout << "pb = " << pb << endl;
    cout << "paa = " << paa << endl;
    cout << "pbb = " << pbb << endl;

    return 0;
}
