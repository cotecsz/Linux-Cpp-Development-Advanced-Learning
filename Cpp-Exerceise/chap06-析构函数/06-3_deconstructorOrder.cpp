//
// Created by Yang Shuangzhen on 2020/10/4.
//

#include <stdio.h>

class Member
{
    const char* ms;
public:
    Member(const char* s)
    {
        printf("Member(const char* s): %s\n", s);

        ms = s;
    }
    ~Member()
    {
        printf("~Member(): %s\n", ms);
    }
};

class Test
{
    Member mA;
    Member mB;
public:
    Test() : mB("mB"), mA("mA")
    {
        printf("Test()\n");
    }
    ~Test()
    {
        printf("~Test()\n");
    }
};

Member gA("gA");

int main()
{
    Test t;

    return 0;
}
