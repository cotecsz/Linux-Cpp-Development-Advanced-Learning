//
// Created by Yang Shuangzhen on 2020/9/27.
//

#include "03-4_intArray.h"

IntArray::IntArray(int len)
{
    m_pointer = new int[len];

    for(int i=0; i<len; i++)
    {
        m_pointer[i] = 0;
    }

    m_length = len;
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

void IntArray::free()
{
    delete[]m_pointer;
}
