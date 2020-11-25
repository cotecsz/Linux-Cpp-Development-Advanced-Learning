//
// Created by dream on 2020/11/25.
//

#include <iostream>
#include <vector>
#include "Array.h"
#include "HeapArray.h"
using namespace std;

int main(){
    Array<double, 5> ad;
    for (int i = 0; i < ad.length(); i++){
        ad[i] = i * i;
    }

    for (int i = 0; i < ad.length(); i++){
        cout << ad[i] << endl;
    }

    HeapArray<char>* pai = HeapArray<char>::NewInstance(10);

    if( pai != NULL )
    {
        HeapArray<char>& ai = pai->self();

        for(int i=0; i<ai.length(); i++)
        {
            ai[i] = i + 'a';
        }

        for(int i=0; i<ai.length(); i++)
        {
            cout << ai[i] << endl;
        }
    }

    delete pai;

    return 0;
}