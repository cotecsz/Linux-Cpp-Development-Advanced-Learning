//
// Created by Yang Shuangzhen on 2020/9/27.
//


#include <stdio.h>
#include "03-4_intArray.h"

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

    a.free();

    return 0;
}

