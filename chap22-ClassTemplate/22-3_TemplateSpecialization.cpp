//
// Created by dream on 2020/11/25.
//

#include <iostream>
#include <string>

using namespace std;

template
        < typename T1, typename T2 >
class Test
{
public:
    void add(T1 a, T2 b)
    {
        cout << "void add(T1 a, T2 b)" << endl;
        cout << a + b << endl;
    }
};

// 模板特化
template
        < typename T1, typename T2 >
class Test < T1*, T2* >      // 关于指针的特化实现
{
public:
    void add(T1* a, T2* b)
    {
        cout << "void add(T1* a, T2* b)" << endl;
        cout << *a + *b << endl;
    }
};

// 部分特化，约束实现（T1 = T2）
template
        < typename T >
class Test < T, T >    // 当 Test 类模板的两个类型参数完全相同时，使用这个实现
{
public:
    void add(T a, T b)
    {
        cout << "void add(T a, T b)" << endl;
        cout << a + b << endl;
    }
    void print()
    {
        cout << "class Test < T, T >" << endl;
    }
};

// 完全特化，当 T1 == void* 并且 T2 == void* 时
template
        <  >
class Test < void*, void* >    // 当 T1 == void* 并且 T2 == void* 时
{
public:
    void add(void* a, void* b)
    {
        cout << "void add(void* a, void* b)" << endl;
        cout << "Error to add void* param..." << endl;
    }
};

int main()
{
    Test<int, float> t1;
    Test<long, long> t2;
    Test<void*, void*> t3;

    t1.add(1, 2.5);

    t2.add(5, 5);
    t2.print();

    t3.add(NULL, NULL);

    Test<int*, double*> t4;
    int a = 1;
    double b = 0.1;

    t4.add(&a, &b);

    return 0;
}

