#pragma once
#include <initializer_list>
#include <iostream>
#include "../Iterator\RandomAccess\RAReverseIter.hpp"

static const int VECTOR_UPSIZE_BY = 2;
static const int VECTOR_DOWNSIZE_BY = 4;
static const int VECTOR_DEFAULT_SIZE = 8;


template <typename T>
class Vector{
public:
    class Iterator: public RABaseIter<T>{ };

    class ConstIterator: public RABaseCIter<T>{ };

    class RIterator : public RABaseRIter<T>{ };

    class ConstRIterator : public RABaseCRiter<T>{ };

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

    Vector(const std::initializer_list<T>& initList);


    bool contains(const T& data) const;
    size_t find(const T& data) const;
    T& operator[](size_t number);   //Data access
    const T& operator[](size_t number) const;
    T* data();
    const T& front() const;
    const T& back() const;
    operator bool() const;
    bool empty() const;

    void resize(size_t size);   //Size Modifications
    void resize(size_t size, const T& fill);
    size_t size() const;
    size_t capacity() const;
    void reserve(size_t number);

    void push_back(const T& newData);   //Data modifications
    void pop_back();
    void insert(size_t index, const T& toInsert);
    void erase(size_t index);
    void swap(size_t index1, size_t index2);
    void clear() noexcept;

    Iterator end();     //Iterators
    ConstIterator cend() const;
    Iterator begin();
    ConstIterator cbegin() const;

    RIterator rend();     //Reverse Iterators
    ConstRIterator crend() const;
    RIterator rbegin();
    ConstRIterator crbegin() const;


private:
    void move(Vector<T>&& other);
    void copyFrom(const Vector<T>& other);
    void free()noexcept;


};



//Big 4 and Constructors


template <typename T>
Vector<T>::Vector(){
    _data = nullptr;
    _size = 0;
    _capacity = VECTOR_DEFAULT_SIZE;
}

template <typename T>
Vector<T>::Vector(size_t _size): Vector(_size, T()){}

template <typename T>
Vector<T>::Vector(size_t size, const T& fill){
    _size = size;
    _capacity = _size * VECTOR_UPSIZE_BY;
    _data = new T[_capacity];
    for(size_t i {0}; i < size;i++){
        _data[i] = fill;
    }
    
}
template <typename T>
Vector<T>::~Vector(){
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

template <typename T>
Vector<T>::Vector(const std::initializer_list<T>& initList){
    _size = initList.size();
    _capacity = _size * VECTOR_UPSIZE_BY;
    _data = new T[_capacity];
    for(size_t i {0}; i < _size; i++){
        _data[i] = initList[i];
    }
}

//data Access

template <typename T>
size_t Vector<T>::find(const T& data) const{
    for(size_t i {0}; i < this->size(); i++){
        if(data == (*this)[i]){
            return i;
        }
    }
    return Vector<T>::nopos;
}
template <typename T>
bool Vector<T>::contains(const T& data) const{
    for(size_t i {0}; i < this->size(); i++){
        if(data == (*this)[i]){
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

template <typename T>
bool Vector<T>::empty() const{
    return _size == 0;
}


//_size Modifications


template <typename T>
void Vector<T>::resize(size_t _size){
    resize(_size, T());
}

template <typename T>
void Vector<T>::resize(size_t size, const T& fill){


    _capacity = size * VECTOR_UPSIZE_BY;

    T* temp = new T [_capacity];
    for(size_t i {0}; i <((_size > size)? size : _size); i++){
        if(i > _size){
            temp[i] = fill;
        }
        else
            temp[i] = _data[i];
    }

    _size = (_size > size)? size : _size;
    delete[] _data;
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
        _capacity = VECTOR_DEFAULT_SIZE;
        _data = new T[VECTOR_DEFAULT_SIZE];
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
    if(_size < _capacity / VECTOR_DOWNSIZE_BY){
        resize(_capacity / VECTOR_UPSIZE_BY);
    }  
}

template <typename T>
void Vector<T>::clear() noexcept{
    free();
}




template <typename T>
void Vector<T>::insert(size_t index, const T& toInsert){
    if(_size == _capacity){
        resize(_capacity * VECTOR_UPSIZE_BY);
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

template<typename T>
Vector<T>::Iterator Vector<T>::end(){
    return Vector<T>::Iterator(_data + size());
}
template<typename T>
Vector<T>::ConstIterator Vector<T>::cend() const{
    return Vector<T>::Constterator(_data + size());
    
}
template<typename T>
Vector<T>::Iterator Vector<T>::begin(){
    return Vector<T>::Iterator(_data);
    
}
template<typename T>
Vector<T>::ConstIterator Vector<T>::cbegin() const{
    return Vector<T>::Constterator(_data);
   
}

template<typename T>
Vector<T>::RIterator Vector<T>::rend(){
    return Vector<T>::RIterator(_data - 1);
}     
template<typename T>
Vector<T>::ConstRIterator Vector<T>::crend() const{
    return Vector<T>::ConstRIterator(_data - 1);
}
template<typename T>
Vector<T>::RIterator Vector<T>::rbegin(){
    return Vector<T>::RIterator(_data + size() - 1);
}
template<typename T>
Vector<T>::ConstRIterator Vector<T>::crbegin() const{
    return Vector<T>::ConstRIterator(_data + size() - 1);
}



template <typename T>
void Vector<T>::copyFrom(const Vector<T>& other){
    _data = new T[other.capacity()];
    for(size_t i {0}; i < other._size; i++){
        _data[i] = other._data[i];
    }
    _size = other._size;
    _capacity = other.capacity();
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
