//
// Created by Yang Shuangzhen on 2020/9/27.
//

#include <stdio.h>

class Test
{
public:
    Test()
    {
        printf("Test()\n");
    }
    Test(int v)
    {
        printf("Test(int v), v = %d\n", v);
    }
};

int main()
{
    Test t;      // 调用 Test()
    Test t1(1);  // 调用 Test(int v)
    Test t2 = 2; // 调用 Test(int v)

    int i(100);

    printf("i = %d\n", i);

    return 0;
}


