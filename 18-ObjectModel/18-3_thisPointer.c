//
// Created by dream on 2020/11/20.
//

#include "18-3_thisPointer.h"
#include "malloc.h"

struct ClassDemo
{
    int mi;
    int mj;
};

Demo* Demo_Create(int i, int j)
{
    struct ClassDemo* ret = (struct ClassDemo*)malloc(sizeof(struct ClassDemo));

    if( ret != NULL )
    {
        ret->mi = i;
        ret->mj = j;
    }

    return ret;
}

int Demo_GetI(Demo* pThis)
{
    struct ClassDemo* obj = (struct ClassDemo*)pThis;

    return obj->mi;
}

int Demo_GetJ(Demo* pThis)
{
    struct ClassDemo* obj = (struct ClassDemo*)pThis;

    return obj->mj;
}

int Demo_Add(Demo* pThis, int value)
{
    struct ClassDemo* obj = (struct ClassDemo*)pThis;

    return obj->mi + obj->mj + value;
}

void Demo_Free(Demo* pThis)
{
    free(pThis);
}