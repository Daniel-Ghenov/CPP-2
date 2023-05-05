#pragma once

template <typename T>
class Node{
private:
    T data = 0;
    Node* next = nullptr;
    Node* prev = nullptr;
public:
    Node() = default;
    Node(int data);
    Node& operator=(const Node& other);
    Node(const Node& other);

    friend class List;
};

template <typename T>
Node<T>::Node(int data){
    this->data = data;
    
}

template <typename T>
Node<T>& Node<T>::operator=(const Node<T>& other){
    this->data = other.data;
    return *this;
}

template <typename T>
Node<T>::Node(const Node<T>& other){
    this->data = other.data;
}