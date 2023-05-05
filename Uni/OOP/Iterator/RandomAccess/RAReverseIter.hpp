#pragma once
#include "RandomAccess\RABaseIter.hpp"

template <typename T>
class RABaseRIter : public RABaseIter{
public:
    RABaseRIter() = default;
    RABaseRIter(T* ptr);
    RABaseRIter(const RABaseIter<T>& other);

    RABaseRIter& operator++() override;
    RABaseRIter& operator--() override;
    RABaseRIter operator++(int a) override;
    RABaseRIter operator--(int a) override;

    RABaseRIter& operator+=(int offset) override;
    RABaseRIter& operator-=(int offset) override;

    RABaseRIter operator+(int offset) override;
    RABaseRIter operator-(int offset) override;

    bool operator>(const RABaseRIter& other) override;
    bool operator>=(const RABaseRIter& other) override;
    bool operator<=(const RABaseRIter& other) override;
    bool operator<(const RABaseRIter& other) override;
    bool operator==(const RABaseRIter& other) override;
    bool operator!=(const RABaseRIter& other) override;

    const T& operator*() const override;
    T& operator*() override;
    T* operator->() override;
};

template <typename T>
class RABaseCRiter :public RABaseCIter{
    RABaseCRiter() = default;
    RABaseCRiter(T* ptr);       
    RABaseCRiter(const RABaseCIter<T>& other);
    RABaseCRiter(const RABaseRIter<T>& other);

    RABaseCRiter<T>& operator++() override;
    RABaseCRiter<T>& operator--() override;
    RABaseCRiter<T> operator++(int a) override;
    RABaseCRiter<T> operator--(int a) override;

    RABaseCRiter<T>& operator+=(int offset) override;
    RABaseCRiter<T>& operator-=(int offset) override;

    RABaseCRiter<T> operator+(int offset) override;
    RABaseCRiter<T> operator-(int offset) override;

    bool operator>(const RABaseCRiter<T>& other) override;
    bool operator>=(const RABaseCRiter<T>& other) override;
    bool operator<=(const RABaseCRiter<T>& other) override;
    bool operator<(const RABaseCRiter<T>& other) override;
    bool operator==(const RABaseCRiter<T>& other) override;
    bool operator!=(const RABaseCRiter<T>& other) override;

    const T& operator*() const override;
    const T* operator->() override;
};

template <typename T>
RABaseRIter<T>::RABaseRIter(T* ptr): RABaseIter(ptr){
}
template <typename T>
RABaseRIter<T>::RABaseRIter(const RABaseIter<T>& other): RABaseIter(other._ptr - 1){

}

template <typename T>
RABaseRIter<T>& RABaseRIter<T>::operator++(){
    _ptr--;
    return *this;
}
template <typename T>
RABaseRIter<T>& RABaseRIter<T>::operator--(){
    _ptr++;
    return *this;
}
template <typename T>
RABaseRIter<T> RABaseRIter<T>::operator++(int a){
    _ptr--;
    return (RABaseRIter<T>((_ptr)  + 1));
}
template <typename T>
RABaseRIter<T> RABaseRIter<T>::operator--(int a){
    _ptr++;
    return (RABaseRIter<T>((_ptr) - 1));
}
template <typename T>
RABaseRIter<T>& RABaseRIter<T>::operator+=(int offset){
    _ptr -= offset;
    return *this;
}
template <typename T>
RABaseRIter<T>& RABaseRIter<T>::operator-=(int offset){
    _ptr += offset;
    return *this;
}
template <typename T>
RABaseRIter<T> RABaseRIter<T>::operator+(int offset){
    return RABaseRIter<T>(_ptr - offset);

}
template <typename T>
RABaseRIter<T> RABaseRIter<T>::operator-(int offset){
    return RABaseRIter<T>(_ptr + offset);
}
template <typename T>
bool RABaseRIter<T>::operator>(const RABaseRIter<T>& other){
    return _ptr < other._ptr;
}
template <typename T>
bool RABaseRIter<T>::operator>=(const RABaseRIter<T>& other){
    return _ptr <= other._ptr;

}
template <typename T>
bool RABaseRIter<T>::operator<=(const RABaseRIter<T>& other){
    return _ptr >= other._ptr;
}
template <typename T>
bool RABaseRIter<T>::operator<(const RABaseRIter<T>& other){
    return _ptr > other._ptr;

}
template <typename T>
bool RABaseRIter<T>::operator==(const RABaseRIter<T>& other){
    return _ptr == other._ptr;
}
template <typename T>
bool RABaseRIter<T>::operator!=(const RABaseRIter<T>& other){
    return _ptr != other._ptr;
}

template <typename T>
const T& RABaseRIter<T>::operator*() const{
    return *(_ptr - 1)
}
template <typename T>
T& RABaseRIter<T>::operator*(){
    return *(_ptr - 1)
}
template <typename T>
T* RABaseRIter<T>::operator->(){
    return *(_ptr - 1)
}
//Const Iter


template <typename T>
RABaseCRiter<T>::RABaseCRiter(T* ptr): RABaseCIter(ptr){
    
}       

template <typename T>
RABaseCRiter<T>::RABaseCRiter(const RABaseCIter<T>& other): RABaseCIter(other._ptr - 1){
    
}
template <typename T>
RABaseCRiter<T>::RABaseCRiter(const RABaseRIter<T>& other): RABaseCIter(other){

}

template <typename T>
RABaseCRiter<T>& RABaseCRiter<T>::operator++(){
    _ptr--;
    return *this;
}
template <typename T>
RABaseCRiter<T>& RABaseCRiter<T>::operator--(){
    _ptr++;
    return *this;
}
template <typename T>
RABaseCRiter<T> RABaseCRiter<T>::operator++(int a){
    _ptr--;
    return CIterator(_ptr + 1);
}
template <typename T>
RABaseCRiter<T> RABaseCRiter<T>::operator--(int a){
    _ptr++;
    return CIterator(_ptr - 1);
}
template <typename T>
RABaseCRiter<T>& RABaseCRiter<T>::operator+=(int offset){
    _ptr -= offset;
    return *this;
}
template <typename T>
RABaseCRiter<T>& RABaseCRiter<T>::operator-=(int offset){
    _ptr += offset;
    return *this;
}
template <typename T>
RABaseCRiter<T> RABaseCRiter<T>::operator+(int offset){
    return CIterator(_ptr - offset);
    
}
template <typename T>
RABaseCRiter<T> RABaseCRiter<T>::operator-(int offset){
    return CIterator(_ptr + offset);
    
}
template <typename T>
bool RABaseCRiter<T>::operator>(const RABaseCRiter<T>& other){
    return _ptr < other._ptr;
    
}
template <typename T>
bool RABaseCRiter<T>::operator>=(const RABaseCRiter<T>& other){
    return _ptr <= other._ptr;
    
}
template <typename T>
bool RABaseCRiter<T>::operator<=(const RABaseCRiter<T>& other){
    return _ptr >= other._ptr;
    
}
template <typename T>
bool RABaseCRiter<T>::operator<(const RABaseCRiter<T>& other){
    return _ptr > other._ptr;
    
}
template <typename T>
bool RABaseCRiter<T>::operator==(const RABaseCRiter<T>& other){
    return _ptr == other._ptr;
    
}
template <typename T>
bool RABaseCRiter<T>::operator!=(const RABaseCRiter<T>& other){
    return _ptr != other._ptr;
    
}

template <typename T>
const T& RABaseCRiter<T>::operator*() const{
    return *(_ptr - 1)
}
template <typename T>
const T* RABaseCRiter<T>::operator->(){
    return *(_ptr - 1)
}