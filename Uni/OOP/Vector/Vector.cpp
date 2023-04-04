#include "Vector.h"

template <class T>
void Vector<T>::copyFrom(const Vector<T>& other){
    this->_data = new T[other.capacity];
    for(size_t i {0}; i < other._size; i++){
        _data[i] = other._data[i];
    }
    this->_size = other._size;
    this->capacity = other.capacity;
}
//Big 4 and Constructors


template <class T>
Vector<T>::Vector(){
    this->_data = nullptr;
    this->_size = 0;
    this->capacity = DEFAULT_SIZE;
}

template <class T>
Vector<T>::Vector(size_t _size): Vector(_size, T()){}

template <class T>
Vector<T>::Vector(size_t _size, const T& fill){
    this->_size = _size;
    this->_data = new T[_size];
    for(size_t i {0}; i < _size;i++){
        this->_data[i] = fill;
    }
    if(_size > capacity){
        this->capacity = _size * UPSIZE_BY;
    }
    
}
template <class T>
Vector<T>::~Vector(){
    this->clear();
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other){
    if(this != &other){
        this->clear();
        this->copyFrom(other);
    }
    return *this;
}
template <class T>
Vector<T>::Vector(const Vector<T>& other){
    this->copyFrom(other);
}


//data Access


template <class T>
T& Vector<T>::operator[](size_t number){
    return this->_data[number];
}
template <class T>
const T& Vector<T>::operator[](size_t number) const{
    return this->_data[number];
}
template <class T>
T* Vector<T>::data(){
    return this->_data;
}

template <class T>
const T& Vector<T>::front(){
    return this->_data[0];
}

template <class T>
const T& Vector<T>::back(){
    return this->_data[_size - 1];
}

//_size Modifications


template <class T>
void Vector<T>::resize(size_t _size){
    this->resize(_size, T());
}

template <class T>
void Vector<T>::resize(size_t _size, const T& fill){



    T* temp = new T [this->capacity];
    for(size_t i {0}; i < (_size > this->_size)? this->_size : _size; i++){
        if(i > this->_size){
            temp[i] = fill;
        }
        else
            temp[i] = this->_data[i];
    }

    delete[] _data;
    this->_size = _size;
    this->capacity = _size * UPSIZE_BY;
    this->_data = temp;
}
template <class T>
size_t Vector<T>::size(){
    return this->size;
}
template <class T>
size_t Vector<T>::capacity(){
    return this->capacity;
}
template <class T>
void Vector<T>::reserve(size_t number){
    if(number > this->_size){
        this->re_size(number);
    }
}

//_data Modificators


template <class T>
void Vector<T>::push_back(const T& new_data){
    if(_data == nullptr){
        this->capacity = DEFAULT_SIZE;
        this->_size++;
    }
    if(this->_size == this->capacity){
        this->capacity *= 2;
        this->re_size(capacity);
    }
    this->_data[_size++] = new_data;
}

template <class T>
void Vector<T>::pop_back(){
    this->_size--;  
    if(this->_size < this->capacity / DOWNSIZE_BY){
        re_size(this->capacity / UPSIZE_BY);
    }  
}

template <class T>
void Vector<T>::clear(){
    delete[] this->_data;
    this->_data = nullptr;
    this->_size = this->capacity = 0;
}

template <class T>
void Vector<T>::insert(size_t index, const T& toInsert){
    if(this->_size == this->capacity){
        this->re_size(this->capacity * UPSIZE_BY);
    }
    for(size_t i = this->_size ; i > index; i--){
        T& temp = this->_data[i];
        this->_data[i] = this->_data[i - 1];
        this->_data[i - 1] = _data[i];
    }
    this->_data[index] = toInsert;
}

template <class T>
void Vector<T>::erase(size_t index){

    for(size_t i = index; i < _size - 1; i++){
        T& temp = this->_data[i];
        this->_data[i] = this->_data[i + 1];
        this->_data[i + 1] = _data[i];
    }
    this->_size--;
}

template <class T>
void Vector<T>::swap(size_t index1, size_t index2){
    T& temp = this->_data[index1];
    this->_data[index1] = this->_data[index2];
    this->_data[index2] = temp;
}

