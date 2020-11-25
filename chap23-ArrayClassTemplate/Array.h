//
// Created by dream on 2020/11/25.
//

#ifndef CPP_EXERCISE_ARRAY_H
#define CPP_EXERCISE_ARRAY_H

template
    <typename T, int N>
class Array{
    T m_array[N];

public:
    int length();
    bool set(int index, T value);
    bool get(int index, T& value);

    T& operator[] (int index);      // 数组下标重载操作符
    T operator[] (int index) const;
    virtual ~Array();
};


template
        <typename T, int N>
int Array<T, N>::length() {
    return N;
}

template <typename T, int N>
bool Array<T, N>::set(int index, T value){
    if (index >= 0 && index <= N - 1){
        m_array[index] = value;
    }
    else{
        return false;
    }
}

template <typename T, int N>
bool Array<T, N>::get(int index, T& value){
    if (index >= 0 && index <= N - 1){
        value = m_array[index];
    }
    else{
        return false;
    }
}

template <typename T, int N>
T& Array<T, N>::operator[](int index) {
    return m_array[index];
}

template <typename T, int N>
T Array<T, N>::operator[](int index) const{
    return m_array[index];
}

template <typename T, int N>
Array<T, N>::~Array<T, N>() {

}


#endif //CPP_EXERCISE_ARRAY_H
