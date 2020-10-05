//
// Created by Yang Shuangzhen on 2020/9/27.
//

#include "09-2_intArray.h"

IntArray::IntArray(int len)
{
    m_length = len;
}

bool IntArray::constructor() {
    // 模拟内存失败
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

//void IntArray::free()
//{
//    delete[]m_pointer;
//}

IntArray::~IntArray()
{
    delete[] m_pointer;
}

