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

    delete left;
    delete right;
    left = right = nullptr;
    data = 0;
}

void Node::copyFrom(const Node& other){
    if(other.left){
        left = new Node(*other.left);
    }
    if(other.right){
        right = new Node(*other.right);
    }
    data = other.data;

}

