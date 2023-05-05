#pragma once
#include "BiDirectional\BiDirectIter.hpp"
template <typename T>
class RABaseIter: public BiDirectIter{
protected:
    T* _ptr = nullptr;
public:
    RABaseIter() = default;
    RABaseIter(T* ptr);

    virtual RABaseIter& operator+=(int offset);
    virtual RABaseIter& operator-=(int offset);
    
    virtual RABaseIter operator+(int offset);
    virtual RABaseIter operator-(int offset);
    
};

template <typename T>
class RABaseCIter: public CBiDirectIter{
protected:
    const T* _ptr = nullptr;
public:
    RABaseCIter() = default;
    RABaseCIter(T* ptr);
    RABaseCIter(const RABaseIter<T>& other);

    virtual RABaseCIter& operator+=(int offset);
    virtual RABaseCIter& operator-=(int offset);

    virtual RABaseCIter operator+(int offset);
    virtual RABaseCIter operator-(int offset);
};

template <typename T>
RABaseIter<T>::RABaseIter(T* ptr): BiDirectIter(ptr){
}
template <typename T>
RABaseIter<T>& RABaseIter<T>::operator+=(int offset){
    _ptr += offset;
    return *this;
}
template <typename T>
RABaseIter<T>& RABaseIter<T>::operator-=(int offset){
    _ptr -= offset;
    return *this;
}
template <typename T>
RABaseIter<T> RABaseIter<T>::operator+(int offset){
    return RABaseIter<T>(_ptr + offset);
}

template <typename T>
RABaseIter<T> RABaseIter<T>::operator-(int offset){  
    return RABaseIter<T>(_ptr - offset);
}


//Constant Iterator


template <typename T>
RABaseCIter<T>::RABaseCIter(T* ptr): CBiDirectIter(ptr){

}
template <typename T>
RABaseCIter<T>::RABaseCIter(const RABaseIter<T>& other): _ptr(other._ptr){

}

template <typename T>
RABaseCIter<T>& RABaseCIter<T>::operator+=(int offset){
    _ptr += offset;
    return *this;
}
template <typename T>
RABaseCIter<T>& RABaseCIter<T>::operator-=(int offset){
    _ptr -= offset;
    return *this;
}

template <typename T>
RABaseCIter<T> RABaseCIter<T>::operator+(int offset){
    return RABaseCIter<T>(_ptr + offset);
}
template <typename T>
RABaseCIter<T> RABaseCIter<T>::operator-(int offset){
    return RABaseCIter<T>(_ptr - offset);

}

