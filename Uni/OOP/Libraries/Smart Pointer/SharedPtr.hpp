#pragma once
#include <iostream>

template <typename T>
class SharedPtr{
private:
    T* _data = nullptr;
    size_t* _ptrCount = nullptr;

public:

    SharedPtr() = default;
    SharedPtr(T* data);
    SharedPtr(const SharedPtr<T>& other);
    SharedPtr(SharedPtr<T>&& other);
    SharedPtr<T>& operator=(const SharedPtr<T>& other);
    SharedPtr<T>& operator=(SharedPtr<T>&& other);
    ~SharedPtr();

    const T& operator*() const;
    T& operator*();

    const T* operator->() const;
    T* operator->();

    bool operator==(const SharedPtr<T>& other) const;
    operator bool() const;
    T* get();


private:
    void free();
    void copyFrom(const SharedPtr<T>& other);
    void move(SharedPtr&& other);

};



template <typename T>
SharedPtr<T>::SharedPtr(T* data){
    _data = data;
    _ptrCount = new size_t(1);
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& other){
    copyFrom(other);
}

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>&& other){
    move(std::move(other));
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T>&& other){
    if(this != &other){
        free();
        move(std::move(other));
    }
    return *this;
}

template <typename T>
SharedPtr<T>::~SharedPtr(){
    free();
}


template <typename T>
const T& SharedPtr<T>::operator*() const{
    return *_data;
}
template <typename T>
T& SharedPtr<T>::operator*(){
    return *_data;
}

template <typename T>
const T* SharedPtr<T>::operator->() const{
    return _data;
}
template <typename T>
T* SharedPtr<T>::operator->(){
    return _data;
}

template <typename T>
bool SharedPtr<T>::operator==(const SharedPtr<T>& other) const{
    return _data == other._data;
}

template <typename T>
SharedPtr<T>::operator bool() const{
    return _data;
}


template <typename T>
T* SharedPtr<T>::get(){
    return _data;
}

template <typename T>
void SharedPtr<T>::free(){
    if(!_ptrCount)
        return;

    if(*_ptrCount == 1){
        delete _data;
        delete _ptrCount;
    }else
        (*_ptrCount)--;
}

template <typename T>
void SharedPtr<T>::copyFrom(const SharedPtr<T>& other){
    _data = other._data;
    _ptrCount = other._ptrCount;
    if(!other._ptrCount)
        (*_ptrCount)++;
}

template <typename T>
void SharedPtr<T>::move(SharedPtr&& other){
    _data = other._data;
    other._data = nullptr;

    _ptrCount = other._ptrCount;
    other._ptrCount = nullptr;

}
