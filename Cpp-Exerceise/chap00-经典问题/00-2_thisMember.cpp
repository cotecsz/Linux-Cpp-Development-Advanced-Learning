//
// Created by Yang Shuangzhen on 2020/10/4.
//

#include <stdio.h>

class Test
{
    int mi;
public:
    int mj;
    Test(int i);
    Test(const Test& t);
    int getMi();
    void print();
};

Test::Test(int i)
{
    mi = i;
}

Test::Test(const Test& t)
{
    mi = t.mi;
}

int Test::getMi()
{
    return mi;
}

void Test::print()
{
    printf("this = %p\n", this);
}

int main()
{
    Test t1(1);
    Test t2(2);
    Test t3(3);

    printf("t1.getMi() = %d\n", t1.getMi());
    printf("&t1 = %p\n", &t1);
    t1.print();

    printf("t2.getMi() = %d\n", t2.getMi());
    printf("&t2 = %p\n", &t2);
    t2.print();

    printf("t3.getMi() = %d\n", t3.getMi());
    printf("&t3 = %p\n", &t3);
    t3.print();

    return 0;
}
