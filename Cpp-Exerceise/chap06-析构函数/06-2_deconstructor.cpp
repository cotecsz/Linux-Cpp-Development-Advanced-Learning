//
// Created by Yang Shuangzhen on 2020/10/3.
//

#include <stdio.h>

class Test
{
    int mi;
public:
    Test(int i)
    {
        mi = i;
        printf("Test(): %d\n", mi);
    }
    ~Test()
    {
        printf("~Test(): %d\n", mi);
    }
};

int main()
{
    Test t(1);   // 构造 Test(1)

    Test* pt = new Test(2); // 构造Test(2)

    delete pt;      // 析构Test(2)
                    // 析构Test(1)
    return 0;
}
