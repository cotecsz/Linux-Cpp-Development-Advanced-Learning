//
// Created by Yang Shuangzhen on 2020/10/3.
//

#ifndef CPP_EXERCEISE_06_1_INTARRAY_H
#define CPP_EXERCEISE_06_1_INTARRAY_H

class IntArray
{
private:
    int m_length;
    int* m_pointer;
public:
    IntArray(int len);
    IntArray(const IntArray& obj);
    int length();
    bool get(int index, int& value);
    bool set(int index ,int value);
    // void free();
    ~IntArray();
};

#endif //CPP_EXERCEISE_06_1_INTARRAY_H
