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
    Node* nodes[10000];
    int capacity;
    int currCap = 0;
public:

    List(int overHeatNum, int capacity): overHeatNum(overHeatNum), capacity(capacity) {
        for(int i = 0; i < 10000; i++){
            nodes[i] = nullptr;
        }
    }

    void put(int key, int data);
    int get(int key);



private:

    void push_front(int key, int data);
    void pop_back();
    void remove(Node* node);
    void overheat();
    void checkOverHeat();
    void checkCapacity();

};

void List::put(int key, int data) {
    bool checkCap = false;
    if(!nodes[key]){
        checkCap = true;
    }else{
        remove(nodes[key]);
    }

    push_front(key, data);
    nodes[key] = head;

    if(checkCap){
        currCap++;
        checkCapacity();
    }

    currOverHeat++;
    checkOverHeat();

}

int List::get(int key) {
    if(!nodes[key]){
        currOverHeat++;
        return -1;
    }
    int data = nodes[key]->data;
    remove(nodes[key]);
    push_front(key, data);
    nodes[key] = head;
    currOverHeat++;
    checkOverHeat();
    return data;
}

void List::push_front(int key, int data){
    head = new Node(key, data, head, nullptr);
    if(tail == nullptr){
        tail = head;
    }
    if(head->next)
        head->next->prev = head;
}

void List::pop_back(){
    if(head == nullptr)
        throw std::out_of_range("No elements");

    if(head == tail){
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* last = tail;
    tail = tail->prev;
    tail->next = nullptr;

    int key = last->key;
    nodes[key] = nullptr;
    delete last;
}

void List::remove(Node* node){

    if(node == head){
        head = node->next;
        if(head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        delete node;
        return;
    }
    if(node == tail){
        tail = node->prev;
        tail->next = nullptr;
        delete node;
        return;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;

}


void List::overheat() {
    pop_back();
}

void List::checkOverHeat(){
    if(currOverHeat == overHeatNum){
        overheat();
        currOverHeat = 0;
        currCap--;
    }
}

void List::checkCapacity() {
    if(currCap > capacity){
        overheat();
        currCap = capacity;
    }
}

int main() {

    int cap, queries, overheat;
    std::cin>>cap>>queries>>overheat;
    List list(overheat, cap);
    for(int i = 0; i < queries; i++){
        std::string query;
        std::cin>>query;
        if(query == "put"){
            int key, data;
            std::cin>>key>>data;
            list.put(key, data);
        }else{
            int key;
            std::cin>>key;
            std::cout<<list.get(key)<<std::endl;
        }
    }


    return 0;
}