//
// Created by dream on 2020/11/22.
//

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Test
{
    int* mp;
public:
    Test()
    {
        cout << "Test::Test()" << endl;

        mp = new int(100);

        cout << *mp << endl;
    }
    ~Test()
    {
        delete mp;

        cout << "~Test::Test()" << endl;
    }
};

int main()
{
    // new 在分配空间后，调用构造函数对对象进行初始化
    // malloc 仅仅分配空间，并没有初始化对象
    // 所以，当类中含有指针对象时，
    Test* pn = new Test;
    Test* pm = (Test*)malloc(sizeof(Test));

    // 动态删除对象，调用析构函数
    delete pn;
    // 内存泄漏,仅仅释放内存，并没有析构对象
    // free (pn);
    free(pm);

    return 0;
}
