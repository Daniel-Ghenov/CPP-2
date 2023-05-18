#pragma once
#include <iostream>
#include "Node.hpp"

template <typename T>
class PriorityQueue{
private:
    Node<T>* head = nullptr;
    size_t _maxPriority = 0;


public:
    PriorityQueue(size_t priority);
    ~PriorityQueue();
    PriorityQueue(const PriorityQueue<T>& other);
    PriorityQueue(PriorityQueue<T>&& other);
    PriorityQueue<T>& operator=(const PriorityQueue<T>& other);
    PriorityQueue<T>& operator=(PriorityQueue<T>&& other);

    void push(const T& data, size_t priority);
    void push(T&& data, size_t priority);
    void pop();
    const T& peek() const;

private:

    void free();
    void copyFrom(const PriorityQueue<T>& other);
    void move(PriorityQueue<T>&& other);
};


template <typename T>
PriorityQueue<T>::~PriorityQueue(){
    free();
}

template <typename T>
PriorityQueue<T>::PriorityQueue(size_t priority){
    _maxPriority = priority;
}

template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& other){
    copyFrom(other);
}

template <typename T>
PriorityQueue<T>::PriorityQueue(PriorityQueue<T>&& other){
    move(std::move(other));
}


template <typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(PriorityQueue<T>&& other){
    if(this != &other){
        free();
        move(std::move(other));
    }
    return *this;
}

template <typename T>
void PriorityQueue<T>::push(const T& data, size_t priority){
    if(priority > _maxPriority)
        throw std::invalid_argument("Priority too large!");



    if(!head){
        head = new Node<T>(data, priority);
        return;
    }

    if(head->priority < priority){
        head = new Node<T>(data, priority, head);
        return;
    }

    Node<T>* iter = head;
    while(iter->next){
        if(iter->next->priority < priority){
            iter->next = new Node<T>(data, priority, iter->next);
            return;
        }
    }
    iter->next = new Node<T>(data, priority);

}

template <typename T>
void PriorityQueue<T>::push(T&& data, size_t priority){
    if(priority > _maxPriority)
        throw std::invalid_argument("Priority too large!");


    if(!head){
        head = new Node<T>(std::move(data), priority);
        return;
    }

    if(head->priority < priority){
        head = new Node<T>(std::move(data), priority, head);
        return;
    }

    Node<T>* iter = head;
    while(iter->next){
        if(iter->next->priority < priority){
            iter->next = new Node<T>(std::move(data), priority, iter->next);
            return;
        }
        iter = iter->next;
    }
    iter->next = new Node<T>(std::move(data), priority);

}
template <typename T>
void PriorityQueue<T>::pop(){
    if(!head)
        throw std::out_of_range("Priority Queue is empty");

    Node<T>* temp = head->next;
    delete[] head;
    head = temp;
}
template <typename T>
const T& PriorityQueue<T>::peek() const{
    if(!head)
        throw std::out_of_range("Priority Queue is empty");
    return head->data;
}


template <typename T>
void PriorityQueue<T>::free(){
    if(!head)
        return;
    Node<T>* iter = head->next;
    while(iter != nullptr){
        delete[] head;
        head = iter;
        iter = iter->next;
    }
    head->data = 0;
}
template <typename T>
void PriorityQueue<T>::copyFrom(const PriorityQueue<T>& other){
    Node<T>* otherIter = other.head->next;
    head = new Node(other.head->data);
    Node<T>* thisIter = head;

    while(otherIter != nullptr){
        thisIter->next = new Node<T>(otherIter->data);
        thisIter = thisIter->next;
        otherIter = otherIter->next;
    }
}
template <typename T>
void PriorityQueue<T>::move(PriorityQueue<T>&& other){
    head = other.head;
    _maxPriority = other._maxPriority;
}
