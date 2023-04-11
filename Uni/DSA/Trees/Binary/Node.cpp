#include "Node.h"

Node::Node(const Node& other){
    copyFrom(other);
}
Node::Node(int data){
    this->data = data;
}

Node& Node::operator=(const Node& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

Node::~Node(){
    free();
}

void Node::free(){
    (*left).free();
    (*right).free();
    delete left;
    delete right;
    left = right = nullptr;
    data = 0;
}

void Node::copyFrom(const Node& other){
    (*left).copyFrom(*other.left);
    (*right).copyFrom(*other.right);
    data = other.data;

}

