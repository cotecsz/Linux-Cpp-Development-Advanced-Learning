//
// Created by Yang Shuangzhen on 2020/10/4.
//

#include <stdio.h>

class Test
{
    int mi;
public:
    Test(int i);
    Test(const Test& t);
    int getMi() ;
};

Test::Test(int i)
{
    mi = i;
}

Test::Test(const Test& t)
{
    // const 对象不能调用非const成员变量
    mi = t.getMi();
}

int Test::getMi()
{
    return mi;
}

int main()
{
    const Test t(1);
    // const 对象不能调用非 const 成员函数
    printf("t.getMi() = %d\n", t.getMi());
    return 0;
}

