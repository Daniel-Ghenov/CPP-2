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
    if(head == nullptr){
        push_front(data);
    }
    Node* last = head;
    while(last->next != nullptr){
        last = last->next;
    }
    last->next = new Node(data);

}
void List::push_front(int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
void List::pop_back(){
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
void List::pop_front(){
    if(head == nullptr)
        throw std::out_of_range("No elements");

    Node* newHead = head->next;

    delete[] head;
    head = newHead;
}

void List::remove(size_t index){
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
bool List::containts(int data){
    Node* iter = head;

    while(iter != nullptr){
        if(iter->data == data)
            return true;
        iter = iter->next;
    }
    return false;
}

void List::insert(size_t index, int data){
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




void List::print() const {
    Node* iter = head;
    while(iter != nullptr){
        std::cout<<iter->data<<' ';
        iter = iter->next;
    }
}

int List::find(int data) const{
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

void List::swap(size_t idx1, size_t idx2){

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
