//
// Created by dream on 2021/1/4.
//

#include <iostream>
using namespace std;

class student
{
private:
    int roll;
public:
    // constructor
    student(int r):roll(r) {}

    // A const function that changes roll with the help of const_cast
    void fun() const
    {
        ( const_cast <student*> (this) )->roll = 5;
    }

    int getRoll() { return roll; }
};

void test_1(){
    student s(3);
    cout << "Old roll number: " << s.getRoll() << endl;

    s.fun();

    cout << "New roll number: " << s.getRoll() << endl;

}


#include <iostream>
using namespace std;

//int fun(int* ptr)
//{
//    *ptr = *ptr + 10;
//    return (*ptr);
//}
//
//int main(void)
//{
//    const int val = 10;
//    const int *ptr = &val;
//    int *ptr1 = const_cast <int *>(ptr);
//    fun(ptr1);
//    cout << val;
//
//    const int v = 10;
//    int a = 20;
//    const int* pv = &v;
//    int* const cpv = &a;        // const pointer to int
//
//     int* const cpcv = &a;
//    *cpcv = a;
//    pv = &a;
//    return 0;
//}

#include <iostream>
#include <typeinfo>
using namespace std;

int main(void)
{
    int a1 = 40;
    const volatile int* b1 = &a1;
    cout << "typeid of b1 " << typeid(b1).name() << '\n';
    int* c1 = const_cast <int *> (b1);
    cout << "typeid of c1 " << typeid(c1).name() << '\n';
    return 0;
}



