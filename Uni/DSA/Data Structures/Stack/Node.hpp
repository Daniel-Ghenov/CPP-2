#pragma once

template <typename T>
struct Node{
    T data;
    Node<T>* next = nullptr;

    Node(const T& data, Node* next);
    Node(T&& data, Node* next);
    Node(const T& data);
    Node(T&& data);
    Node(const Node<T>& other);
    Node<T>& operator=(const Node<T>& other);

};

template <typename T>
Node<T>::Node(const T& data){
    this->data = data;
}
template <typename T>
Node<T>::Node(const Node<T>& other){
    data = other.data;

}

template <typename T>
Node<T>::Node(const T& data, Node* next){
    this->data = data;
    this->next = next;
}
template <typename T>

Node<T>::Node(T&& data, Node* next){
    this->data = std::move(data);
    this->next = next;
}

template <typename T>
Node<T>::Node(T&& data){
    this->data = std::move(data);
}