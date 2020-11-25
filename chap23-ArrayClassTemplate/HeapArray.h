//
// Created by dream on 2020/11/25.
//

#ifndef CPP_EXERCISE_HEAPARRAY_H
#define CPP_EXERCISE_HEAPARRAY_H

template
        < typename T >
class HeapArray
{
private:
    int m_length;
    T* m_pointer;

    HeapArray(int len);
    HeapArray(const HeapArray<T>& obj);
    bool construct();
public:
    static HeapArray<T>* NewInstance(int length);
    int length();
    bool get(int index, T& value);
    bool set(int index ,T value);
    T& operator [] (int index);
    T operator [] (int index) const;
    HeapArray<T>& self();
    ~HeapArray();
};

template
        < typename T >
HeapArray<T>::HeapArray(int len)
{
    m_length = len;
}

template < typename T >
bool HeapArray<T>::construct()
{
    m_pointer = new T[m_length];

    return m_pointer != nullptr;
}

template < typename T >
HeapArray<T>* HeapArray<T>::NewInstance(int length)
{
    HeapArray<T>* ret = new HeapArray<T>(length);

    if( !(ret && ret->construct()) )
    {
        delete ret;
        ret = 0;
    }

    return ret;
}

template
        < typename T >
int HeapArray<T>::length()
{
    return m_length;
}

template
        < typename T >
bool HeapArray<T>::get(int index, T& value)
{
    bool ret = (0 <= index) && (index < length());

    if( ret )
    {
        value = m_pointer[index];
    }

    return ret;
}

template
        < typename T >
bool HeapArray<T>::set(int index, T value)
{
    bool ret = (0 <= index) && (index < length());

    if( ret )
    {
        m_pointer[index] = value;
    }

    return ret;
}

template
        < typename T >
T& HeapArray<T>::operator [] (int index)
{
    return m_pointer[index];
}

template
        < typename T >
T HeapArray<T>::operator [] (int index) const
{
    return m_pointer[index];
}

template
        < typename T >
HeapArray<T>& HeapArray<T>::self()
{
    return *this;
}

template
        < typename T >
HeapArray<T>::~HeapArray()
{
    delete[]m_pointer;
}

#endif //CPP_EXERCISE_HEAPARRAY_H
