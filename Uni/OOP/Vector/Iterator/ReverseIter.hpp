#pragma once
#include "Iterator\BaseIter.hpp"

template <typename T>
class BaseRIter : public BaseIter{
public:
    BaseRIter() = default;
    BaseRIter(T* ptr);
    BaseRIter(const BaseIter<T>& other);

    BaseRIter& operator++() override;
    BaseRIter& operator--() override;
    BaseRIter operator++(int a) override;
    BaseRIter operator--(int a) override;

    BaseRIter& operator+=(int offset) override;
    BaseRIter& operator-=(int offset) override;

    BaseRIter operator+(int offset) override;
    BaseRIter operator-(int offset) override;

    bool operator>(const BaseRIter& other) override;
    bool operator>=(const BaseRIter& other) override;
    bool operator<=(const BaseRIter& other) override;
    bool operator<(const BaseRIter& other) override;
    bool operator==(const BaseRIter& other) override;
    bool operator!=(const BaseRIter& other) override;

    const T& operator*() const override;
    T& operator*() override;
    T* operator->() override;
};

template <typename T>
class BaseCRiter :public BaseCIter{
    BaseCRiter<T>() = default;
    BaseCRiter<T>(T* ptr);       
    BaseCRiter<T>(const BaseCIter<T>& other);
    BaseCRiter<T>(const BaseRIter<T>& other);

    BaseCRiter<T>& operator++() override;
    BaseCRiter<T>& operator--() override;
    BaseCRiter<T> operator++(int a) override;
    BaseCRiter<T> operator--(int a) override;

    BaseCRiter<T>& operator+=(int offset) override;
    BaseCRiter<T>& operator-=(int offset) override;

    BaseCRiter<T> operator+(int offset) override;
    BaseCRiter<T> operator-(int offset) override;

    bool operator>(const BaseCRiter<T>& other) override;
    bool operator>=(const BaseCRiter<T>& other) override;
    bool operator<=(const BaseCRiter<T>& other) override;
    bool operator<(const BaseCRiter<T>& other) override;
    bool operator==(const BaseCRiter<T>& other) override;
    bool operator!=(const BaseCRiter<T>& other) override;

    const T& operator*() const override;
    T& operator*() override;
    T* operator->() override;
};

template <typename T>
BaseRIter<T>::BaseRIter(T* ptr): Iterator(ptr){
}
template <typename T>
BaseRIter<T>::BaseRIter(const BaseIter<T>& other): Iterator(other._ptr - 1){

}

template <typename T>
BaseRIter<T>& BaseRIter<T>::operator++(){
    this->_ptr--;
    return *this;
}
template <typename T>
BaseRIter<T>& BaseRIter<T>::operator--(){
    this->_ptr++;
    return *this;
}
template <typename T>
BaseRIter<T> BaseRIter<T>::operator++(int a){
    this->_ptr--;
    return (BaseRIter<T>(++(this->_ptr)));
}
template <typename T>
BaseRIter<T> BaseRIter<T>::operator--(int a){
    this->_ptr++;
    return (BaseRIter<T>(--(this->_ptr)));
}
template <typename T>
BaseRIter<T>& BaseRIter<T>::operator+=(int offset){
    this->_ptr -= offset;
    return *this;
}
template <typename T>
BaseRIter<T>& BaseRIter<T>::operator-=(int offset){
    this->_ptr += offset;
    return *this;
}
template <typename T>
BaseRIter<T> BaseRIter<T>::operator+(int offset){
    return BaseRIter<T>(this->_ptr - offset);

}
template <typename T>
BaseRIter<T> BaseRIter<T>::operator-(int offset){
    return BaseRIter<T>(this->_ptr + offset);
}
template <typename T>
bool BaseRIter<T>::operator>(const BaseRIter<T>& other){
    return this->_ptr < other._ptr;
}
template <typename T>
bool BaseRIter<T>::operator>=(const BaseRIter<T>& other){
    return this->_ptr <= other._ptr;

}
template <typename T>
bool BaseRIter<T>::operator<=(const BaseRIter<T>& other){
    return this->_ptr >= other._ptr;
}
template <typename T>
bool BaseRIter<T>::operator<(const BaseRIter<T>& other){
    return this->_ptr > other._ptr;

}
template <typename T>
bool BaseRIter<T>::operator==(const BaseRIter<T>& other){
    return this->_ptr == other._ptr;
}
template <typename T>
bool BaseRIter<T>::operator!=(const BaseRIter<T>& other){
    return this->_ptr != other._ptr;
}

template <typename T>
const T& BaseRIter<T>::operator*() const{
    return *(_ptr - 1)
}
template <typename T>
T& BaseRIter<T>::operator*(){
    return *(_ptr - 1)
}
template <typename T>
T* BaseRIter<T>::operator->(){
    return *(_ptr - 1)
}
//Const Iter


template <typename T>
BaseCRiter<T>::BaseCRiter(T* ptr): CIterator(ptr){
    
}       

template <typename T>
BaseCRiter<T>::BaseCRiter(const BaseCIter<T>& other): CIterator(other._ptr - 1){
    
}
template <typename T>
BaseCRiter<T>::BaseCRiter(const BaseRIter<T>& other): CIterator(other){

}

template <typename T>
BaseCRiter<T>& BaseCRiter<T>::operator++(){
    this->_ptr--;
    return *this;
}
template <typename T>
BaseCRiter<T>& BaseCRiter<T>::operator--(){
    this->_ptr++;
    return *this;
}
template <typename T>
BaseCRiter<T> BaseCRiter<T>::operator++(int a){
    this->_ptr--;
    return CIterator(++_ptr);
}
template <typename T>
BaseCRiter<T> BaseCRiter<T>::operator--(int a){
    this->_ptr++;
    return CIterator(--_ptr);
}
template <typename T>
BaseCRiter<T>& BaseCRiter<T>::operator+=(int offset){
    _ptr -= offset;
    return *this;
}
template <typename T>
BaseCRiter<T>& BaseCRiter<T>::operator-=(int offset){
    _ptr += offset;
    return *this;
}
template <typename T>
BaseCRiter<T> BaseCRiter<T>::operator+(int offset){
    return CIterator(_ptr - offset);
    
}
template <typename T>
BaseCRiter<T> BaseCRiter<T>::operator-(int offset){
    return CIterator(_ptr + offset);
    
}
template <typename T>
bool BaseCRiter<T>::operator>(const BaseCRiter<T>& other){
    return _ptr < other._ptr;
    
}
template <typename T>
bool BaseCRiter<T>::operator>=(const BaseCRiter<T>& other){
    return _ptr <= other._ptr;
    
}
template <typename T>
bool BaseCRiter<T>::operator<=(const BaseCRiter<T>& other){
    return _ptr >= other._ptr;
    
}
template <typename T>
bool BaseCRiter<T>::operator<(const BaseCRiter<T>& other){
    return _ptr > other._ptr;
    
}
template <typename T>
bool BaseCRiter<T>::operator==(const BaseCRiter<T>& other){
    return _ptr == other._ptr;
    
}
template <typename T>
bool BaseCRiter<T>::operator!=(const BaseCRiter<T>& other){
    return _ptr != other._ptr;
    
}

template <typename T>
const T& BaseCRiter<T>::operator*() const{
    return *(_ptr - 1)
}
template <typename T>
T& BaseCRiter<T>::operator*(){
    return *(_ptr - 1)
}
template <typename T>
T* BaseCRiter<T>::operator->(){
    return *(_ptr - 1)
}