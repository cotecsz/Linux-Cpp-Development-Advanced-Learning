//
// Created by dream on 2021/1/5.
//


#include <iostream>
#include "29-2_static.h"

using namespace std;

extern int g_val;
 // int g_c_staVal;
 extern int g_c_val;


 void func(){
     static int i = 10;
     i--;
 }


 static const int i = 0;
struct myS{
    int i = 10;
};
 class Test{
 public:
     static const myS c;
 };

 const myS Test::c = myS();
 // const int Test::c = 10;

int main(){
    cout << g_val << endl;
    // cout << g_sta_val << endl;
    cout << i << endl;
    cout << g_c_val << endl;

    Test t = Test();
    [[unused]]
    int j = 10;
    func();
    return 0;
}

