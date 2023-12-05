#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
struct Node{

    T data;
    Node<T>* next = nullptr;

    Node<T>(const T& data);
    Node<T>(const Node<T>& other);
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

Node* mergeLists(Node* listA, Node* listB){

}

int main() {

    return 0;
}
