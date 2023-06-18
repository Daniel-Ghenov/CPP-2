#pragma once
#include <iostream>
#include "Queue.hpp"

template <typename T>
class Queue{
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

public:

    Queue() = default;
    Queue(const Queue<T>& other);
    Queue(Queue<T>&& other);
    Queue<T>& operator=(const Queue<T>& other);
    Queue<T>& operator=(Queue<T>&& other);


    void push(const T& data);
    void push(T&& data);
    void pop();
    const T& peek() const;

    bool empty() const;

private:
    void free();
    void copyFrom(const Queue<T>& other);
    void move(Queue<T>&& other);
};

template <typename T>
Queue<T>::Queue(const Queue<T>& other){
    copyFrom(other);
}

template <typename T>
Queue<T>::Queue(Queue<T>&& other){
    move(std::move(other));
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& other){
    if(this != &other){
        free();
        move(std::move(other));
    }
    return *this;
}


template <typename T>
void Queue<T>::push(const T& data){

    if(!head){
        head = new Node<T>(data, nullptr);
        tail = head;
        return;
    }

    tail->next = new Node<T>(data, nullptr);
    tail = tail->next;
}

template <typename T>
void Queue<T>::push(T&& data){

    if(!head){
        head = new Node<T>(data, nullptr);
        tail = head;
        return;
    }

    tail->next = new Node<T>(std::move(data), nullptr);
    tail = tail->next;
}

template <typename T>
void Queue<T>::pop(){
    if(!head)
        throw std::out_of_range("Queue is empty");

    if(tail == head){
        delete head;
        head = tail = nullptr;
        return;
    }
        
    Node<T>* newHead = head->next;
    delete head;
    head = newHead;
}

template <typename T>
const T& Queue<T>::peek() const{
    return head;
}

template <typename T>
bool Queue<T>::empty() const{
    return !head;
}


template <typename T>
void Queue<T>::free(){
    if(!head)
        return;

    for(Node<T>* it = head->next; it != nullptr; it = it->next){
        delete head;
        head = it;
    }
    delete it;
    head = nullptr;
}

template <typename T>
void Queue<T>::copyFrom(const Queue<T>& other){

    Node* otherIter = other.head->next;
    head = new Node(other.head->data);
    Node* thisIter = head;

    while(otherIter != nullptr){
        thisIter->next = new Node(otherIter->data);
        thisIter = thisIter->next;
        otherIter = otherIter->next;
    }
}

template <typename T>
void Queue<T>::move(Queue<T>&& other){

    head = other.head;
    other.head = nullptr;
}

