#include "List.h"

void List::free(){
    Node* iter = head;
    while(iter->next != nullptr){
        iter = iter->next;
        delete iter->prev;
        iter->prev = nullptr;
    }
    delete iter;
    head = nullptr;
    
}
void List::copyFrom(const List& other){
    head = new Node(*(other.head));
    Node* otherIter = other.head;
    Node* thisIter = head;
    while(otherIter->next != nullptr){
        thisIter->next = new Node(*(otherIter->next));
        thisIter->next->prev = thisIter;
        thisIter = thisIter->next;
        otherIter = otherIter->next;
    }
    
}

List::List(){
    head = nullptr;

}
List::List(int data){
    head = new Node(data);
    head->next = head->prev = nullptr;
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

void  List::push_back(int data){
    if(head == nullptr){
        push_front(data);
    }
    Node* iter = head;
    while(iter->next != nullptr){
        iter = iter->next;
    }
    iter->next = new Node(data);
    iter->next->prev = iter;

}

void  List::push_front(int data){
    Node* newHead = new Node(data);
    newHead->next = head;
    head = newHead;

}

void  List::pop_back(){
    if(head == nullptr){
        throw std::out_of_range("No elements");
    }

    Node* iter = head;
    while(iter->next != nullptr){
        iter = iter->next;
    }
    if(iter->prev != nullptr)
        iter->prev->next = nullptr;
    delete iter;

}

void  List::pop_front(){
    if(head == nullptr)
        throw std::out_of_range("No elements");

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    Node* newHead = head->next;
    newHead->prev = nullptr;
    delete head;
    head = newHead;
}

void  List::insert(size_t index, int data){
    if(index == 0){
        push_front(data);
        return;
    }
    Node* iter = head;

    while(iter != nullptr){
        if(index == 1){
            Node* newNode = new Node(data);
            if(iter ->next != nullptr)
                iter->next->prev = newNode;
            newNode->next = iter->next;
            newNode->prev = iter;
            iter->next = newNode;
            return;
        }
        index--;
        iter = iter->next;
    }

    if(index > 0)
        throw std::out_of_range("Out of range");
}

void  List::remove(size_t index){
    if(index == 0){
        pop_front();
    }
    
    Node* iter = head;

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

bool List::contains(int data){
    Node* iter = head;
    while(iter != nullptr){
        if(iter->data == data)
            return true;
        iter = iter->next;
    }
    return false;

}
void List::print(){
    Node* iter = head;
    while(iter != nullptr){
        std::cout<<iter->data<<' ';
        iter = iter->next;
    }
}
