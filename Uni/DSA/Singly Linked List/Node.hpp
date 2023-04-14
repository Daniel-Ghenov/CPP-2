#pragma once

template <typename T>
struct Node{
private:

    T data;
    Node<T>* next = nullptr;

public:
    Node<T>(const T& data);
    Node<T>(const Node<T>& other);
    Node<T>& operator=(const Node<T>& other);

    friend class List;
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
Node<T>& Node<T>::operator=(const Node<T>& other){
    data = other.data;
    return *this;
}