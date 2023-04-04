#include "vector.h"

template <class T>
Vector<T>::Vector(){
    data = nullptr;
    size = 0;
    maxSize = 8;
}

template <class T>
Vector<T>::Vector(size_t size, const T& fill){
    this->size = size;
    data = new T[size];
    for(size_t i {0}; i < size;i++){
        data[i] = fill;
    }
    
}
template <class T>
Vector<T>::~Vector(){
    clear();s
}
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other){
    
}
template <class T>
Vector<T>::Vector(const Vector<T>& other){
    
}
template <class T>
void Vector<T>::app(T newData){
    
}
template <class T>
void Vector<T>::popback(){
    
}
template <class T>
void Vector<T>::clear(){
    delete[] data;
    data = nullptr;
    size = maxSize = 0;
}

template <class T>
void Vector<T>::resize(size_t size){

}
template <class T>
void Vector<T>::copyFrom(const Vector<T>& other){
    data = new T[other.maxSize];
    for(size_t i {0}; i < other.size; i++){
        data[i] = other.data[i];
    }
    size = otehr.size;
    maxSize = other.maxSize;
}
