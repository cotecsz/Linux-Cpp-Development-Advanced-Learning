//
// Created by Yang Shuangzhen on 2020/10/11.
//

#include <iostream>
#include <string>

using namespace std;

class Test
{
    int mValue;
public:
    Test(int v)
    {
        mValue = v;
    }
    int value() const
    {
        return mValue;
    }
};

bool operator && (const Test& l, const Test& r)
{
    return l.value() && r.value();
}

bool operator || (const Test& l, const Test& r)
{
    return l.value() || r.value();
}

Test func(Test i)
{
    cout << "Test func(Test i) : i.value() = " << i.value() << endl;

    return i;
}

int main()
{
    Test t0(0);
    Test t1(1);

    if( func(t0) && func(t1) )
    {
        cout << "Result is true!" << endl;
    }
    else
    {
        cout << "Result is false!" << endl;
    }

    cout << endl;

    if( func(1) || func(0) )
    {
        cout << "Result is true!" << endl;
    }
    else
    {
        cout << "Result is false!" << endl;
    }

    return 0;
}
