#pragma once

template <typename T>
struct Node{

    T data;
    bool color = false; //false is black true is red
    Node<T>* parent = nullptr;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;

    Node() = default;
    Node(const T& data, bool color, Node<T>* parent);
    Node(const T& data, bool color);

};


template <typename T>
Node<T>::Node(const T& data,bool color, Node<T>* parent ): data(data), color(color), parent(parent) {}

template <typename T>
Node<T>::Node(const T& data, bool color): data(data), color(color) {}
