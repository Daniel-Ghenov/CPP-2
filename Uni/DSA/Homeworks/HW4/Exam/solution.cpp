#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Node{
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(int data);
    Node(int data, Node* next);
    Node(int data, Node* prev, Node* next);
    Node(const Node& other);

};

Node::Node(int data){
    this->data = data;
}

Node::Node(const Node& other){
    this->data = other.data;
}

Node::Node(int data, Node* next){
    this->data = data;
    this-> next = next;
}

Node::Node(int data, Node* prev, Node* next){
    this->data = data;
    this->next = next;
    this->prev = prev;
}

class List{
private:
    Node* tail = nullptr;
    Node* mid = nullptr;
    bool isEven = false;
public:
    Node* head = nullptr;
    void gun();
    void add(int data);
    void milen();

private:

    void pop_back();
    void push_back(int data);

};



void List::gun() {
    pop_back();
}

void List::add(int data) {
    push_back(data);
}


void List::milen() {
    if(head == nullptr)
        return;
    if(head == tail){
        return;
    }

    Node* leftEnd = mid->prev;

    leftEnd->next = nullptr;
    Node* currHead = head;
    head = mid;
    if(isEven){
    mid = currHead;
    }else{
        mid = tail;
    }
    tail->next = currHead;
    currHead->prev = tail;
    tail = leftEnd;
}

void List::push_back(int data){
    if(tail == nullptr){
        mid = tail = head = new Node(data, nullptr, nullptr);
        return;
    }
    tail->next = new Node(data, tail, nullptr);
    tail = tail->next;

    if(!isEven){
        mid = mid->next;
    }
    isEven = !isEven;

}

void List::pop_back(){
    if(head == nullptr)
        return;

    if(head == tail){
        delete head;
        mid = head = tail = nullptr;
        return;
    }

    Node* last = tail;
    tail = tail->prev;
    tail->next = nullptr;

    delete last;

    if(isEven){
        mid = mid->prev;
    }
    isEven = !isEven;
}



int main() {

    int n;
    std::cin>>n;
    List list;
    for(int i = 0; i < n; i++){
        std::string s;
        std::cin>>s;
        if(s == "gun"){
         list.gun();
        }else if(s == "milen"){
            list.milen();
        }else {
            int num;
            std::cin>>num;
            list.add(num);
        }
    }
    int num = 0;
    for(auto it = list.head; it != nullptr; it = it->next){
        num++;
    }
    std::cout<<num<<std::endl;
    for(auto it = list.head; it != nullptr; it = it->next){
        std::cout<<it->data<<' ';
    }

    return 0;
}