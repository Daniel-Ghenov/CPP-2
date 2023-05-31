#pragma once
#include "SharedPtr.hpp"


template <typename T>
class WeakPtr{
private:
    const T* _data = nullptr;
    SharedPtr<T>::Counter* _counter = nullptr;

public:

    WeakPtr() = default;
    WeakPtr(const WeakPtr<T>& other);
    WeakPtr(const SharedPtr<T>& other);
    WeakPtr<T>& operator=(const WeakPtr<T>& other);
    WeakPtr<T>& operator=(const SharedPtr<T>& other);

    ~WeakPtr();

    const T& operator*() const;
    const T* operator->() const;

    bool operator==(const WeakPtr<T>& other) const;
    bool operator==(const T* ptr) const;
    operator bool() const;
    T* get();


private:
    void free();
    void copyFrom(const SharedPtr<T>& other);
    void copyFrom(const WeakPtr<T>& other);

};




template <typename T>
WeakPtr<T>::WeakPtr(const WeakPtr<T>& other){

    copyFrom(other);
}

template <typename T>
WeakPtr<T>::WeakPtr(const SharedPtr<T>& other){
    copyFrom(other);
}

template <typename T>
WeakPtr<T>& WeakPtr<T>::operator=(const WeakPtr<T>& other){

    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
WeakPtr<T>& WeakPtr<T>::operator=(const SharedPtr<T>& other){

    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
WeakPtr<T>::~WeakPtr(){
    free();
}


template <typename T>
const T& WeakPtr<T>::operator*() const{
    retrun *_data;
}
template <typename T>
const T* WeakPtr<T>::operator->() const{
    return _data;
}
template <typename T>
T* WeakPtr<T>::get(){
    return _data;
}

template <typename T>
bool WeakPtr<T>::operator==(const WeakPtr<T>& other) const{
    return _data = other._data;
}
template <typename T>
bool WeakPtr<T>::operator==(const T* ptr) const{
    return _data = ptr;
}
template <typename T>
WeakPtr<T>::operator bool() const{
    return (_counter && _counter->_sharedCount != 0);
}

template <typename T>
void WeakPtr<T>::free(){
    if(_counter){
        _counter->removeWeak();
        if(_counter->weakCount == 0)
            delete _counter;
    }
}
template <typename T>
void WeakPtr<T>::copyFrom(const SharedPtr<T>& other){
    _data = other._data;
    _counter = other._counter;
    if(_counter)
        _counter.addWeak();

}

template <typename T>
void WeakPtr<T>::copyFrom(const WeakPtr<T>& other){
    _data = other._data;
    _counter = other._counter;
    if(_counter)
        _counter.addWeak();

}
