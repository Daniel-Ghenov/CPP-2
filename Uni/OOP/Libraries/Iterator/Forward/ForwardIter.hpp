#pragma once

template <typename T>
struct ForwardIter{
protected:
    T* _ptr = nullptr;
public:
    ForwardIter() = default;
    ForwardIter(T* ptr);

    virtual ForwardIter& operator++();
    virtual ForwardIter operator++(int a);


    virtual bool operator<(const ForwardIter& other);

    virtual const T& operator*() const;
    virtual T& operator*();
    virtual T* operator->();
};

template <typename T>
struct CForwardIter{
protected:
    const T* _ptr = nullptr;
public:
    CForwardIter() = default;
    CForwardIter(T* ptr);

    virtual CForwardIter& operator++();
    virtual CForwardIter operator++(int a);

    virtual bool operator<(const CForwardIter& other);

    virtual const T& operator*() const;
    virtual const T* operator->();
};

template <typename T>
ForwardIter<T>::ForwardIter(T* ptr): _ptr(ptr){ }

template <typename T>
ForwardIter<T>& ForwardIter<T>::operator++(){
    _ptr++;
    return *this;
}
template <typename T>
ForwardIter<T> ForwardIter<T>::operator++(int a){
    _ptr++;
    return ForwardIter(_ptr - 1);
}


template <typename T>
bool ForwardIter<T>::operator<(const ForwardIter& other){
    return _ptr < other._ptr;
}

template <typename T>
const T& ForwardIter<T>::operator*() const{
    return *_ptr;
}
template <typename T>
T& ForwardIter<T>::operator*(){
    return *_ptr;
}
template <typename T>
T* ForwardIter<T>::operator->(){
    return _ptr;
}

//Constant Forward Iterator


template <typename T>
CForwardIter<T>::CForwardIter(T* ptr): _ptr(ptr){ }

template <typename T>
CForwardIter<T>& CForwardIter<T>::operator++(){
    _ptr++;
    return *this;
}
template <typename T>
CForwardIter<T> CForwardIter<T>::operator++(int a){
    _ptr++;
    return CForwardIter(_ptr - 1);
}

template <typename T>
bool CForwardIter<T>::operator<(const CForwardIter& other){
    return _ptr < other._ptr;
}

template <typename T>
const T& CForwardIter<T>::operator*() const{
    return *_ptr;
}
template <typename T>
const T* CForwardIter<T>::operator->(){
    return _ptr;
}