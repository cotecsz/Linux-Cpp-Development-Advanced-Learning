//
// Created by dream on 2020/11/25.
//

#ifndef CPP_EXERCISE_22_2_PRACTICALCLASSTEMPLATE_H
#define CPP_EXERCISE_22_2_PRACTICALCLASSTEMPLATE_H


template < typename T >
class Operator
{
public:
    T add(T a, T b);
    T minus(T a, T b);
    T multiply(T a, T b);
    T divide(T a, T b);
};

template < typename T >
T Operator<T>::add(T a, T b)
{
    return a + b;
}


template < typename T >
T Operator<T>::minus(T a, T b)
{
    return a - b;
}


template < typename T >
T Operator<T>::multiply(T a, T b)
{
    return a * b;
}


template < typename T >
T Operator<T>::divide(T a, T b)
{
    return a / b;
}

#endif //CPP_EXERCISE_22_2_PRACTICALCLASSTEMPLATE_H
