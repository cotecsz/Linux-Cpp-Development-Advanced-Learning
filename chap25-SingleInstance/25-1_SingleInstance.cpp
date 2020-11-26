//
// Created by dream on 2020/11/26.
//

#include <iostream>
#include <string>
using namespace std;

class SingleInstance{
public:
    void print(){
        cout << "this = " << this << endl;
    }

    // 静态成员函数，返回对象
    static SingleInstance* GetInstance();

private:
    // 构造函数、拷贝构造函数、赋值构造函数
    SingleInstance(){

    }
    SingleInstance(const SingleInstance&);
    SingleInstance& operator=(const SingleInstance&);

    // 静态成员变量，需要在类外进行定义
    static SingleInstance* c_instance;
};


// 1. 定义 c_instance ，并设置为空
SingleInstance* SingleInstance::c_instance = nullptr;

SingleInstance* SingleInstance::GetInstance() {
    // 2. 当 c_instance 不存在时，创建对象，否则返回对象
    if (c_instance == nullptr){
        c_instance = new SingleInstance();
    }
    return c_instance;
}

// 3. 单例模式没有析构函数，因为单例模式在系统生命周期中都是存在的。

int main(){

    SingleInstance* s = SingleInstance::GetInstance();
    s->print();

    SingleInstance* s1 = SingleInstance::GetInstance();
    SingleInstance* s2 = SingleInstance::GetInstance();

    s1->print();
    s2->print();
    return 0;
}