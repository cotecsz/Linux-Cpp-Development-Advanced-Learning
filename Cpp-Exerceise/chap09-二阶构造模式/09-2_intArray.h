//
// Created by Yang Shuangzhen on 2020/10/5.
//

#ifndef CPP_EXERCEISE_09_2_INTARRAY_H
#define CPP_EXERCEISE_09_2_INTARRAY_H

class IntArray
{
private:
    int m_length;
    int* m_pointer;

    IntArray(int len);
    bool constructor();
public:
    static IntArray* NewInstance(int len); // 对象创建函数
    int length();
    bool get(int index, int& value);
    bool set(int index ,int value);
    // void free();
    ~IntArray();
};


#endif //CPP_EXERCEISE_09_2_INTARRAY_H
