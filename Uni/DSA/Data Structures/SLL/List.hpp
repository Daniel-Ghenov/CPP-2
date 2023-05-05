#pragma once
#include <iostream>
#include "SLL\Node\Node.hpp"

template <typename T>
class List{
private:
    Node* head = nullptr;

    void free();
    void copyFrom(const List<T>& other);

public:
    List() = default;
    List(const T& data);
    ~List();
    List<T>& operator=(const List<T>& other);
    List(const List<T>& other);

    void push_back(const T& data);
    void push_front(const T& data);
    void pop_back();
    void pop_front();
    void remove(size_t index);
    void insert(size_t index, const T& data);
    bool contains(const T& data);

    void print() const;

    const T& find(const T& data) const;
    void swap(size_t idx1, size_t idx2);


    Node* tail();
};

template <typename T>
void List<T>::free(){
    Node* iter = head->next;
    while(iter != nullptr){
        delete[] head;
        head = iter;
        iter = iter->next;
    }
    head->data = 0;
}
template <typename T>
void List<T>::copyFrom(const List<T>& other){
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
List<T>::List(const T& data){
    Node* newHead = new Node(data);
    head = newHead;
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
void List<T>::push_back(const T& data){
    if(head == nullptr){
        push_front(data);
    }
    Node* last = head;
    while(last->next != nullptr){
        last = last->next;
    }
    last->next = new Node(data);

}
template <typename T>
void List<T>::push_front(const T& data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
template <typename T>
void List<T>::pop_back(){
    if(head == nullptr)
        throw std::out_of_range("No elements");

    if(head->next == nullptr){
        head->data = 0;
        return;
    }
    Node* ntlast = head;

    while(ntlast->next->next != nullptr){
        ntlast = ntlast->next;
    }
    delete ntlast->next;
    ntlast->next = nullptr;

}
template <typename T>
void List<T>::pop_front(){
    if(head == nullptr)
        throw std::out_of_range("No elements");

    Node* newHead = head->next;

    delete[] head;
    head = newHead;
}

template <typename T>
void List<T>::remove(size_t index){
    if(index == 0)
        pop_front();


    Node* iter = head;
    while(iter->next != nullptr){    
        if(index == 1){
            Node* goTo = iter->next->next;
            delete[] iter->next;
            iter->next = goTo;
            return;
        }
        index--;
        iter = iter->next;
    }
    
    if(index == 1){
        delete[] iter->next;
        iter->next = nullptr;
    }
    else
        throw std::out_of_range("Out of Range");

}
template <typename T>
bool List<T>::contains(const T& data){
    Node* iter = head;

    while(iter != nullptr){
        if(iter->data == data)
            return true;
        iter = iter->next;
    }
    return false;
}

template <typename T>
void List<T>::insert(size_t index, const T& data){
    if(index == 0){
        push_front(data);
        return;
    }

    Node* iter = head;
    while(iter != nullptr){    
        if(index == 1){
            Node* newData = new Node(data);
            newData->next = iter->next;
            iter->next = newData;
            return;
        }
        index--;
        if(index == 1 && iter->next == nullptr){
            iter->next = new Node(data);
            return;
        }
        iter = iter->next;
    }
    if(index > 0){
        throw std::out_of_range("Out of Range");
    }
}




template <typename T>
void List<T>::print() const {
    Node* iter = head;
    while(iter != nullptr){
        std::cout<<iter->data<<' ';
        iter = iter->next;
    }
}

template <typename T>
const T& List<T>::find(const T& data) const{
    size_t index = 0;
    Node*iter = head;
    while(iter != nullptr){
        if(iter->data == data){
            return index;
        }
        index++;
        iter = iter->next;
    }
    return -1;

}

template <typename T>
void List<T>::swap(size_t idx1, size_t idx2){

    Node* iter1 = head;
    Node* iter2;

    if(idx1 > idx2){
        swap(idx1, idx2);
    }

    while(idx1--){
        iter1 = iter1->next;
    }
    iter2 = iter1;
    idx2 -= idx1;
    while(idx2--){
        iter2 = iter2->next;
    }
    swap(iter1->data, iter2->data);



}