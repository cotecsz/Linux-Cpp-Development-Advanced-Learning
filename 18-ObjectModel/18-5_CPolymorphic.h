//
// Created by dream on 2020/11/20.
//

#ifndef CPP_EXERCISE_18_5_CPOLYMORPHIC_H
#define CPP_EXERCISE_18_5_CPOLYMORPHIC_H

typedef void Demo;
typedef void Derived;

Demo* Demo_Create(int i, int j);
int Demo_GetI(Demo* pThis);
int Demo_GetJ(Demo* pThis);
int Demo_Add(Demo* pThis, int value);
void Demo_Free(Demo* pThis);

Derived* Derived_Create(int i, int j, int k);
int Derived_GetK(Derived* pThis);
int Derived_Add(Derived* pThis, int value);

#endif //CPP_EXERCISE_18_5_CPOLYMORPHIC_H
