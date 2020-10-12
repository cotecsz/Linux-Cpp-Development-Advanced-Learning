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
    Test(int i)
    {
        mValue = i;
    }
    int value()
    {
        return mValue;
    }
};

Test& operator , (const Test& a, const Test& b)
{
    return const_cast<Test&>(b);
}

Test func(Test& i)
{
    cout << "func() : i = " << i.value() << endl;

    return i;
}

int main()
{
    Test t0(0);
    Test t1(1);
    // Test tt = (func(t0), func(t1));         // Test tt = func(t1);
    Test tt = (operator ,(func(t0), func(t1))) ;       // 重载逗号表达式函数：作为参数，从右向左计算
    cout << tt.value() << endl; // 1

    return 0;
}
