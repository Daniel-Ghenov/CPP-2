#include "Node.h"

Node::Node(int _data){
    this->_data = _data;
    _sons = new Node*[_capacity];
    for(size_t i {0};i < _capacity; i++){
        _sons[i] = nullptr;
    }
}

Node::Node(const Node& other){
    copyFrom(other);
    
}
Node::Node(size_t cap, int _data = 0){

}
Node::~Node(){
    free();
}

Node& Node::operator=(const Node& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;

}



void Node::add_son(int _data){
    if(_size == _capacity)
        resize(_capacity * UPSIZE_BY);

    _sons[_size++] = new Node(_data);
    
}
void Node::remove_son(size_t index){

    if(index > _size)
        throw std::out_of_range("Out of Range");
    
    swap(*(_sons[index]), *(_sons[--_size]));

    if(_size < _capacity / DOWNSIZE_BY)
        resize(_capacity / UPSIZE_BY);
}

void Node::free(){
    
    for(size_t i {0}; i < _size; i++)
        (*_sons[i]).free();
    delete[] _sons;
    _sons = nullptr;
    _data = 0;
}

void Node::copyFrom(const Node& other){

    _sons = new Node* [other._capacity];
    for(size_t i {0}; i < other._size; i++){
        _sons[i] = other._sons[i];
    }

    _data = other._data;
    _capacity = other._capacity;
    _size = other._size;
}

void Node::resize(size_t _size){
    Node** newSons = new Node*[_size];
    this->_size = (_size > _capacity)? _size : this->_size;

    for(size_t i {0}; i < this-> _size; i++){
        newSons[i] = _sons[i];
    }
    delete[] _sons;
    _sons = newSons;
    _capacity = _size;
}
void swap(Node& lhs, Node& rhs){

    Node temp = lhs;
    lhs = rhs;
    rhs = temp;

}
int& Node::data(){
    return _data;
}
size_t Node::capacity(){
    return _capacity;
}
Node** Node::sons(){
    return _sons;
}
size_t Node::size(){
    return _size;
}