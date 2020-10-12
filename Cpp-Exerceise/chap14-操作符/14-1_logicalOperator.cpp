//
// Created by Yang Shuangzhen on 2020/10/11.
//

#include <iostream>
#include <string>

using namespace std;

int func(int i)
{
    cout << "int func(int i) : i = " << i << endl;

    return i;
}

int main()
{
    if( func(0) && func(1) )
    {
        cout << "Result is true!" << endl;
    }
    else
    {
        cout << "Result is false!" << endl;
    }

    cout << endl;

    if( func(0) || func(1) )
    {
        cout << "Result is true!" << endl;
    }
    else
    {
        cout << "Result is false!" << endl;
    }

    return 0;
}
