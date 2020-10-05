//
// Created by Yang Shuangzhen on 2020/10/5.
//

#include <stdio.h>

class Demo
{
private:
    int i;
public:
    int getI();
    static void StaticFunc(const char* s);
    static void StaticSetI(Demo& d, int v);
};

int Demo::getI()
{
    return i;
}

void Demo::StaticFunc(const char* s)
{
    printf("StaticFunc: %s\n", s);
}

void Demo::StaticSetI(Demo& d, int v)
{
    d.i = v;
}

int main()
{
    Demo::StaticFunc("main Begin...");

    Demo d;

    Demo::StaticSetI(d, 10);

    printf("d.i = %d\n", d.getI());

    Demo::StaticFunc("main End...");

    return 0;
}
