#include "Vector.h"

template <class T>
void Vector<T>::copyFrom(const Vector<T>& other){
    _data = new T[other.capacity];
    for(size_t i {0}; i < other._size; i++){
        _data[i] = other._data[i];
    }
    _size = other._size;
    capacity = other.capacity;
}
//Big 4 and Constructors


template <class T>
Vector<T>::Vector(){
    _data = nullptr;
    _size = 0;
    capacity = DEFAULT_SIZE;
}

template <class T>
Vector<T>::Vector(size_t _size): Vector(_size, T()){}

template <class T>
Vector<T>::Vector(size_t _size, const T& fill){
    _size = _size;
    _data = new T[_size];
    for(size_t i {0}; i < _size;i++){
        _data[i] = fill;
    }
    if(_size > capacity){
        capacity = _size * UPSIZE_BY;
    }
    
}
template <class T>
Vector<T>::~Vector(){
    clear();
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other){
    if(this != &other){
        clear();
        copyFrom(other);
    }
    return *this;
}
template <class T>
Vector<T>::Vector(const Vector<T>& other){
    copyFrom(other);
}


//data Access


template <class T>
T& Vector<T>::operator[](size_t number){
    return _data[number];
}
template <class T>
const T& Vector<T>::operator[](size_t number) const{
    return _data[number];
}
template <class T>
T* Vector<T>::data(){
    return _data;
}

template <class T>
const T& Vector<T>::front(){
    return _data[0];
}

template <class T>
const T& Vector<T>::back(){
    return _data[_size - 1];
}

//_size Modifications


template <class T>
void Vector<T>::resize(size_t _size){
    resize(_size, T());
}

template <class T>
void Vector<T>::resize(size_t _size, const T& fill){



    T* temp = new T [capacity];
    for(size_t i {0}; i < (_size > _size)? _size : _size; i++){
        if(i > _size){
            temp[i] = fill;
        }
        else
            temp[i] = _data[i];
    }

    delete[] _data;
    _size = _size;
    capacity = _size * UPSIZE_BY;
    _data = temp;
}
template <class T>
size_t Vector<T>::size(){
    return size;
}
template <class T>
size_t Vector<T>::capacity(){
    return capacity;
}
template <class T>
void Vector<T>::reserve(size_t number){
    if(number > _size){
        resize(number);
    }
}

//_data Modificators


template <class T>
void Vector<T>::push_back(const T& new_data){
    if(_data == nullptr){
        capacity = DEFAULT_SIZE;
        _size++;
    }
    if(_size == capacity){
        capacity *= 2;
        re_size(capacity);
    }
    _data[_size++] = new_data;
}

template <class T>
void Vector<T>::pop_back(){
    _size--;  
    if(_size < capacity / DOWNSIZE_BY){
        re_size(capacity / UPSIZE_BY);
    }  
}

template <class T>
void Vector<T>::clear(){
    delete[] _data;
    _data = nullptr;
    _size = capacity = 0;
}

template <class T>
void Vector<T>::insert(size_t index, const T& toInsert){
    if(_size == capacity){
        re_size(capacity * UPSIZE_BY);
    }
    for(size_t i = _size ; i > index; i--){
        T& temp = _data[i];
        _data[i] = _data[i - 1];
        _data[i - 1] = _data[i];
    }
    _data[index] = toInsert;
}

template <class T>
void Vector<T>::erase(size_t index){

    for(size_t i = index; i < _size - 1; i++){
        T& temp = _data[i];
        _data[i] = _data[i + 1];
        _data[i + 1] = _data[i];
    }
    _size--;
}

template <class T>
void Vector<T>::swap(size_t index1, size_t index2){
    T& temp = _data[index1];
    _data[index1] = _data[index2];
    _data[index2] = temp;
}

