#pragma once

template <typename T>
struct Node{
    unsigned key;
    T data;
    bool color; //false is black true is red
    Node<T>* parent;
    Node<T>* left;
    Node<T>* right;

    Node(key, const T& data, Node<T>* parent ,bool color, Node<T>* left, Node<T>* right);
    Node(key, const T& data, Node<T>* parent ,bool color);
    Node(key, const T& data, Node<T>* parent);


};