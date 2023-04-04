#include "Vector.h"

template <class T>
void Vector<T>::copyFrom(const Vector<T>& other){
    data = new T[other.maxSize];
    for(size_t i {0}; i < other.size; i++){
        data[i] = other.data[i];
    }
    size = other.size;
    maxSize = other.maxSize;
}

template <class T>
Vector<T>::Vector(){
    data = nullptr;
    size = 0;
    maxSize = 4;
}

template <class T>
void Vector<T>::clear(){
    delete[] data;
    data = nullptr;
    size = maxSize = 0;
}

template <class T>
Vector<T>::Vector(size_t size, const T& fill){
    this->size = size;
    data = new T[size];
    for(size_t i {0}; i < size;i++){
        data[i] = fill;
    }
    if(size > maxSize){
        maxSize = size * 2;
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
template <class T>
void Vector<T>::app(const T& newData){
    if(data == nullptr){
        maxSize = 4;
        size++;
        
        
    }
    if(size == maxSize){
        maxSize *= 2;
        resize(maxSize);
    }
    data[size++] = newData;
}
template <class T>
void Vector<T>::popback(){
    size--;    
}

template <class T>
void Vector<T>::resize(size_t size){
    resize(size, T());
}

template <class T>
void Vector<T>::resize(size_t size, const T& fill){
    T* temp = new T [2 * size];
    for(size_t i {0}; i < (size > this->size)? this->size : size; i++){
        if(i > this->size){
            temp[i] = fill;
        }
        else
            temp[i] = data[i];
    }

    clear();
    this->size = size;
    this->maxSize = 2 * size;
    data = temp;
}
