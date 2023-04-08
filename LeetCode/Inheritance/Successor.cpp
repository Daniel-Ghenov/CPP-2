#include "Successor.h"

Successor::Successor(std::string name){
    this->_name = name; 
}
Successor::~Successor(){
    free();

}
Successor::Successor(const Successor& other){
    copyFrom(other);

}
Successor& Successor::operator=(const Successor& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;

}

void Successor::free(){
    delete[] _children;
    _children = nullptr;
    _size = 0;

}
void Successor::copyFrom(const Successor& other){
    _size = other._size;
    _children = new Successor*[_size];
    for(size_t i {0}; i < _size; i++){
        _children[i] = other._children[i];
    }
    _name = other._name;

}
void Successor::resize(size_t size){
    
    size_t cycleTo = (size > _size)? _size : size;
    
    Successor** newChildren = new Successor*[size];

    for(size_t i {0}; i < cycleTo; i++){
        newChildren[i] = _children[i];
    }
    delete[] _children;
    _children = newChildren;
    _capacity = size;
}


std::string Successor::name() const{
    return _name;
}


std::string& Successor::name(){
    return _name;
}

Successor** Successor::children() const{
    return _children;
}

Successor** Successor::children(){
    return _children;
}

size_t Successor::size() const{
    return _size;
}


Successor* Successor::operator[](size_t index){
    return _children[index];
}

void Successor::kill(){
    _children = nullptr;
    _capacity =_size = 0;
}

void Successor::removeChild(std::string name){
    for(size_t i {0}; i < size(); i++){
        if(_children[i]->name() == name){
            delete _children[i];
            _children[i] = _children[--_size];
        }
    }
}

void Successor::addChild(std::string name){
    if(_capacity == 0){
        resize(2);
    }
    if(_size == _capacity){
        resize(_capacity * UPSIZE_BY);
    }
    _children[_size++] = new Successor(name);
}

void Successor::addChildren(Successor** children, size_t childCount){
    Successor** newChildren = new Successor*[childCount + _size * UPSIZE_BY];
    for(size_t i {0}; i < childCount; i++){
        newChildren[i] = children[i];
    }
    for(size_t i {0}; i < _size; i++){
        newChildren[i] = _children[i];
    }
    _children = newChildren;
    _size += childCount;
    _capacity = _size * UPSIZE_BY;
}

