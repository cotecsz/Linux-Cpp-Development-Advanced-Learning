//
// Created by dream on 2020/11/20.
//

#include "stdio.h"
#include "18-5_CPolymorphic.h"

void run(Demo* p, int v)
{
    int r = Demo_Add(p, v);

    printf("r = %d\n", r);
}

int main()
{
    Demo* pb = Demo_Create(1, 2);
    Derived* pd = Derived_Create(1, 22, 333);

    printf("pb->add(3) = %d\n", Demo_Add(pb, 3));
    printf("pd->add(3) = %d\n", Derived_Add(pd, 3));

    run(pb, 3);
    run(pd, 3);

    Demo_Free(pb);
    Demo_Free(pd);

    return 0;
}