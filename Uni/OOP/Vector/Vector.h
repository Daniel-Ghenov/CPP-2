#pragma once

#include <iostream>
#include "Const.h"

template <class T>
class Vector{
private:
    T* _data;
    size_t _size;
    size_t _capacity;

    void copyFrom(const Vector<T>& other);

public:
    Vector();   //Big 4 and constructors
    Vector(size_t size, const T& fill);
    Vector(size_t size);
    ~Vector();
    Vector& operator=(const Vector<T>& other);
    Vector(const Vector<T>& other);

    T& operator[](size_t number);   //Data access
    const T& operator[](size_t number) const;
    T* data();
    const T& front();
    const T& back();
    
    void resize(size_t size);   //Size Modifications
    void resize(size_t size, const T& fill);
    size_t size();
    size_t capacity();
    void reserve(size_t number);

    void push_back(const T& newData);   //Data modifications
    void pop_back();
    void insert(size_t index, const T& toInsert);
    void erase(size_t index);
    void swap(size_t index1, size_t index2);
    void clear();



};