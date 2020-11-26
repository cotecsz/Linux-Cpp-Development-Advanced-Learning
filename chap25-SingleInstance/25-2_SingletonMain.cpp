//
// Created by dream on 2020/11/26.
//


#include <iostream>
#include "Singleton.h"
using namespace std;


class SingleInstance{
public:
    friend class Singleton<SingleInstance>;
    void print(){
        cout << "this = " << this << endl;
    }
private:
    // 构造函数、拷贝构造函数、赋值构造函数
    SingleInstance(){

    }
    SingleInstance(const SingleInstance&);
    SingleInstance& operator=(const SingleInstance&);
};

int main(){

    SingleInstance* s =  Singleton<SingleInstance>::GetInstance() ;

    s->print();

    SingleInstance* s1 = Singleton<SingleInstance>::GetInstance();
    SingleInstance* s2 = Singleton<SingleInstance>::GetInstance();

    s1->print();
    s2->print();
    return 0;
}