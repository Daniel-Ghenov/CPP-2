#pragma once

template <typename T>
class BaseIter{
protected:
    T* _ptr = nullptr;
public:
    BaseIter() = default;
    BaseIter() = default;
    BaseIter(T* ptr);

    virtual BaseIter& operator++();
    virtual BaseIter& operator--();
    virtual BaseIter operator++(int a);
    virtual BaseIter operator--(int a);

    virtual BaseIter& operator+=(int offset);
    virtual BaseIter& operator-=(int offset);
    
    virtual BaseIter operator+(int offset);
    virtual BaseIter operator-(int offset);
    
    virtual bool operator>(const BaseIter& other);
    virtual bool operator>=(const BaseIter& other);
    virtual bool operator<=(const BaseIter& other);
    virtual bool operator<(const BaseIter& other);
    virtual bool operator==(const BaseIter& other);
    virtual bool operator!=(const BaseIter& other);

    virtual const T& operator*() const;
    virtual T& operator*();
    virtual T* operator->();
};



template <typename T>
class BaseCIter{
protected:
    const T* _ptr = nullptr;
public:
    BaseCIter() = default;
    BaseCIter(T* ptr);
    BaseCIter(const BaseIter<T>& other);

    virtual BaseCIter& operator++();
    virtual BaseCIter& operator--();
    virtual BaseCIter operator++(int a);
    virtual BaseCIter operator--(int a);

    virtual BaseCIter& operator+=(int offset);
    virtual BaseCIter& operator-=(int offset);

    virtual BaseCIter operator+(int offset);
    virtual BaseCIter operator-(int offset);

    virtual bool operator>(const BaseCIter& other);
    virtual bool operator>=(const BaseCIter& other);
    virtual bool operator<=(const BaseCIter& other);
    virtual bool operator<(const BaseCIter& other);
    virtual bool operator==(const BaseCIter& other);
    virtual bool operator!=(const BaseCIter& other);

    virtual const T& operator*() const;
    virtual T& operator*();
    virtual T* operator->();
};

template <typename T>
BaseIter<T>::BaseIter(T* ptr): _ptr(ptr){
}

template <typename T>
BaseIter<T>& BaseIter<T>::operator++(){
    _ptr++;
    return *this;
}

template <typename T>
BaseIter<T>& BaseIter<T>::operator--(){
    _ptr--;
    return *this;
}
template <typename T>
BaseIter<T> BaseIter<T>::operator++(int a){
    _ptr++;
    return (BaseIter<T>(--_ptr));
}
template <typename T>
BaseIter<T> BaseIter<T>::operator--(int a){
    _ptr--;
    return (BaseIter<T>(++_ptr));
}

template <typename T>
BaseIter<T>& BaseIter<T>::operator+=(int offset){

    _ptr += offset;
    return *this;
}
template <typename T>
BaseIter<T>& BaseIter<T>::operator-=(int offset){
    _ptr -= offset;
    return *this;
}
template <typename T>
BaseIter<T> BaseIter<T>::operator+(int offset){
    return BaseIter<T>(_ptr + offset);

}

template <typename T>
BaseIter<T> BaseIter<T>::operator-(int offset){  
    return BaseIter<T>(_ptr - offset);

}


template <typename T>
bool BaseIter<T>::operator>(const BaseIter<T>& other){
    return _ptr > other._ptr;
}

template <typename T>
bool BaseIter<T>::operator>=(const BaseIter<T>& other){

    return _ptr >= other._ptr;
}

template <typename T>
bool BaseIter<T>::operator<=(const BaseIter<T>& other){

    return _ptr <= other._ptr;
}

template <typename T>
bool BaseIter<T>::operator<(const BaseIter<T>& other){

    return _ptr < other._ptr;
}
template <typename T>
bool BaseIter<T>::operator==(const BaseIter<T>& other){
    return _ptr == other._ptr;
}
template <typename T>
bool BaseIter<T>::operator!=(const BaseIter<T>& other){
    return _ptr != other._ptr;
}

template <typename T>
const T& BaseIter<T>::operator*() const{
    return *_ptr;
}
template <typename T>
T& BaseIter<T>::operator*(){
    return *_ptr;
}
template <typename T>
T* BaseIter<T>::operator->(){
    return _ptr;
}

//Constant Iterator


template <typename T>
BaseCIter<T>::BaseCIter(T* ptr): _ptr(ptr){

}
template <typename T>
BaseCIter<T>::BaseCIter(const BaseIter<T>& other): _ptr(other._ptr){

}

template <typename T>
BaseCIter<T>& BaseCIter<T>::operator++(){
    _ptr++;
    return *this;
}

template <typename T>
BaseCIter<T>& BaseCIter<T>::operator--(){
    _ptr--;
    return *this;  
}

template <typename T>
BaseCIter<T> BaseCIter<T>::operator++(int a){
    _ptr++;
    return BaseCIter<T>(--_ptr);
}
template <typename T>
BaseCIter<T> BaseCIter<T>::operator--(int a){
    _ptr--;
    return BaseCIter<T>(++_ptr);
}

template <typename T>
BaseCIter<T>& BaseCIter<T>::operator+=(int offset){
    _ptr += offset;
    return *this;
}
template <typename T>
BaseCIter<T>& BaseCIter<T>::operator-=(int offset){
    _ptr -= offset;
    return *this;
}

template <typename T>
BaseCIter<T> BaseCIter<T>::operator+(int offset){
    return BaseCIter<T>(_ptr + offset);
}
template <typename T>
BaseCIter<T> BaseCIter<T>::operator-(int offset){
    return BaseCIter<T>(_ptr - offset);

}


template <typename T>
bool BaseCIter<T>::operator>(const BaseCIter<T>& other){
    
    return _ptr > other._ptr;
}


template <typename T>
bool BaseCIter<T>::operator>=(const BaseCIter<T>& other){
    
    return _ptr >= other._ptr;
}


template <typename T>
bool BaseCIter<T>::operator<=(const BaseCIter<T>& other){
    
    return _ptr <= other._ptr;
}


template <typename T>
bool BaseCIter<T>::operator<(const BaseCIter<T>& other){
    return _ptr < other._ptr;
    
}
template <typename T>
bool BaseCIter<T>::operator==(const BaseCIter<T>& other){
    return _ptr == other._ptr;

}
template <typename T>
bool BaseCIter<T>::operator!=(const BaseCIter<T>& other){
    return _ptr != other._ptr;

}

template <typename T>
const T& BaseCIter<T>::operator*() const{
    return *_ptr;
}
template <typename T>
T& BaseCIter<T>::operator*(){
    return *_ptr;
}
template <typename T>
T* BaseCIter<T>::operator->(){
    return _ptr;
}