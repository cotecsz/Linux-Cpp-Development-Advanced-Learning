//
// Created by dream on 2020/11/20.
//

#ifndef CPP_EXERCISE_18_3_THISPOINTER_H
#define CPP_EXERCISE_18_3_THISPOINTER_H

typedef void Demo;

Demo* Demo_Create(int i, int j);
int Demo_GetI(Demo* pThis);
int Demo_GetJ(Demo* pThis);
int Demo_Add(Demo* pThis, int value);
void Demo_Free(Demo* pThis);


#endif //CPP_EXERCISE_18_3_THISPOINTER_H
