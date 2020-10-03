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

    int* getP(){
        return p;
    }

    Test(int v){
        i = 1;
        j = 2;
        p = new int;
        *p = v;
    }

    Test(const Test& t){
        i = t.i;
        j = t.j;
        p = new int;
        *p = *t.p;
    }
    ~Test(){
        delete p;
    }
private:
    int i;
    int j;
    int* p;
};

class EmptyClass{
    // 至少有一个无参构造函数
};

int main(){
    Test t(3);
    Test tCopy (t);

    printf(" t.i = %d, t.j = %d, t.p = %d\n", t.getI(), t.getJ(), t.getP());
    printf(" tCopy.i = %d, tCopy.j = %d, tCopy.p = %d\n", tCopy.getI(), tCopy.getJ(), tCopy.getP());
    return 0;
}

