//
// Created by dream on 2020/11/18.
//
#include <iostream>
#include <string>

using namespace std;

class Parent
{
    int mv;
public:
    Parent()
    {
        cout << "Parent()" << endl;
        mv = 100;
    }
    void method()
    {
        cout << "mv = " << mv << endl;
    }
};

class Child : public Parent
{
public:
    Child(){
        cout << "Child()" << endl;
    }
    void hello()
    {
        cout << "I'm Child calss!" << endl;
    }
};

int main()
{
    Child c;

    c.hello();
    c.method();

    return 0;
}


