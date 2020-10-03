//
// Created by Yang Shuangzhen on 2020/10/3.
//

#include <stdio.h>

class Test{
public:
    int getI(){
        return i;
    }

    int getJ(){
        return j;
    }

    Test(){

    }

//    Test(const Test& t){
//        i = t.i;
//        j = t.j;
//    }
private:
    int i;
    int j;
};

class EmptyClass{
    // 至少有一个无参构造函数
};

int main(){
    Test t;
    Test tCopy = t;

    printf(" t.i = %d, t.j = %d\n", t.getI(), t.getJ());
    printf(" tCopy.i = %d, tCopy.j = %d\n", tCopy.getI(), tCopy.getJ());
    return 0;
}

