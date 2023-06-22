#pragma once
#include "Node\Node.hpp"

template <typename T>
class Tree{
private:
        
    Node<T>* root = nullptr;
    Node<T>* nil;

public:

    Tree();
    Tree(const Tree<T>& other);
    Tree(Tree<T>&& other);
    Tree<T>& operator=(const Tree<T>& other);
    Tree<T>& operator=(Tree<T>&& other);
    ~Tree();

    void push(const T& data);
    void push(T&& data);
    bool contains(const T& data);
    

private:

    void free();
    void _free(Node<T>* current);
    void copyFrom(const Tree<T>& other);
    Node<T>* _copyFrom(const Node<T>* otherIter);
    void move(Tree<T>&& other);

    void leftRotate(Node<T>* node);
    void rightRotate(Node<T>* node);
    void insertFix(Node<T>* node);
};

template <typename T>
Tree<T>::Tree(){
    nil = new Node<T>();
    nil->color = false;
    nil->parent = nil->left = nil->right = nil;
    
}


template <typename T>
Tree<T>::Tree(const Tree& other){
    copyFrom(other);
}

template <typename T>
Tree<T>::Tree(Tree&& other){
    move(std::move(other));
}

template <typename T>
Tree<T>& Tree<T>::operator=(const Tree<T>& other){
    
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
Tree<T>& Tree<T>::operator=(Tree<T>&& other){

    if(this != &other){
        free();
        move(std::move(other));
    }
    return *this;
}

template <typename T>
Tree<T>::~Tree(){
    free();
}

template <typename T>
void Tree<T>::push(const T& data){

}

template <typename T>
void Tree<T>::push(T&& data){

}

template <typename T>
bool Tree<T>::contains(const T& data){

}




template <typename T>
void Tree<T>::free(){
    _free(root);
    root = nullptr;
    delete nil;
    nil = nullptr;
}

template <typename T>
void Tree<T>::_free(Node<T>* current){
    if(current == nullptr)
        return;
    
    _free(current->left);
    _free(current->right);

    delete current;

}

template <typename T>
void Tree<T>::copyFrom(const Tree<T>& other){
    
    head = _copyFrom(head, other.head);

}

template <typename T>
Node<T>* Tree<T>::_copyFrom(const Node<T>* otherIter){
    if(!otherIter)
        return nullptr;
    
    Node<T> newNode(otherIter->data, otherIter->color);
    newNode->left = _copyFrom(otherIter->left);
    newNode->right = _copyFrom(otherIter->right);
    return newNode;

}

template <typename T>
void Tree<T>::move(Tree<T>&& other){
    head = other.head;
    head->parent = nil;
    other.head = nullptr;
}