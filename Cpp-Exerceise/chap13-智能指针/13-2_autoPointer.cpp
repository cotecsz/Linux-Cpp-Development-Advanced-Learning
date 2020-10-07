//
// Created by Yang Shuangzhen on 2020/10/7.
//
#include <iostream>

using namespace std;

class Test{
public:
    Test(int val): i(val){
        cout << "Test(int val) " << endl;
    }
    int value(){
        return i;
    }
    ~Test(){
        cout << "~Test()" << endl;
    }
private:
    int i;
};


class Pointer{
public:
    Pointer(Test* p): m_p(nullptr)  {}
    Pointer(const Pointer &obj){
        delete m_p;
        m_p = obj.m_p;
        const_cast<Pointer&>(obj).m_p = nullptr;
    }
    Pointer& operator = (const Pointer& obj){
        if (this != &obj){
            delete m_p;
            m_p = obj.m_p;
            const_cast<Pointer&>(obj).m_p = nullptr;
        }

        return *this;
    }
    Test* operator -> (){
        return m_p;
    }
    Test& operator * (){
        return *m_p;
    }

    bool isNull(){
        return m_p == nullptr;
    }
    ~Pointer(){
        delete m_p;
    }

private:
    Test* m_p;
};


int main(){
    Pointer p = new Test(0);
    cout << p->value() << endl;

    Pointer p2 = p;
    cout << p.isNull() << endl;
    cout << p2.isNull() << endl;

    return 0;
}