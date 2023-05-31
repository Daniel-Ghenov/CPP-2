#pragma once

template <typename T>
class UniquePtr{
private:
    T* _data = nullptr;

public:



    UniquePtr() = default;
    UniquePtr(T* data);
    UniquePtr(const UniquePtr<T>& other) = delete;
    UniquePtr(UniquePtr<T>&& other);
    UniquePtr<T>& operator=(const UniquePtr<T>& other) = delete;
    UniquePtr<T>& operator=(UniquePtr<T>&& other);
    ~UniquePtr();

    const T& operator*() const;
    T& operator*();

    const T* operator->() const;
    T* operator->();


private:
    void free();
    void move(UniquePtr&& other);

};


template <typename T>
UniquePtr<T>::UniquePtr(T* data){
    _data = data;
}
template <typename T>
UniquePtr<T>::UniquePtr(UniquePtr<T>&& other){
    move(std::move(other));
}
template <typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& other){
    if(this != &other){
        free();
        move(std::move(other));
    }
    return *this;
}

template <typename T>
UniquePtr<T>::~UniquePtr(){
    free();
}

template <typename T>
const T& UniquePtr<T>::operator*() const{
    return *_data;
}
template <typename T>
T& UniquePtr<T>::operator*(){
    return *_data;
}

template <typename T>
const T* UniquePtr<T>::operator->() const{
    return _data;
}
template <typename T>
T* UniquePtr<T>::operator->(){
    return _data;
}

template <typename T>
void UniquePtr<T>::free(){
    delete _data;
    _data = nullptr;
}
template <typename T>
void UniquePtr<T>::move(UniquePtr&& other){
    _data = other._data;
    other._data = nullptr;   
}