//
// Created by Yang Shuangzhen on 2020/10/19.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    short s = 'a';
    unsigned int ui = 1000;
    int i = -2000;
    double d = i;

    cout << "d = " << d << endl;
    cout << "ui = " << ui << endl;
    cout << "ui + i = " << ui + i << endl;

    // i 转换为 unsign int
    if( (ui + i) > 0 )
    {
        cout << "Positive" << endl;
    }
    else
    {
        cout << "Negative" << endl;
    }

    // 转换为 int
    cout << "sizeof(s + 'b') = " << sizeof(s + 'b') << endl;

    return 0;
}

