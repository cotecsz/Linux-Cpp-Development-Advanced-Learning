//
// Created by Yang Shuangzhen on 2020/9/27.
//

#include <stdio.h>

class Test
{
private:
    int i;
    int j;
public:
    int getI() { return i; }
    int getJ() { return j; }
    Test()
    {
        printf("Test() Begin\n");

        i = 1;
        j = 2;

        printf("Test() End\n");
    }
};


Test gt;

int main()
{
    printf("gt.i = %d\n", gt.getI());
    printf("gt.j = %d\n", gt.getJ());

    Test t1;

    printf("t1.i = %d\n", t1.getI());
    printf("t1.j = %d\n", t1.getJ());

    Test* pt = new Test;

    printf("pt->i = %d\n", pt->getI());
    printf("pt->j = %d\n", pt->getJ());

    delete pt;

    return 0;
}
