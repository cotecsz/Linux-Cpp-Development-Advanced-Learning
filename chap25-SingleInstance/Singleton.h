//
// Created by dream on 2020/11/26.
//

#ifndef CPP_EXERCISE_SINGLETON_H
#define CPP_EXERCISE_SINGLETON_H

template <typename T>
class Singleton{
public:
    // 返回对象
    static T* GetInstance();

private:
    // 对象
    static T* c_instance;
};

template <typename T>
T* Singleton<T>::c_instance = nullptr;

template <typename T>
T* Singleton<T>::GetInstance() {
    if (c_instance == nullptr){
        c_instance = new T();
    }
    return c_instance;
}

#endif //CPP_EXERCISE_SINGLETON_H
