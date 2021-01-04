//
// Created by dream on 2021/1/4.
//

#include <iostream>
#include <string>
using namespace std;
class Int {
    int x;

public:
    Int(int x_in = 0)
            : x{ x_in }
    {
        cout << "Conversion Ctor called" << endl;
    }
    operator string()
    {
        cout << "Conversion Operator" << endl;
        return to_string(x);
    }
};

void test_1(){
    Int obj(3);             // Int 对象，调用构造函数

    string str = obj;       // Int -> string 对象 ，相当于 string str = obj.string(obj)
    obj = 20;               // 隐式类型转换，20 --> Int(20)，调用构造函数

    string str2 = static_cast<string>(obj);     // Int -> string 对象，相当于string str2 = obj.string(obj)
    obj = static_cast<Int>(30);     // 显示强制类型转换， 30 --> Int(30)，调用构造函数
}


class Base {

};
class Derived : public Base {

};
void test_2()
{
    Derived d1;
    Base* b1 = (Base*)(&d1); // allowed
    Base* b2 = static_cast<Base*>(&d1);

}

int main()
{
    test_2();
    return 0;
}
