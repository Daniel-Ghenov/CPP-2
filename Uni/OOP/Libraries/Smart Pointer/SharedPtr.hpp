#pragma once
#include <iostream>

template <typename T>
class SharedPtr{
private:
    T* _data = nullptr;
    Counter* _counter = nullptr;
public:

    struct Counter{
        size_t _sharedCount = 0;
        size_t _weakCount = 0;

        void addShared() const;
        void removeShared() const;
        void addWeak() const;
        void removeWeak() const;

    };

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
    bool operator==(const T* ptr) const;
    operator bool() const;
    T* get();


private:
    void free();
    void copyFrom(const SharedPtr<T>& other);
    void move(SharedPtr&& other);

};

template <typename T>
void SharedPtr<T>::Counter::addShared() const{
    _sharedCount++;
    if(_weakCount == 0)
        _weakCount++;
}
template <typename T>
void SharedPtr<T>::Counter::removeShared() const{
    _sharedCount--;
    if(_sharedCount == 0)
        _weakCount--;
}
template <typename T>
void SharedPtr<T>::Counter::addWeak() const{
    _weakCount++;
}
template <typename T>
void SharedPtr<T>::Counter::removeWeak() const{
    _weakCount--;
}


template <typename T>
SharedPtr<T>::SharedPtr(T* data){
    _data = data;
    if(_data){
        _counter = new Counter;
        _counter->addShared();
    }
        
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
bool SharedPtr<T>::operator==(const T* ptr) const{
    return _data == ptr;
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
    if(_counter){
        _counter->removeShared();
        if(_counter->_sharedCount == 0)
            delete _data;
        if(_counter->_weakCount == 0)
            delete _counter;
    }

}

template <typename T>
void SharedPtr<T>::copyFrom(const SharedPtr<T>& other){
    _data = other._data;
    _counter = other._counter;

    if(_counter){
        _counter->addShared;
    }
    
}

template <typename T>
void SharedPtr<T>::move(SharedPtr&& other){
    _data = other._data;
    other._data = nullptr;

    _counter = other._counter;
    other._counter = nullptr;
}
