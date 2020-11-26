//
// Created by dream on 2020/11/26.
//

#include "smartPointer.h"
#include <iostream>
using namespace std;


class Test{
public:
    Test(int val): i(val){
        cout << "Test(int val) " << endl;
    }
    int value(){
        return i;
    }
    ~Test(){
        cout << "~Test()" << endl;
    }
private:
    int i;
};

int main(){
    SmartPointer<Test> p = new Test(0);
    cout << p->value() << endl;

    SmartPointer<Test> p2 = p;
    cout << p.isNull() << endl;
    cout << p2.isNull() << endl;

    return 0;
}