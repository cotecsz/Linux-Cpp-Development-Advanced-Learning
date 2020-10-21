//
// Created by Yang Shuangzhen on 2020/10/19.
//

#include <iostream>
#include <string>

using namespace std;

class Test
{
    int mValue;
public:
    Test()
    {
        mValue = 0;
    }

    explicit Test(int i)
    {
        mValue = i;
    }

    Test operator + (const Test& p)
    {
        Test ret(mValue + p.mValue);

        return ret;
    }

    int value()
    {
        return mValue;
    }
};

int main()
{
    Test t;

    t = static_cast<Test>(5);    // t = Test(5);

    Test r;

    r = t + static_cast<Test>(10);   // r = t + Test(10);

    cout << r.value() << endl;

    return 0;
}

