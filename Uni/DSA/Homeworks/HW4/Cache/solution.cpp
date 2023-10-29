#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Node{
    int key;
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(int key, int data);
    Node(int key, int data, Node* next);
    Node(int key, int data, Node* next, Node* prev);
    Node(const Node& other);
    Node& operator=(const Node& other);

};

Node::Node(int key, int data){
    this->key = key;
    this->data = data;
}

Node::Node(const Node& other){
    this->key = other.key;
    this->data = other.data;
}

Node::Node(int key, int data, Node* next){
    this->key = key;
    this->data = data;
    this-> next = next;
}

Node::Node(int key, int data, Node* next, Node* prev){
    this->key = key;
    this->data = data;
    this->next = next;
    this->prev = prev;
}

class List{
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int overHeatNum;
    int currOverHeat = 0;

public:

    void put(int key, int data);
    void get(int key);



private:

    void pop_back();
    void overheat();

    Node* find(int key);
};

void List::pop_back(){
    if(head == nullptr)
        throw std::out_of_range("No elements");

    if(head->next == nullptr){
        head = nullptr;
        return;
    }

    Node* ntlast = head;

    while(ntlast->next->next != nullptr){
        ntlast = ntlast->next;
    }
    delete ntlast->next;
    ntlast->next = nullptr;

}

void List::overheat() {
    pop_back();
}

Node* List::find(int key) {

    if(head == nullptr)
        throw std::out_of_range("No elements");

}


int main() {





    return 0;
}