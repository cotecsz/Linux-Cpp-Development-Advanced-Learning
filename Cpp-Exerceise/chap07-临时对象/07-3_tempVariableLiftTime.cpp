//
// Created by Yang Shuangzhen on 2020/10/3.
//

#include <stdio.h>

class Test
{
    int mi;
public:
    explicit Test(int i)
    {
        printf("Test(int i) : %d\n", i);
        mi = i;
    }
    Test(const Test& t)
    {
        printf("Test(const Test& t) : %d\n", t.mi);
        mi = t.mi;
    }
    Test()
    {
        printf("Test()\n");
        mi = 0;
    }
    int print()
    {
        printf("mi = %d\n", mi);
    }
    ~Test()
    {
        printf("~Test()\n");
    }
};

// 临时对象作为返回值
Test func()
{
    return Test(20);
}

// 临时对象作为参数
Test func1(Test a)
{
    return Test(20);
}

// 对象作为返回值
Test func2(Test a)
{
    return a;
}
int main()
{
    Test t = Test(10);      // ==> Test t = 10;
    // Test tt = func();         // ==> Test tt = Test(20); ==> Test tt = 20;
    // Test tt = func1(t);
    Test tt = func2(t);

    t.print();
    tt.print();

    return 0;
}

