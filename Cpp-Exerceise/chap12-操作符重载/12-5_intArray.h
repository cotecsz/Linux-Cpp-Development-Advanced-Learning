//
// Created by Yang Shuangzhen on 2020/10/7.
//

#ifndef CPP_EXERCEISE_12_5_INTARRAY_H
#define CPP_EXERCEISE_12_5_INTARRAY_H

class IntArray
{
private:
    int m_length;
    int* m_pointer;

    IntArray(int len);
    IntArray(const IntArray& obj);
    bool constructor();

public:
    static IntArray* NewInstance(int len); // 对象创建函数
    int length();
    bool get(int index, int& value);
    bool set(int index ,int value);

    IntArray& operator = (const IntArray& obj);
    int& operator [] (int index);
    IntArray& self();
    ~IntArray();
};

#endif //CPP_EXERCEISE_12_5_INTARRAY_H
