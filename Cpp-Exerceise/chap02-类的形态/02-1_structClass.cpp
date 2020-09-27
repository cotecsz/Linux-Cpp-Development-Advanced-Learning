//
// Created by Yang Shuangzhen on 2020/9/26.
//

#include <cstdio>

struct A{
    int i;
    int getI(){
        return i;
    }
};

class B{
    int i;
    int getI(){
        return i;
    }
};

int main(){
    A a;
    B b;
    a.getI();
    printf("a.getI() = %d", a.getI());
    // printf("b.getI() = %d", b.getI());       // default to private
    return 0;
}