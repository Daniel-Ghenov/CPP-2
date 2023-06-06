#pragma once
#include <iostream>
#include "Node\Node.hpp"
#include "Iterators\BiDirectIter.hpp"

template <typename T>
class List{
private:
    Node<T>* sentinel;

public:


    List();
    ~List();
    List& operator=(const List<T>& other);
    List(const List<T>& other);

    void push_back(const T& data);
    void push_front(const T& data);
    void push_back(T&& data);
    void push_front(T&& data);
    void pop_back();
    void pop_front();
    void insert(size_t index, const T& data);   //need to implement with iterators
    void remove(size_t index);
    bool contains(const T& data) const;

    void print();

private:

    void free();
    void copyFrom(const List<T>& other);
    void move(List<T>&& other);
};

template <typename T>
List<T>::List(){
    sentinel = new Node<T>();
    sentinel->next = sentinel->prev = sentinel;
}



template <typename T>
List<T>::~List(){
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
List<T>::List(const List<T>& other){
    copyFrom(other);

}

template <typename T>
void  List<T>::push_front(const T& data){
    sentinel->next = new Node<T>(data, sentinel ,sentinel->next);
    if(sentinel->next->next == sentinel)
        sentinel->prev = sentinel->next;

}

template <typename T>
void  List<T>::push_back(const T& data){
    sentinel->prev = new Node<T>(data, sentinel->prev, sentinel);
    if(sentinel->prev->prev == sentinel)
        sentinel->next = sentinel->prev;
}

template <typename T>
void  List<T>::push_front(T&& data){
    sentinel->next = new Node<T>(std::move(data), sentinel ,sentinel->next);
    if(sentinel->next->next == sentinel)
        sentinel->prev = sentinel->next;

}

template <typename T>
void  List<T>::push_back(T&& data){
    sentinel->prev = new Node<T>(std::move(data), sentinel->prev, sentinel);
    if(sentinel->prev->prev == sentinel)
        sentinel->next = sentinel->prev;
}

template <typename T>
void  List<T>::pop_back(){

    if(sentinel->prev == sentinel)
        throw std::out_of_range("List is empty");
        
    sentinel->prev = sentinel->prev->prev;
    delete sentinel->prev->next;
    sentinel->prev->next = sentinel;

}

template <typename T>
void  List<T>::pop_front(){
    if(sentinel->next == sentinel)
        throw std::out_of_range("List is empty");

    sentinel->next = sentinel->next->next;
    delete sentinel->next->prev;
    sentinel->next->prev = sentinel;
}


template <typename T>
bool List<T>::contains(const T& data) const{
    Node<T>* iter = sentinel->next;
    while(iter != sentinel){
        if(iter->data == data)
            return true;
        iter = iter->next;
    }
    return false;

}
template <typename T>
void List<T>::print(){
    Node<T>* iter = sentinel->next;
    while(iter != sentinel){
        std::cout<<iter->data<<' ';
        iter = iter->next;
    }
}


template <typename T>
void List<T>::free(){
    Node<T>* iter = sentinel->next;
    while(iter != sentinel){
        iter = iter->next;
        delete iter->prev;
    }
    delete iter->prev;
    sentinel->next = sentinel->prev = sentinel;
    
}

template <typename T>
void List<T>::copyFrom(const List<T>& other){
    Node<T>* otherIter = other.sentinel->next;
    Node<T>* thisIter = sentinel;

    while(otherIter != sentinel){
        thisIter->next = new Node(otherIter->data, thisIter, sentinel);
        thisIter = thisIter->next;
        otherIter = otherIter->next;
    }
    
    sentinel->prev = thisIter;
}

template <typename T>
void List<T>::move(List<T>&& other){

    sentinel = other.sentinel;
    other.sentinel->next = other.sentinel->prev = other.sentinel;
}
