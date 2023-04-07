#include "Vertex.h"

Vertex::Vertex(int data){
    this->data = data;
    sons = new Vertex*[capacity];
    for(size_t i {0};i < capacity; i++){
        sons[i] = nullptr;
    }
}

Vertex::Vertex(const Vertex& other){
    copyFrom(other);
    
}
Vertex::Vertex(size_t cap, int data = 0){

}
Vertex::~Vertex(){
    free();
}

Vertex& Vertex::operator=(const Vertex& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;

}



void Vertex::add_son(int data){
    if(size == capacity)
        resize(capacity * UPSIZE_BY);

    sons[size++] = new Vertex(data);
    
}
void Vertex::remove_son(size_t index){

    if(index > size)
        throw std::out_of_range("Out of Range");
    
    swap(*(sons[index]), *(sons[--size]));

    if(size < capacity / DOWNSIZE_BY)
        resize(capacity / UPSIZE_BY);
}

void Vertex::free(){
    
    delete[] sons;
    sons = nullptr;
    data = 0;
}

void Vertex::copyFrom(const Vertex& other){

    sons = new Vertex* [other.capacity];
    for(size_t i {0}; i < other.size; i++){
        sons[i] = other.sons[i];
    }

    data = other.data;
    capacity = other.capacity;
    size = other.size;
}

void Vertex::resize(size_t size){
    Vertex** newSons = new Vertex*[size];
    this->size = (size > capacity)? size : this->size;

    for(size_t i {0}; i < this-> size; i++){
        newSons[i] = sons[i];
    }
    delete[] sons;
    sons = newSons;
    capacity = size;
}
void swap(Vertex& lhs, Vertex& rhs){

    Vertex temp = lhs;
    lhs = rhs;
    rhs = temp;

}
