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
    explicit  Test(int i = 0)
    {
        mValue = i;
    }
    int value()
    {
        return mValue;
    }
    operator int ()
    {
        return mValue;
    }
};

int main()
{
    Test t(100);
    // 隐式类型转换
    int i = t;      // int i = t.operator int();

    cout << "t.value() = " << t.value() << endl;
    cout << "i = " << i << endl;

    return 0;
}
