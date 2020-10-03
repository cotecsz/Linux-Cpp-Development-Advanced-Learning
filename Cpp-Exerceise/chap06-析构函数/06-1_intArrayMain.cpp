//
// Created by Yang Shuangzhen on 2020/9/27.
//


#include <stdio.h>
#include "06-1_intArray.h"

int main()
{
    IntArray a(5);

    for(int i=0; i<a.length(); i++)
    {
        a.set(i, i + 1);
    }

    for(int i=0; i<a.length(); i++)
    {
        int value = 0;

        if( a.get(i, value) )
        {
            printf("a[%d] = %d\n", i, value);
        }
    }

    // a.free();

    IntArray b = a;
    for(int i=0; i<b.length(); i++)
    {
        int value = 0;

        if( b.get(i, value) )
        {
            printf("b[%d] = %d\n", i, value);
        }
    }

    // b.free();
    return 0;
}

