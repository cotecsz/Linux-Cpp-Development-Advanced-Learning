//
// Created by Yang Shuangzhen on 2020/10/3.
//

#include <stdio.h>

class Test{
public:
    //Test(){}
//    Test(){
//        ci = 10;
//    }
    Test(): ci(10){}
    int getI(){
        return ci;
    }
private:
    const int ci;
};


int main(){
    Test t;
    printf("t.ci = %d \n", t.getI());
    return 0;
}