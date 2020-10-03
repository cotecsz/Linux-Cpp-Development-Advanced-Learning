//
// Created by Yang Shuangzhen on 2020/10/3.
//
#include <stdio.h>

class Value
{
private:
    int mi;
public:
    Value(int i)
    {
        printf("i = %d\n", i);
        mi = i;
    }
    int getI()
    {
        return mi;
    }
};

class Test
{
public:
    Test() : ci(10), m1(1), m2(2), m3(3)
    {
        printf("Test::Test()\n");
    }

    int getCI(){
        return ci;
    }

    int setCI(int v){
        int* p = const_cast<int*> (&ci);
        *p = v;
    }

private:
    const int ci;
    Value m2;
    Value m3;
    Value m1;
};

int main(){
    Test t;
    printf("t.ci = %d\n", t.getCI());

    t.setCI(20);
    printf("t.ci = %d\n", t.getCI());

    return 0;
}
