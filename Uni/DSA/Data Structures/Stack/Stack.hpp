#pragma once
#include <iostream>
#include "Node.hpp"

template <typename T>
class Stack{
private:
    Node<T>* head = nullptr;

public:
    Stack() = default;
    Stack(const Stack& other);
    Stack(Stack&& other);
    Stack<T>& operator=(const Stack<T>& other);
    Stack<T>& operator=(Stack<T>&& other);
    ~Stack();

    void push(const T& data);
    void push(T&& data);
    void pop();
    const T& peek() const;
    bool isEmpty();

private:
    void free();
    void copyFrom(const Stack<T>& other);
    void move(Stack<T>&& other);
};

template <typename T>
Stack<T>::Stack(const Stack& other){
    copyFrom(other);
}
template <typename T>
Stack<T>::Stack(Stack&& other){
    move(std::move(other));
}
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other){

    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}
template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& other){
    
    if(this != &other){
        free();
        move(std::move(other));
    }
    return *this;
}
template <typename T>
Stack<T>::~Stack(){
    free();
}


template <typename T>
void Stack<T>::push(const T& data){
    Node<T>* newHead = new Node<T>(data, head);
    head = newHead;
}

template <typename T>
void Stack<T>::push(T&& data){
    Node<T>* newHead = new Node<T>(std::move(data), head);
    head = newHead;
}

template <typename T>
void Stack<T>::pop(){
    if(head == nullptr)
        throw std::out_of_range("Stack is Empty");
        
    Node<T>* temp = head->next;
    delete head;
    head = temp;
    
}

template <typename T>
const T& Stack<T>::peek() const{
    return head->data;
}

template <typename T>
bool Stack<T>::isEmpty(){
    return (!head);
}

template <typename T>
void Stack<T>::free(){
    while(head){
        Node<T>* temp = head->next;
        delete head;
        head = temp;
    }
}
template <typename T>
void Stack<T>::copyFrom(const Stack<T>& other){
    if(other.head == nullptr)
        return;
    
    head = new Node<T>(other.head->data);
    Node<T>* iter = head;
    Node<T>* otherIter = other.head;

    while(otherIter){
        iter->next = new Node<T>(otherIter->data);
        iter = iter->next;
        otherIter = otherIter->next;
    }
}
template <typename T>
void Stack<T>::move(Stack<T>&& other){
    head = other.head;
    other.head = nullptr;
}
