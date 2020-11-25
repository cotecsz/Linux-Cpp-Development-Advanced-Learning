//
// Created by dream on 2020/11/25.
//

#include <iostream>
#include <string>
#include "22-2_PracticalClassTemplate.h"

using namespace std;


int main()
{
    Operator<int> op1;

    cout << op1.add(1, 2) << endl;
    cout << op1.multiply(4, 5) << endl;
    cout << op1.minus(5, 6) << endl;
    cout << op1.divide(10, 5) << endl;

    return 0;
}

