//
// Created by Yang Shuangzhen on 2020/9/27.
//

#include "12-5_intArray.h"

IntArray::IntArray(int len)
{
    m_length = len;
}

IntArray::IntArray(const IntArray& obj) {
    m_length = obj.m_length;

    m_pointer = new int[m_length];
    for (int i=0; i<m_length; i++){
        m_pointer[i] = obj.m_pointer[i];
    }
}

bool IntArray::constructor() {
    m_pointer = new int[m_length];
    if (m_pointer){
        for(int i=0; i<m_length; i++)
        {
            m_pointer[i] = 0;
        }

        return true;
    }

    return false;

}

IntArray* IntArray::NewInstance(int len)
{
    IntArray* ret = new IntArray(len);

    // 若第二阶段构造失败，返回 NULL
    if( !(ret && ret->constructor()) )
    {
        delete ret;
        ret = nullptr;
    }

    return ret;
}

int IntArray::length()
{
    return m_length;
}

bool IntArray::get(int index, int& value)
{
    bool ret = (0 <= index) && (index < length());

    if( ret )
    {
        value = m_pointer[index];
    }

    return ret;
}

bool IntArray::set(int index, int value)
{
    bool ret = (0 <= index) && (index < length());

    if( ret )
    {
        m_pointer[index] = value;
    }

    return ret;
}

IntArray& IntArray::operator=(const IntArray &obj) {
    if (this != &obj){
        int* pointer = new int[obj.m_length];

        if (pointer){
            for (int i=0; i < m_length; i++){
                pointer[i] = obj.m_pointer[i];
            }
        }
        m_length = obj.m_length;
        delete m_pointer;
        m_pointer = pointer;
    }

    return *this;
}

int& IntArray::operator[](int index) {
    return m_pointer[index];
}

IntArray& IntArray::self() {
    return *this;
}

IntArray::~IntArray()
{
    delete[] m_pointer;
}

