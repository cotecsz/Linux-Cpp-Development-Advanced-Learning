//
// Created by dream on 2021/1/6.
//

#include <iostream>
using namespace std;



class Test{
public:
    static const int v;
    int a;
    int b;
};

class Test_const{
public:
    int getVar(){
        return var;
    }

    int getVar() const{
        cout << "int getVar() const" << endl;
        return var;
    }

private:
    int var;
};



void constPointer(){
    const int i = 10;
    const int* pci = &i;

    const int j = 20;
    pci = &j;


    int const* pci1 = &i;
    pci1 = &j;
    cout << *pci<< endl;
    cout << *pci1 << endl;

    int k = 99;
    int * const cpi = &k;
    *cpi = 9;
    cout << *cpi << endl;
}

const int Test::v = 10;


const  volatile int var = 10;
 int g_i = 11;
 const static int csi  = 12;
int main(){
//    int j = 6;
//    cout << &j << endl;
//
//    cout << (int*)&var << endl;
//    cout << &g_i << endl;
//    cout << &csi << endl;
//    int* pvar = (int*)(&var);
//    *pvar = 99;
//    cout << pvar << endl;
//    cout << *pvar << endl;

//    Test t = Test();
//
//    const int* p = &t.v;
//
//
//    const Test_const ct = Test_const();
//    cout << ct.getVar() << endl;

//    constPointer();


    Test a = Test();
    Test& b = a;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    return 0;
}