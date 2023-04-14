#include "Tree.h"

Tree::Tree(const Tree& other){
    copyFrom(other);

}
Tree::Tree(int data){
    root = new Node(data);
}

Tree& Tree::operator=(const Tree& other){

    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

Tree::~Tree(){
    free();

}

void Tree::add(int data){
    
    _add(data, root);

}
void Tree::remove(int data){
    
    _remove(data, root);

}
bool Tree::contains(int data) const{
    
    _contains(data, root);

}
void Tree::print() const{
    
    _print(root);

}




Node* Tree::_add(int data, Node* current){
    
    if(current == nullptr){
        return new Node(data);
    }
    else if(current->data > data){
        current->left = _add(data, current->left);
    }
    else{
        current->right = _add(data, current->right);
    }

    return current;
    
}
Node* Tree::_remove(int data, Node* current){
    //WIP
}
void Tree::_print(Node* current) const{
    
    
}
bool Tree::_contains(int data, Node* current) const{
    if(current == nullptr)
        return false;
    if(current->data == data)
        return true;

    return (current->data > data)? _contains(data, current->left): _contains(data, current->right);    
}



void Tree::free(){

    delete root;
    root = nullptr;

}

void Tree::copyFrom(const Tree& other){
    (*root) = (*other.root);

}