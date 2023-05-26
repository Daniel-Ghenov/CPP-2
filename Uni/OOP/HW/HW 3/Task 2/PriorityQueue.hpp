#pragma once
#include <iostream>
#include "Node.hpp"
#include "Vector.hpp"

template <typename T>
class PriorityQueue{
private:
    SharedPtr<Node<T>> head = nullptr;
    size_t _maxPriority = 0;
    Vector<SharedPtr<Node<T>>> insertPos;   //saving the positions of the last nodes with k-th priority for O(1) push

public:
    PriorityQueue(size_t priority);
    PriorityQueue(const PriorityQueue<T>& other);
    PriorityQueue(PriorityQueue<T>&& other);
    PriorityQueue<T>& operator=(const PriorityQueue<T>& other);
    PriorityQueue<T>& operator=(PriorityQueue<T>&& other);

    void push(const T& data, size_t priority);
    void push(T&& data, size_t priority);
    void pop();
    const T& peek() const;
    bool isEmpty() const;

private:

    void copyFrom(const PriorityQueue<T>& other);
    void move(PriorityQueue<T>&& other);
};


template <typename T>
PriorityQueue<T>::PriorityQueue(size_t priority): insertPos(priority, nullptr){
    _maxPriority = priority - 1;
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
        copyFrom(other);
    }
    return *this;
}

template <typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(PriorityQueue<T>&& other){
    if(this != &other){
        move(std::move(other));
    }
    return *this;
}

template <typename T>
void PriorityQueue<T>::push(const T& data, size_t priority){
    if(priority > _maxPriority)
        throw std::invalid_argument("Priority too large!");


    if(insertPos[priority] != nullptr){
        if(insertPos[priority]->next == nullptr){
            insertPos[priority]->next = new Node<T>(std::move(data), priority);
        }else{
            insertPos[priority]->next = new Node<T>(std::move(data), priority, insertPos[priority]->next);
        }
        for(size_t i = priority + 1; i < insertPos.size(); i++){
            if(insertPos[i] == insertPos[priority])
                insertPos[i] = insertPos[priority]->next;
        }
            insertPos[priority] = insertPos[priority]->next;
    }

    if(!head){
        head = new Node<T>(std::move(data), priority);
        for(size_t i = priority ; i < insertPos.size(); i++){
            insertPos[priority] = head;
        }
        return;
    }

}

template <typename T>
void PriorityQueue<T>::push(T&& data, size_t priority){
    if(priority > _maxPriority)
        throw std::invalid_argument("Priority too large!");

    if(insertPos[priority] != nullptr){
        if(insertPos[priority]->next == nullptr){
            insertPos[priority]->next = new Node<T>(std::move(data), priority);
        }else{
            insertPos[priority]->next = new Node<T>(std::move(data), priority, insertPos[priority]->next);

        }
        for(int i = priority - 1; i > 0; i--){

            if(insertPos[i] == insertPos[priority])
                insertPos[i] = insertPos[priority]->next;
        }
            insertPos[priority] = insertPos[priority]->next;
    }
    else{

        head = new Node<T>(std::move(data), priority, head);

        for(int i = priority ; i >= 0; i--){

            if(insertPos[i] == nullptr)
                insertPos[i] = head;
        }
    }

}
template <typename T>
void PriorityQueue<T>::pop(){
    if(!head)
        throw std::out_of_range("Priority Queue is empty");

    SharedPtr<Node<T>> temp = head->next;

    for(size_t i {0}; i < insertPos.size(); i++){
        if(insertPos[i] == head)
            insertPos[i] = nullptr;
    }

    head = std::move(temp);
}
template <typename T>
const T& PriorityQueue<T>::peek() const{
    if(!head)
        throw std::out_of_range("Priority Queue is empty");
    return head->data;
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const{
    return head == nullptr;
}


template <typename T>
void PriorityQueue<T>::copyFrom(const PriorityQueue<T>& other){

    SharedPtr<Node<T>> otherIter = other.head->next;
    head = new Node(other.head->data);
    SharedPtr<Node<T>> thisIter = head;

    while(otherIter != nullptr){
        thisIter->next = new Node<T>(otherIter->data);
        thisIter = thisIter->next;
        otherIter = otherIter->next;
    }
}
template <typename T>
void PriorityQueue<T>::move(PriorityQueue<T>&& other){
    head = std::move(other.head);
    _maxPriority = other._maxPriority;
    insertPos = std::move(other.insertPos);
}
