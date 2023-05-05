#pragma once

template <typename T>
class RABaseIter{
protected:
    T* _ptr = nullptr;
public:
    RABaseIter() = default;
    RABaseIter() = default;
    RABaseIter(T* ptr);

    virtual RABaseIter& operator++();
    virtual RABaseIter& operator--();
    virtual RABaseIter operator++(int a);
    virtual RABaseIter operator--(int a);

    virtual RABaseIter& operator+=(int offset);
    virtual RABaseIter& operator-=(int offset);
    
    virtual RABaseIter operator+(int offset);
    virtual RABaseIter operator-(int offset);
    
    virtual bool operator>(const RABaseIter& other);
    virtual bool operator>=(const RABaseIter& other);
    virtual bool operator<=(const RABaseIter& other);
    virtual bool operator<(const RABaseIter& other);
    virtual bool operator==(const RABaseIter& other);
    virtual bool operator!=(const RABaseIter& other);

    virtual const T& operator*() const;
    virtual T& operator*();
    virtual T* operator->();
};



template <typename T>
class RABaseCIter{
protected:
    const T* _ptr = nullptr;
public:
    RABaseCIter() = default;
    RABaseCIter(T* ptr);
    RABaseCIter(const RABaseIter<T>& other);

    virtual RABaseCIter& operator++();
    virtual RABaseCIter& operator--();
    virtual RABaseCIter operator++(int a);
    virtual RABaseCIter operator--(int a);

    virtual RABaseCIter& operator+=(int offset);
    virtual RABaseCIter& operator-=(int offset);

    virtual RABaseCIter operator+(int offset);
    virtual RABaseCIter operator-(int offset);

    virtual bool operator>(const RABaseCIter& other);
    virtual bool operator>=(const RABaseCIter& other);
    virtual bool operator<=(const RABaseCIter& other);
    virtual bool operator<(const RABaseCIter& other);
    virtual bool operator==(const RABaseCIter& other);
    virtual bool operator!=(const RABaseCIter& other);

    virtual const T& operator*() const;
    virtual T& operator*();
    virtual T* operator->();
};

template <typename T>
RABaseIter<T>::RABaseIter(T* ptr): _ptr(ptr){
}

template <typename T>
RABaseIter<T>& RABaseIter<T>::operator++(){
    _ptr++;
    return *this;
}

template <typename T>
RABaseIter<T>& RABaseIter<T>::operator--(){
    _ptr--;
    return *this;
}
template <typename T>
RABaseIter<T> RABaseIter<T>::operator++(int a){
    _ptr++;
    return (RABaseIter<T>(--_ptr));
}
template <typename T>
RABaseIter<T> RABaseIter<T>::operator--(int a){
    _ptr--;
    return (RABaseIter<T>(++_ptr));
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


template <typename T>
bool RABaseIter<T>::operator>(const RABaseIter<T>& other){
    return _ptr > other._ptr;
}

template <typename T>
bool RABaseIter<T>::operator>=(const RABaseIter<T>& other){

    return _ptr >= other._ptr;
}

template <typename T>
bool RABaseIter<T>::operator<=(const RABaseIter<T>& other){

    return _ptr <= other._ptr;
}

template <typename T>
bool RABaseIter<T>::operator<(const RABaseIter<T>& other){

    return _ptr < other._ptr;
}
template <typename T>
bool RABaseIter<T>::operator==(const RABaseIter<T>& other){
    return _ptr == other._ptr;
}
template <typename T>
bool RABaseIter<T>::operator!=(const RABaseIter<T>& other){
    return _ptr != other._ptr;
}

template <typename T>
const T& RABaseIter<T>::operator*() const{
    return *_ptr;
}
template <typename T>
T& RABaseIter<T>::operator*(){
    return *_ptr;
}
template <typename T>
T* RABaseIter<T>::operator->(){
    return _ptr;
}

//Constant Iterator


template <typename T>
RABaseCIter<T>::RABaseCIter(T* ptr): _ptr(ptr){

}
template <typename T>
RABaseCIter<T>::RABaseCIter(const RABaseIter<T>& other): _ptr(other._ptr){

}

template <typename T>
RABaseCIter<T>& RABaseCIter<T>::operator++(){
    _ptr++;
    return *this;
}

template <typename T>
RABaseCIter<T>& RABaseCIter<T>::operator--(){
    _ptr--;
    return *this;  
}

template <typename T>
RABaseCIter<T> RABaseCIter<T>::operator++(int a){
    _ptr++;
    return RABaseCIter<T>(--_ptr);
}
template <typename T>
RABaseCIter<T> RABaseCIter<T>::operator--(int a){
    _ptr--;
    return RABaseCIter<T>(++_ptr);
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


template <typename T>
bool RABaseCIter<T>::operator>(const RABaseCIter<T>& other){
    
    return _ptr > other._ptr;
}


template <typename T>
bool RABaseCIter<T>::operator>=(const RABaseCIter<T>& other){
    
    return _ptr >= other._ptr;
}


template <typename T>
bool RABaseCIter<T>::operator<=(const RABaseCIter<T>& other){
    
    return _ptr <= other._ptr;
}


template <typename T>
bool RABaseCIter<T>::operator<(const RABaseCIter<T>& other){
    return _ptr < other._ptr;
    
}
template <typename T>
bool RABaseCIter<T>::operator==(const RABaseCIter<T>& other){
    return _ptr == other._ptr;

}
template <typename T>
bool RABaseCIter<T>::operator!=(const RABaseCIter<T>& other){
    return _ptr != other._ptr;

}

template <typename T>
const T& RABaseCIter<T>::operator*() const{
    return *_ptr;
}
template <typename T>
T& RABaseCIter<T>::operator*(){
    return *_ptr;
}
template <typename T>
T* RABaseCIter<T>::operator->(){
    return _ptr;
}