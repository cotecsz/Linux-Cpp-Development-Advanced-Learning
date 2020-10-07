//
// Created by Yang Shuangzhen on 2020/10/7.
//

#include <iostream>
#include <string>

using namespace std;

class Test
{
    int* m_pointer;
public:
    Test()
    {
        m_pointer = NULL;
    }
    Test(int i)
    {
        m_pointer = new int(i);
    }

    // 拷贝构造函数
    Test(const Test& obj)
    {
        printf("Test(const Test& obj)\n");
        m_pointer = new int(*obj.m_pointer);
    }
    /*
     *
     * 赋值操作符重载
     *     1. 返回值为引用类型
     *     2. 参数为 const 引用类型
     *     3. 避免自赋值
     *     4. 返回当前对象
     *
     */
    Test& operator = (const Test& obj)
    {
        printf("Test& operator = (const Test& obj)\n");
        if( this != &obj )
        {
            delete m_pointer;
            m_pointer = new int(*obj.m_pointer);
        }

        return *this;
    }
    void print()
    {
        cout << "m_pointer = " << hex << m_pointer << endl;
    }
    ~Test()
    {
        delete m_pointer;
    }
};

int main()
{
    Test t1 = 1;
    Test t2 = t1;

    t2 = t1;

    t1.print();
    t2.print();

    return 0;
}
