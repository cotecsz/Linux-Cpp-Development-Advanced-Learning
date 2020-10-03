//
// Created by Yang Shuangzhen on 2020/10/3.
//

#include <stdio.h>
/*
 * Test() 构造函数中调用Test(0) ,仅仅创建了临时对象，并不是调用Test(int i)
 *
 */
class Test {
    int mi;
public:
    Test(int i) {
        mi = i;
    }
    Test() {
        Test(0);
    }
    void print() {
        printf("mi = %d\n", mi);
    }
};


int main()
{
    Test t;

    t.print();

    return 0;
}


