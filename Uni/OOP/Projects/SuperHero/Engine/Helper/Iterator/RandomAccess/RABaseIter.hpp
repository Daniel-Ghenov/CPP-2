#pragma once
#include "../BiDirectional\BiDirectIter.hpp"
template <typename T>
class RABaseIter: public BiDirectIter<T>{
public:
    RABaseIter() = default;
    RABaseIter(T* ptr);

    virtual RABaseIter& operator+=(int offset);
    virtual RABaseIter& operator-=(int offset);
    
    virtual RABaseIter operator+(int offset);
    virtual RABaseIter operator-(int offset);
    
};

template <typename T>
class RABaseCIter: public CBiDirectIter<T>{
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
RABaseIter<T>::RABaseIter(T* ptr): BiDirectIter<T>(ptr){
}
template <typename T>
RABaseIter<T>& RABaseIter<T>::operator+=(int offset){
    this->_ptr += offset;
    return *this;
}
template <typename T>
RABaseIter<T>& RABaseIter<T>::operator-=(int offset){
    this->_ptr -= offset;
    return *this;
}
template <typename T>
RABaseIter<T> RABaseIter<T>::operator+(int offset){
    return RABaseIter<T>(this->_ptr + offset);
}

template <typename T>
RABaseIter<T> RABaseIter<T>::operator-(int offset){  
    return RABaseIter<T>(this->_ptr - offset);
}


//Constant Iterator


template <typename T>
RABaseCIter<T>::RABaseCIter(T* ptr): CBiDirectIter<T>(ptr){

}
template <typename T>
RABaseCIter<T>::RABaseCIter(const RABaseIter<T>& other): CBiDirectIter<T>(other._ptr){

}

template <typename T>
RABaseCIter<T>& RABaseCIter<T>::operator+=(int offset){
    this->_ptr += offset;
    return *this;
}
template <typename T>
RABaseCIter<T>& RABaseCIter<T>::operator-=(int offset){
    this->_ptr -= offset;
    return *this;
}

template <typename T>
RABaseCIter<T> RABaseCIter<T>::operator+(int offset){
    return RABaseCIter<T>(this->_ptr + offset);
}
template <typename T>
RABaseCIter<T> RABaseCIter<T>::operator-(int offset){
    return RABaseCIter<T>(this->_ptr - offset);

}

