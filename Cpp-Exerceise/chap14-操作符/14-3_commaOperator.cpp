//
// Created by Yang Shuangzhen on 2020/10/11.
//

#include <iostream>
#include <string>

using namespace std;

void func(int i)
{
    cout << "func() : i = " << i << endl;
}

int main()
{
    int a[3][3] = {
            (0, 1, 2),      // 因为有括号，所以为逗号表达式
            (3, 4, 5),      // 逗号表达式值为最后一个数
            (6, 7, 8)       // 修改为 {}
    };

    int i = 0;
    int j = 0;

    while( i < 5 )
        func(i),

                i++;

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cout << a[i][j] << endl;
        }
    }

    (i, j) = 6;

    cout << "i = " << i << endl;
    cout << "j = " << j << endl;

    return 0;
}
