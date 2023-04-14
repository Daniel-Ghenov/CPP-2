#pragma once

template <typename T>
class Node{
private:
    T data = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    size_t _height = 1;

public:
    Node() = default;
    Node(const Node& other);
    Node& operator=(const Node& other);
    ~Node();
    Node(const T& data);

    size_t height();
    void updateHeight();

private:
    void free();
    void copyFrom(const Node& other);


    friend class Tree;
};

template <typename T>
Node<T>::Node(const Node& other){
    copyFrom(other);
}
template <typename T>
Node<T>::Node(const T& data){
    this->data = data;
}

template <typename T>
Node<T>& Node<T>::operator=(const Node& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
void Node<T>::updateHeight(){
    if(!this)
        return;
    height = std::max(right->height(), left->height()) + 1;

}

template <typename T>
Node<T>::~Node(){
    free();
}

template <typename T>
void Node<T>::free(){
    (*left).free();
    (*right).free();
    delete left;
    delete right;
    left = right = nullptr;
    data = 0;
}

template <typename T>
void Node<T>::copyFrom(const Node& other){
    left->copyFrom(*other.left);
    right->copyFrom(*other.right);
    data = other.data;

}
template <typename T>
size_t Node<T>::height(){
    if(this)
        return _height;
    return 0;
}
