//
// Created by Yang Shuangzhen on 2020/10/19.
//
#include <iostream>
#include <string>

using namespace std;

class Test;

class Value
{
public:
    Value()
    {
    }
    explicit Value(Test& t)
    {
    }
};

class Test
{
    int mValue;
public:
    Test(int i = 0)
    {
        mValue = i;
    }
    int value()
    {
        return mValue;
    }
    operator Value()
    {
        Value ret;
        cout << "operator Value()" << endl;
        return ret;
    }
};

int main()
{
    Test t(100);
    Value v = t;

    return 0;
}

