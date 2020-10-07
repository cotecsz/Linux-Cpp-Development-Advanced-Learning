//
// Created by Yang Shuangzhen on 2020/10/7.
//

#include <iostream>

using namespace std;

class Test{
public:
    Test(int val): i(val){}
    int value(){
        return i;
    }
    ~Test(){}
private:
    int i;
};

int main(){
    for (int i = 0; i < 5; i++){
        Test* p = new Test(i);
        cout << p->value() << endl;		// 使用完成，并未释放动态内存空间
    }

    return 0;
}