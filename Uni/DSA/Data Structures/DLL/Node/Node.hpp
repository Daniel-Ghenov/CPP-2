#pragma once

template <typename T>
struct Node{

    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;

    Node() = default;
    Node(const T& data);
    Node(const T& data, Node<T>* next);
    Node(const T& data, Node<T>* prev, Node<T>* next);

    Node(T&& data);
    Node(T&& data, Node<T>* next);
    Node(T&& data, Node<T>* prev, Node<T>* next);
    

};

template <typename T>
Node<T>::Node(const T& data){
    this->data = data;
    
}

template <typename T>
Node<T>::Node(const T& data, Node<T>* next){
    this->data = data;
    this->next = next;
}

template <typename T>
Node<T>::Node(const T& data, Node<T>* prev, Node<T>* next){
    this->data = data;
    this->prev = prev;
    this->next = next;
}

template <typename T>
Node<T>::Node(T&& data){
    this->data = std::move(data);
    
}

template <typename T>
Node<T>::Node(T&& data, Node<T>* next){
    this->data = std::move(data);
    this->next = next;
}

template <typename T>
Node<T>::Node(T&& data, Node<T>* prev, Node<T>* next){
    this->data = std::move(data);
    this->prev = prev;
    this->next = next;
}