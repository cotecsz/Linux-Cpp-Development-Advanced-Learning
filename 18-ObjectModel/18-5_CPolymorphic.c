//
// Created by dream on 2020/11/20.
//

#include "18-5_CPolymorphic.h"
#include "malloc.h"

static int Demo_Virtual_Add(Demo* pThis, int value);
static int Derived_Virtual_Add(Demo* pThis, int value);

struct VTable     // 2. 定义虚函数表数据结构
{
    int (*pAdd)(void*, int);   // 3. 虚函数表里面存储什么？？？
};

struct ClassDemo
{
    struct VTable* vptr;     // 1. 定义虚函数表指针  ==》 虚函数表指针类型？？？
    int mi;
    int mj;
};

struct ClassDerived
{
    struct ClassDemo d;
    int mk;
};


// static 关键字可以隐藏变量，外部不可访问
static struct VTable g_Demo_vtbl =
        {
                Demo_Virtual_Add
        };

static struct VTable g_Derived_vtbl =
        {
                Derived_Virtual_Add
        };

Demo* Demo_Create(int i, int j)
{
    struct ClassDemo* ret = (struct ClassDemo*)malloc(sizeof(struct ClassDemo));

    if( ret != NULL )
    {
        ret->vptr = &g_Demo_vtbl;   // 4. 关联对象和虚函数表
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

// 6. 定义虚函数表中指针所指向的具体函数
static int Demo_Virtual_Add(Demo* pThis, int value)
{
    struct ClassDemo* obj = (struct ClassDemo*)pThis;

    return obj->mi + obj->mj + value;
}


// 5. 分析具体的虚函数！！！！
int Demo_Add(Demo* pThis, int value)
{

    struct ClassDemo* obj = (struct ClassDemo*)pThis;

    return obj->vptr->pAdd(pThis, value);
}

void Demo_Free(Demo* pThis)
{
    free(pThis);
}

Derived* Derived_Create(int i, int j, int k)
{
    struct ClassDerived* ret = (struct ClassDerived*)malloc(sizeof(struct ClassDerived));

    if( ret != NULL )
    {
        ret->d.vptr = &g_Derived_vtbl;
        ret->d.mi = i;
        ret->d.mj = j;
        ret->mk = k;
    }

    return ret;
}

int Derived_GetK(Derived* pThis)
{
    struct ClassDerived* obj = (struct ClassDerived*)pThis;

    return obj->mk;
}

static int Derived_Virtual_Add(Demo* pThis, int value)
{
    struct ClassDerived* obj = (struct ClassDerived*)pThis;

    return obj->mk + value;
}

int Derived_Add(Derived* pThis, int value)
{
    struct ClassDerived* obj = (struct ClassDerived*)pThis;

    return obj->d.vptr->pAdd(pThis, value);
}