//
// Created by Yang Shuangzhen on 2020/10/5.
//
#include <stdio.h>

class Test
{
    int i;
public:
    Test()
    {
        printf("Test::Test()\n");
        this->i = 0;
    }

    Test(int i)
    {
        printf("Test::Test(int i)\n");
        this->i = i;
    }

    Test(const Test& obj)
    {
        printf("Test(const Test& obj)\n");
        this->i = obj.i;
    }

    static void func()
    {
        printf("void Test::func()\n");
    }

    void func(int i)
    {
        printf("void Test::func(=int i), i  %d\n", i);
    }

    int getI()
    {
        return i;
    }
};

void func()
{
    printf("void func()\n");
}

void func(int i)
{
    printf("void func(int i), i = %d\n", i);
}

int main()
{
    // 全局函数
    func();
    func(1);

    // 类的成员函数
    Test t;        // Test::Test()
    Test t1(1);    // Test::Test(int i)
    Test t2(t1);   // Test(const Test& obj)

    // 静态成员函数和全局函数
    func();        // void func()
    Test::func();  // void Test::func()

    // 成员函数和全局函数
    func(2);       // void func(int i), i = 2;
    t1.func(2);    // void Test::func(int i), i = 2
    t1.func();     // void Test::func()

    return 0;
}

