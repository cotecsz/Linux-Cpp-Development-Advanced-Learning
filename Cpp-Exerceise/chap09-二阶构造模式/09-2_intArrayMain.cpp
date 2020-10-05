//
// Created by Yang Shuangzhen on 2020/9/27.
//


#include <stdio.h>
#include "09-2_intArray.h"

int main()
{
    //IntArray a(5);

    IntArray* a = IntArray::NewInstance(5);
    
    printf("a.length = %d\n", a->length());

    a->set(0, 1);

    for(int i=0; i<a->length(); i++)
    {
        int v = 0;

        a->get(i, v);

        printf("a[%d] = %d\n", i, v);
    }

    delete a;

    return 0;
}

