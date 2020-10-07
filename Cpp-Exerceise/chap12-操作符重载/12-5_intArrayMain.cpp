//
// Created by Yang Shuangzhen on 2020/9/27.
//


#include <stdio.h>
#include "12-5_intArray.h"

int main()
{

    IntArray* a = IntArray::NewInstance(5);

    if (a != nullptr){
        IntArray& array = a->self();
        // printf("a.length = %d\n", a->length());
        printf("a.length = %d\n", array.length());

        // a->set(0, 1);
        array.set(0,1 );

        for(int i=0; i<a->length(); i++)
        {
            // printf("a[%d] = %d\n", i, (*a)[i]);
            printf("a[%d] = %d\n", i, array[i]);
        }

        delete a;
    }


    return 0;
}

