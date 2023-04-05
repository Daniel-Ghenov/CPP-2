#include "Node.h"


Node::Node(int data){
    this->data = data;
}
Node::Node(const Node& other){
    data = other.data;

}
Node& Node::operator=(const Node& other){
    data = other.data;
    return *this;
}