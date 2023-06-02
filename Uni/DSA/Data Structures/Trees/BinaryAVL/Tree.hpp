#pragma once
#include <iostream>
#include "Node.hpp"

template <typename T>
class Tree{
private:
    Node<T>* root = nullptr;
public:
    Tree() = default;
    Tree(const Tree& other);
    Tree& operator=(const Tree& other);
    ~Tree();

    void add(const T& data);
    void remove(const T& data);
    bool contains(const T& data) const;
    void print() const;

private:

    void free();
    void copyFrom(const Tree& other);

    void _add(const T& data, Node<T>*& current);
    void _remove(const T& data, Node<T>*& current);
    bool _contains(const T& data, Node<T>* current) const;
    void _print(Node<T>* current) const;

    static void _leftRotate(Node<T>*& current);
    static void _rightRotate(Node<T>*& current);
    static int getBalance(Node<T>* node);
    static void balanceLeft(Node<T>*& root);
    static void balanceRight(Node<T>*& root);
};


template <typename T>
Tree<T>::Tree(const Tree& other){
    copyFrom(other);

}

template <typename T>
Tree<T>& Tree<T>::operator=(const Tree& other){

    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
Tree<T>::~Tree(){
    free();

}


template <typename T>
void Tree<T>::free(){
    (*root).~Node();
    root = nullptr;

}

template <typename T>
void Tree<T>::copyFrom(const Tree& other){
    (*root) = (*other.root);

}

template <typename T>
void Tree<T>::_add(const T& data, Node<T>*& current){
    
    if(current == nullptr){
        current = new Node(data);
        return;
    }
    else if(current->data > data){
        current->left = _add(data, current->left);

        balanceLeft(current);
        current->updateHeight();

    }
    else{
        current->right = _add(data, current->right);

        balanceRight(currnet);
        current->updateHeight();
    }

    return current;
    
}
template <typename T>
void Tree<T>::_remove(const T& data, Node<T>*& current){
    
    
}
template <typename T>
void Tree<T>::_print(Node<T>* current) const{
    if(current->left)
        _print(current->left);
    
    std::cout<<current->data;

    if(current->right)
        _print(current->right);
    
}
template <typename T>
bool Tree<T>::_contains(const T& data, Node<T>* current) const{
    if(current == nullptr)
        return false;
    if(current->data == data)
        return true;

    return (current->data > data)? _contains(data, current->left): _contains(data, current->right);    
}


template <typename T>
int Tree<T>::getBalance(Node<T>* node){
    return node->left->height() - node->right->height();
}


template <typename T>
void Tree<T>::add(const T& data){
    
    _add(data, root);

}
template <typename T>
void Tree<T>::remove(const T& data){
    
    _remove(data, root);

}
template <typename T>
bool Tree<T>::contains(const T& data) const{
    
    _contains(data, root);

}
template <typename T>
void Tree<T>::print() const{
    _print(root);

}
template <typename T>
void Tree<T>::_leftRotate(Node<T>*& current){

    Node<T>* originalRight = current->right;

    if(!originalRight){
        throw std::runtime_error("Empty right Branch");
    }
    
    current->right = originalRight->right;
    originalRight->right = originalRight->left;
    originalRight->left = current->left;
    current->left = originalRight;

}
template <typename T>
void Tree<T>::_rightRotate(Node<T>*& current){

    Node<T>* originalLeft = current->left;

    if(!originalLeft)
        throw std::runtime_error("Empty Left Branch");
    
    current->left = originalLeft->left;
    originalLeft->left = originalLeft->right;
    originalLeft->right = current->right;
    current->right = originalLeft;

}

template <typename T>
void Tree<T>::balanceLeft(Node<T>*& root){
    assert(root != nullptr);

    int rootBal = getBalance(root);
    int subRootBal = getBalance(root->right);

    if(rootBal == 2){

        if(subRootBal == -1){
            _rightRotate(root->right);
            root->right->updateHeight();
            root->right->right->updateHeight();
            
        }

        _leftRotate(root);
        root->left->updateHeight();
        root->updateHeight();
    }

}

template <typename T>
void Tree<T>::balanceRight(Node<T>*& root){
    assert(root != nullptr);

    int rootBal = getBalance(root);
    int subRootBal = getBalance(root->left);

    if(rootBal == -2){

        if(subRootBal == 1){
            _leftRotate(root->left);
            root->left->updateHeight();
            root->left->left->updateHeight();
            
        }

        _rightRotate(root);
        root->right->updateHeight();
        root->updateHeight();
    }

}