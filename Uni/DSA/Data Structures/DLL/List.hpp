#pragma once
#include <iostream>
#include "Node\Node.hpp"

template <typename T>
class List{
public:
    class Iterator;
    class CIterator;
    class RIterator;
    class CRIterator;

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
    void insert(List<T>::Iterator& it, const T& data);
    void insert(List<T>::Iterator& it, T&& data);
    void remove(List<T>::Iterator& it);
    bool contains(const T& data) const;

    List<T>::Iterator end();
    List<T>::Iterator begin();
    List<T>::CIterator cend() const;
    List<T>::CIterator cbegin() const;
    List<T>::RIterator rend();
    List<T>::RIterator rbegin();
    List<T>::CRIterator crend() const;
    List<T>::CRIterator crbegin() const;
    

private:

    void free();
    void copyFrom(const List<T>& other);
    void move(List<T>&& other);

public:

    class Iterator{
    private:
        Node<T>* ptr = nullptr;
    public:

        Iterator() = default;
        Iterator(Node<T>* ptr);
        
        virtual Node<T>& operator*();
        virtual Node<T>* operator->();
        virtual const Node<T>& operator*() const;
        virtual const Node<T>* operator->() const;

        virtual Iterator& operator++();
        virtual Iterator operator++(int a);
        virtual Iterator& operator--();
        virtual Iterator operator--(int a);

        virtual bool operator!=(Iterator& other);
        virtual bool operator!=(List<T>::CIterator& other);

    };

    class CIterator : public List<T>::Iterator{
    public:
        CIterator() = default;
        CIterator(Node<T>* ptr);

        Node<T>& operator*() = delete;
        Node<T>* operator->() = delete;
    }
    class RIterator: public List<T>::Iterator{
    private:
        Node<T>* ptr = nullptr;
    public:

        RIterator() = default;
        RIterator(Node<T>* ptr);

        RIterator& operator++();
        RIterator operator++(int a);
        RIterator& operator--();
        RIterator operator--(int a);


    };
    class CRIterator: public List<T>::RIterator{
    public:
        CRIterator() = default;
        CRIterator(Node<T>* ptr);

        Node<T>& operator*() = delete;
        Node<T>* operator->() = delete;
    };

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
void insert(List<T>::Iterator& it, const T& data){

    it->
    
}
template <typename T>
void insert(List<T>::Iterator& it, T&& data){
    
}
template <typename T>
void remove(List<T>::Iterator& it){
    
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

template <typename T>
List<T>::Iterator List<T>::end(){
    return List<T>::Iterator(sentinel);   
}
template <typename T>
List<T>::Iterator List<T>::begin(){
    return List<T>::Iterator(sentinel->next);   
}
template <typename T>
List<T>::CIterator List<T>::cend() const{
    return List<T>::CIterator(sentinel);   
    
}
template <typename T>
List<T>::CIterator List<T>::cbegin() const{
    return List<T>::CIterator(sentinel->next);   
}
template <typename T>
List<T>::RIterator List<T>::rend(){
    return List<T>::RIterator(sentinel);   
    
}
template <typename T>
List<T>::RIterator List<T>::rbegin(){
    return List<T>::RIterator(sentinel->prev);   
}
template <typename T>
List<T>::CRIterator List<T>::crend() const{
    
    return List<T>::CRIterator(sentinel);   
}
template <typename T>
List<T>::CRIterator List<T>::crbegin() const{
    return List<T>::CRIterator(sentinel->prev);   
    
}

//Iterators

template <typename T>
List<T>::Iterator::Iterator(Node<T>* ptr){
    this->ptr = ptr;
}

template <typename T>
Node<T>& List<T>::Iterator::operator*(){
    return *ptr;
}
template <typename T>
const Node<T>& List<T>::Iterator::operator*() const{
    return *ptr;
}
template <typename T>
Node<T>* List<T>::Iterator::operator->(){
    return ptr;
}
template <typename T>
const Node<T>* List<T>::Iterator::operator->() const{
    return ptr;
}

template <typename T>
List<T>::Iterator& List<T>::Iterator::operator++(){
    return (ptr = ptr->next);

}
template <typename T>
List<T>::Iterator List<T>::Iterator::operator++(int a){
    ptr = ptr->next;
    return ptr->prev;
}
template <typename T>
List<T>::Iterator& List<T>::Iterator::operator--(){
    return (ptr = ptr->prev);
    
}
template <typename T>
List<T>::Iterator List<T>::Iterator::operator--(int a){
    ptr = ptr->prev;
    return ptr->next;
}

template <typename T>
bool List<T>::Iterator::operator!=(Iterator& other){
    return ptr != other.ptr;
}
template <typename T>
bool List<T>::Iterator::operator!=(List<T>::CIterator& other){   
    return ptr != other.ptr;
}

template <typename T>
List<T>::CIterator::CIterator(Node<T>* ptr): Iterator(ptr) {}


//Reverse Iterator


template <typename T>
List<T>::RIterator::RIterator(Node<T>* ptr): Iterator(ptr){}

template <typename T>
List<T>::RIterator& List<T>::RIterator::operator++(){
    return (ptr = ptr->prev);

}
template <typename T>
List<T>::RIterator List<T>::RIterator::operator++(int a){
    ptr = ptr->prev;
    return ptr->next;
}
template <typename T>
List<T>::RIterator& List<T>::RIterator::operator--(){
    return (ptr = ptr->next);
    
}
template <typename T>
List<T>::RIterator List<T>::RIterator::operator--(int a){
    ptr = ptr->next;
    return ptr->prev;
}

template <typename T>
List<T>::CRIterator::CRIterator(Node<T>* ptr): RIterator(ptr){}
