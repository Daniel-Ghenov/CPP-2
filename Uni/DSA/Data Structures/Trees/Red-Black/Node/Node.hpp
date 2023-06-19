#pragma once

template <typename T>
struct Node{

    unsigned key = 0;
    T data;
    bool color = false; //false is black true is red
    Node<T>* parent = nullptr;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;

    Node() = default;
    Node(unsigned key, const T& data, bool color, Node<T>* parent);
    Node(unsigned key, const T& data, bool color);


};


template <typename T>
Node<T>::Node(unsigned key, const T& data,bool color, Node<T>* parent ): key(key), data(data), color(color), parent(parent) {}

template <typename T>
Node<T>::Node(unsigned key, const T& data, bool color): key(key), data(data), color(color) {}
