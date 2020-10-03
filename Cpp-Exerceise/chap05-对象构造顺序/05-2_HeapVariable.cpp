//
// Created by Yang Shuangzhen on 2020/10/3.
//

#include <stdio.h>

class Test
{
private:
    int mi;
public:
    Test(int i)
    {
        mi = i;
        printf("Test(int i): %d\n", mi);
    }
    Test(const Test& obj)
    {
        mi = obj.mi;
        printf("Test(const Test& obj): %d\n", mi);
    }
    int getMi()
    {
        return mi;
    }
};

int main()
{
    int i = 0;
    Test* a1 = new Test(i); // Test(int i): 0

    while( ++i < 10 )
        if( i % 2 )
            new Test(i); // Test(int i): 1, 3, 5, 7, 9

    if( i < 4 )
        new Test(*a1);
    else
        new Test(100); // Test(int i): 100

    return 0;
}

