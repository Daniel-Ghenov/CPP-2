#include "List.h"

void List::free(){
    Node* iter = head->next;
    while(iter != nullptr){
        delete[] head;
        head = iter;
        iter = iter->next;
    }
    head->data = 0;
}
void List::copyFrom(const List& other){
    Node* otherIter = other.head->next;
    head = new Node(other.head->data);
    Node* thisIter = head;

    while(otherIter != nullptr){
        thisIter->next = new Node(otherIter->data);
        thisIter = thisIter->next;
        otherIter = otherIter->next;
    }
}




List::List(int data){
    Node* newHead = new Node(data);
    head = newHead;
}
List::~List(){
    free();
}

List& List::operator=(const List& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}
List::List(const List& other){
    copyFrom(other);
}

void List::push_back(int data){
    Node* last = head;
    while(last->next != nullptr){
        last = last->next;
    }
    last->next = new Node(data);

}
void List::add(int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
void List::print() const {
    Node* iter = head;
    while(iter != nullptr){
        std::cout<<iter->data<<' ';
        iter = iter->next;
    }
}
void List::pop_back(){
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

