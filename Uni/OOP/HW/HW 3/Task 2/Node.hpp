#pragma once
#include "SharedPtr.hpp"

template <typename T>
struct Node{
    T data;
    size_t priority = 0;
    SharedPtr<Node<T>> next = nullptr;

    Node(const T& data, size_t priority ,SharedPtr<Node> next);
    Node(T&& data,size_t priority ,SharedPtr<Node> next);
    Node(T&& data, size_t priority);
    Node(const T& data, size_t priority);

};

template <typename T>
Node<T>::Node(const T& data, size_t priority){
    this->data = data;
    this->priority = priority;
}

template <typename T>
Node<T>::Node(T&& data, size_t priority){
    this->data = std::move(data);
    this->priority = priority;
}

template <typename T>
Node<T>::Node(const T& data, size_t priority ,SharedPtr<Node> next){
    this->data = data;
    this->priority = priority;
    this->next = next;
}
template <typename T>

Node<T>::Node(T&& data, size_t priority ,SharedPtr<Node> next){
    this->data = std::move(data);
    this->priority = priority;
    this->next = next;
}

