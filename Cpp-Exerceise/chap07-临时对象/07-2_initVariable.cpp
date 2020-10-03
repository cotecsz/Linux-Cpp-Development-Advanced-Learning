//
// Created by Yang Shuangzhen on 2020/10/3.
//

#include <stdio.h>

class Test {
    int mi;

    void init(int i)
    {
        mi = i;
    }
public:
    Test(int i) {
        init(i);
    }
    Test() {
        init(0);
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
