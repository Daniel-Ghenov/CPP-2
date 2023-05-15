#pragma once
#include "../Forward\ForwardIter.hpp"

template <typename T>
class BiDirectIter: public ForwardIter<T>{
public:
    BiDirectIter() = default;
    BiDirectIter(T* ptr);

    virtual BiDirectIter& operator--();
    virtual BiDirectIter operator--(int a);
};

template <typename T>
class CBiDirectIter: public CForwardIter<T>{
public:
    CBiDirectIter() = default;
    CBiDirectIter(T* ptr);

    virtual CBiDirectIter& operator--();
    virtual CBiDirectIter operator--(int a);
};

template <typename T>
BiDirectIter<T>::BiDirectIter(T* ptr): ForwardIter<T>(ptr){}

template <typename T>
BiDirectIter<T>& BiDirectIter<T>::operator--(){
    this->_ptr--;
    return *this;
}
template <typename T>
BiDirectIter<T> BiDirectIter<T>::operator--(int a){
    this->_ptr--;
    return ForwardIter(this->_ptr + 1);
}

template <typename T>
CBiDirectIter<T>::CBiDirectIter(T* ptr): ForwardIter<T>(ptr){}

template <typename T>
CBiDirectIter<T>& CBiDirectIter<T>::operator--(){
    this->_ptr--;
    return *this;
}
template <typename T>
CBiDirectIter<T> CBiDirectIter<T>::operator--(int a){
    this->_ptr--;
    return ForwardIter(this->_ptr + 1);
}