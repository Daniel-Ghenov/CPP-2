#pragma once
#include <iostream>
#include "DLL\Node\Node.hpp"

template <typename T>
class List{
private:
    Node<T>* head = nullptr;

public:
    List() = default;
    List(const T& data);
    ~List();
    List& operator=(const List<T>& other);
    List(const List<T>& other);

    void push_back(const T& data);
    void push_front(const T& data);
    void pop_back();
    void pop_front();
    void insert(size_t index, const T& data);
    void remove(size_t index);
    bool contains(const T& data) const;

    void print();

private:

    void free();
    void copyFrom(const List<T>& other);
};

template <typename T>
void List<T>::free(){
    Node<T>* iter = head;
    while(iter->next != nullptr){
        iter = iter->next;
        delete iter->prev;
        iter->prev = nullptr;
    }
    delete iter;
    head = nullptr;
    
}

template <typename T>
void List<T>::copyFrom(const List<T>& other){
    head = new Node<T>(*(other.head));
    Node<T>* otherIter = other.head;
    Node<T>* thisIter = head;
    while(otherIter->next != nullptr){
        thisIter->next = new Node<T>(*(otherIter->next));
        thisIter->next->prev = thisIter;
        thisIter = thisIter->next;
        otherIter = otherIter->next;
    }
    
}

template <typename T>
List<T>::List<T>(const T& data){
    head = new Node<T>(data);
    head->next = head->prev = nullptr;
}
template <typename T>
List<T>::~List<T>(){
    free();
}
template <typename T>
List<T>& List<T>::operator=(const List<T>& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;

}

template <typename T>
List<T>::List<T>(const List<T>& other){
    copyFrom(other);

}

template <typename T>
void  List<T>::push_back(const T& data){
    if(head == nullptr){
        push_front(data);
    }
    Node<T>* iter = head;
    while(iter->next != nullptr){
        iter = iter->next;
    }
    iter->next = new Node<T>(data);
    iter->next->prev = iter;

}

template <typename T>
void  List<T>::push_front(const T& data){
    Node<T>* newHead = new Node<T>(data);
    newHead->next = head;
    head = newHead;

}

template <typename T>
void  List<T>::pop_back(){
    if(head == nullptr){
        throw std::out_of_range("No elements");
    }

    Node<T>* iter = head;
    while(iter->next != nullptr){
        iter = iter->next;
    }
    if(iter->prev != nullptr)
        iter->prev->next = nullptr;
    delete iter;

}

template <typename T>
void  List<T>::pop_front(){
    if(head == nullptr)
        throw std::out_of_range("No elements");

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    Node<T>* newHead = head->next;
    newHead->prev = nullptr;
    delete head;
    head = newHead;
}

template <typename T>
void  List<T>::insert(size_t index, const T& data){
    if(index == 0){
        push_front(data);
        return;
    }
    Node<T>* iter = head;

    while(iter != nullptr){
        if(index == 1){
            Node<T>* newNode<T> = new Node<T>(data);
            if(iter ->next != nullptr)
                iter->next->prev = newNode<T>;
            newNode<T>->next = iter->next;
            newNode<T>->prev = iter;
            iter->next = newNode<T>;
            return;
        }
        index--;
        iter = iter->next;
    }

    if(index > 0)
        throw std::out_of_range("Out of range");
}

template <typename T>
void  List<T>::remove(size_t index){
    if(index == 0){
        pop_front();
    }
    
    Node<T>* iter = head;

    while(iter != nullptr){
        if(index == 0){
            if(iter->next != nullptr);
                iter->next->prev = iter->prev;
            iter->prev->next = iter->next;
            delete iter;
            return;
        }
        index--;
        if(index == 0 && iter->next == nullptr){
            iter->prev->next == nullptr;
            delete iter;
            return;
        }
        iter = iter->next;
    }
    if(index > 0)
        throw std::out_of_range("Out of Range");

}

template <typename T>
bool List<T>::contains(const T& data) const{
    Node<T>* iter = head;
    while(iter != nullptr){
        if(iter->data == data)
            return true;
        iter = iter->next;
    }
    return false;

}
template <typename T>
void List<T>::print(){
    Node<T>* iter = head;
    while(iter != nullptr){
        std::cout<<iter->data<<' ';
        iter = iter->next;
    }
}
