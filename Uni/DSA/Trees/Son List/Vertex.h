#pragma once
#include <iostream>
#include "Const.h"

class Vertex{
private:
    int data = 0;
    Vertex** sons = nullptr;
    size_t capacity = DEFAULT_CAP_VERTEX;
    size_t size = 0;

public:
    Vertex() = default;
    Vertex(int data);
    Vertex(size_t cap, int data);
    Vertex(const Vertex& other);
    ~Vertex();
    Vertex& operator=(const Vertex& other);
    
    void add_son(int data);
    void remove_son(size_t index);
    

    
public:
    void free();
    void copyFrom(const Vertex& other);
    void resize(size_t size);
};

void swap(Vertex& lhs, Vertex& rhs);
