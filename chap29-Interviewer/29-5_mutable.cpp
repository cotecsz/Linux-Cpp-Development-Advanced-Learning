//
// Created by dream on 2021/1/8.
//

#include <iostream>
using namespace std;

class Test{
public:
    Test():m_count(0), m_i(10){};

    int getI() const{
        m_count++;
        return m_i;
    }

    int callingTimes() const{
        return m_count;
    }
private:
    int m_i;
    mutable int m_count;
};


int main(){
    Test t = Test();

    cout << t.getI() << endl;
    cout << t.getI() << endl;
    cout << t.getI() << endl;
    cout << t.getI() << endl;
    cout << t.getI() << endl;

    cout << "t.getI() called times:  " << t.callingTimes() << endl;

    return 0;
}