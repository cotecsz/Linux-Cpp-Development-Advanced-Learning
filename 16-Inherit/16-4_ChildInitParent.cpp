//
// Created by dream on 2020/11/19.
//

#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
    Parent()
    {
        cout << "Parent()" << endl;
    }
    Parent(string s)
    {
        cout << "Parent(string s) : " << s << endl;
    }
};

class Child : public Parent
{
public:
    Child()
    {
        cout << "Child()" << endl;
    }
    Child(string s) : Parent(s)
    {
        cout << "Child(string s) : " << s << endl;
    }
};

int main()
{
    Child c;
    Child cc("cc");

    return 0;
}
