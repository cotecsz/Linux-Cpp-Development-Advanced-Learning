//
// Created by dream on 2020/11/26.
//

#ifndef CPP_EXERCISE_SMARTPOINTER_H
#define CPP_EXERCISE_SMARTPOINTER_H

template <typename T>
class SmartPointer{
public:
    SmartPointer(T* p = nullptr) {
        m_p = p;
    }

    SmartPointer(const SmartPointer &obj){
        delete m_p;
        m_p = obj.m_p;
        const_cast<SmartPointer<T>&>(obj).m_p = nullptr;
    }

    SmartPointer& operator = (const SmartPointer& obj){
        if (this != &obj){
            delete m_p;
            m_p = obj.m_p;
            const_cast<SmartPointer<T>&>(obj).m_p = nullptr;
        }

        return *this;
    }

    T* operator -> (){
        return m_p;
    }

    T& operator * (){
        return *m_p;
    }

    bool isNull(){
        return m_p == nullptr;
    }

    ~SmartPointer(){
        delete m_p;
    }

    T* get(){
        return m_p;
    }
private:
    T* m_p;
};


#endif //CPP_EXERCISE_SMARTPOINTER_H
