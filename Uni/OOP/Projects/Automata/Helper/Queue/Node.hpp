#pragma once

template <typename T>
struct Node{

    Node<T>* next = nullptr;
    T data;

    Node() = default;
    Node(const T& data);
    Node(T&& data);
    Node(const T& data, Node<T>* next);
    Node(T&& data, Node<T>* next);
};

template <typename T>
Node<T>::Node(const T& data): data(data) {}

template <typename T>
Node<T>::Node(T&& data): data(std::move(data)) {}

template <typename T>
Node<T>::Node(const T& data, Node<T>* next): data(data), next(next){}

template <typename T>
Node<T>::Node(T&& data, Node<T>* next): data(std::move(data)), next(next){}

