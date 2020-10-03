//
// Created by Yang Shuangzhen on 2020/9/27.
//

#ifndef CPP_EXERCEISE_03_4_INTARRAY_H
#define CPP_EXERCEISE_03_4_INTARRAY_H

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
    void free();
};

#endif //CPP_EXERCEISE_03_4_INTARRAY_H
