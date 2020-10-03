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

    int getI(){
        return mi;
    }
};

int main()
{
    int i = 0;
    Test a1 = i;

    while( i < 3 )
    {
        Test a2 = ++i;
    }

    goto End;
    if( i < 4 )
    {
        Test a = a1;
    }
    else
    {
        Test a(100);
    }
End:
    //printf("a.i = %d\n", a.getI());
    return 0;
}
