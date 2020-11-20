//
// Created by dream on 2020/11/20.
//

#include <stdio.h>
#include "18-3_thisPointer.h"

int main()
{
    Demo* d = Demo_Create(1, 2);             // Demo* d = new Demo(1, 2);

    printf("d.mi = %d\n", Demo_GetI(d));     // d->getI();
    printf("d.mj = %d\n", Demo_GetJ(d));     // d->getJ();
    printf("Add(3) = %d\n", Demo_Add(d, 3));    // d->add(3);

    // d->mi = 100;

    Demo_Free(d);

    return 0;
}