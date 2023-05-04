#pragma once

#include <iostream>
#include "Const.h"

template <typename T>
class Vector{
private:
    T* _data;
    size_t _size;
    size_t _capacity;

public:

    Vector();   //Big 6 and constructors
    Vector(size_t size, const T& fill);
    Vector(size_t size);
    ~Vector();
    Vector<T>& operator=(const Vector<T>& other);
    Vector(const Vector<T>& other);
    Vector(Vector<T>&& other) noexcept;
    Vector<T>& operator=(Vector<T>&& other) noexcept;


    bool contains(const T& data) const;
    size_t find(const T& data) const;
    T& operator[](size_t number);   //Data access
    const T& operator[](size_t number) const;
    T* data();
    const T& front() const;
    const T& back() const;
    operator bool() const;

    void resize(size_t size);   //Size Modifications
    void resize(size_t size, const T& fill);
    size_t size() const;
    size_t capacity() const;
    void reserve(size_t number);

    void push_back(const T& newData);   //Data modifications
    void pop_back();
    void insert(size_t index, const T& toInsert);
    void erase(size_t index) noexcept;
    void swap(size_t index1, size_t index2);
    void clear();

private:
    void move(Vector<T>&& other);
    void copyFrom(const Vector<T>& other);
    void free()noexcept;
};



template <typename T>
void Vector<T>::copyFrom(const Vector<T>& other){
    _data = new T[other.capacity];
    for(size_t i {0}; i < other._size; i++){
        _data[i] = other._data[i];
    }
    _size = other._size;
    _capacity = other.capacity;
}

template <typename T>
void Vector<T>::move(Vector<T>&& other){
    this->_data = other._data;
    this->_size = other.size;
    this->_capacity = other._capacity;
    other._data = nullptr;
    other._capacity = other._size = 0;

}
template <typename T>
void Vector<T>::free() noexcept{
    delete[] _data;
    _data = nullptr;
    _size = _capacity = 0;
}

//Big 4 and Constructors


template <typename T>
Vector<T>::Vector(){
    _data = nullptr;
    _size = 0;
    _capacity = DEFAULT_SIZE;
}

template <typename T>
Vector<T>::Vector(size_t _size): Vector(_size, T()){}

template <typename T>
Vector<T>::Vector(size_t size, const T& fill){
    _size = size;
    _capacity = _size * UPSIZE_BY;
    _data = new T[_capacity];
    for(size_t i {0}; i < size;i++){
        _data[i] = fill;
    }

}
template <typename T>
Vector<T>::~Vector<T>(){
    clear();
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other){
    if(this != &other){
        clear();
        copyFrom(other);
    }
    return *this;
}
template <typename T>
Vector<T>::Vector(const Vector<T>& other){
    copyFrom(other);
}

template <typename T>
Vector<T>::Vector(Vector<T>&& other)noexcept{
    move(std::move(other));

}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other)noexcept{
    if(this != &other){
        free();
        move(std::move(other));
    }
    return *this;
}

//data Access

template <typename T>
size_t Vector<T>::find(const T& data) const{
    for(size_t i {0}; i < this->size(); i++){
        if(data == this->[i]){
            return i;
        }
    }
    return Vector<T>::nopos;
}
template <typename T>
bool Vector<T>::contains(const T& data) const{
    for(size_t i {0}; i < this->size(); i++){
        if(data == this->[i]){
            return true;
        }
    }
    return false;
}

template <typename T>
T& Vector<T>::operator[](size_t number){
    return _data[number];
}
template <typename T>
const T& Vector<T>::operator[](size_t number) const{
    return _data[number];
}
template <typename T>
T* Vector<T>::data(){
    return _data;
}

template <typename T>
const T& Vector<T>::front() const{
    return _data[0];
}

template <typename T>
const T& Vector<T>::back() const{
    return _data[_size - 1];
}

//_size Modifications


template <typename T>
void Vector<T>::resize(size_t _size){
    resize(_size, T());
}

template <typename T>
void Vector<T>::resize(size_t size, const T& fill){



    T* temp = new T [_capacity];
    for(size_t i {0}; i < (_size > size)? size : _size; i++){
        if(i > _size){
            temp[i] = fill;
        }
        else
            temp[i] = _data[i];
    }

    delete[] _data;
    _size = size;
    _capacity = _size * UPSIZE_BY;
    _data = temp;
}
template <typename T>
size_t Vector<T>::size() const{
    return _size;
}
template <typename T>
size_t Vector<T>::capacity() const{
    return _capacity;
}
template <typename T>
void Vector<T>::reserve(size_t number){
    if(number > _size){
        resize(number);
    }
}

//_data Modificators


template <typename T>
void Vector<T>::push_back(const T& new_data){

    if(_data == nullptr){
        _capacity = DEFAULT_SIZE;
        _data = new T[DEFAULT_SIZE];
    }

    if(_size == _capacity){
        _capacity *= 2;
        resize(_capacity);
    }
    _data[_size++] = new_data;
}

template <typename T>
void Vector<T>::pop_back(){
    _size--;  
    if(_size < _capacity / DOWNSIZE_BY){
        resize(_capacity / UPSIZE_BY);
    }  
}

template <typename T>
void Vector<T>::clear(){
    free();
}




template <typename T>
void Vector<T>::insert(size_t index, const T& toInsert){
    if(_size == _capacity){
        resize(_capacity * UPSIZE_BY);
    }
    for(size_t i = _size ; i > index; i--){
        T& temp = _data[i];
        _data[i] = _data[i - 1];
        _data[i - 1] = _data[i];
    }
    _data[index] = toInsert;
}

template <typename T>
void Vector<T>::erase(size_t index){

    for(size_t i = index; i < _size - 1; i++){
        T& temp = _data[i];
        _data[i] = _data[i + 1];
        _data[i + 1] = _data[i];
    }
    _size--;
}

template <typename T>
void Vector<T>::swap(size_t index1, size_t index2){
    T& temp = _data[index1];
    _data[index1] = _data[index2];
    _data[index2] = temp;
}

template<typename T>
Vector<T>::operator bool() const{
    return(_data == nullptr || _size == 0);
}

