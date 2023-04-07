#pragma once
#include <iostream>
#include "Node.h"


class List{
private:
    Node* head = nullptr;

    void free();
    void copyFrom(const List& other);

public:
    List();
    List(int data);
    ~List();
    List& operator=(const List& other);
    List(const List& other);

    void push_back(int data);
    void push_front(int data);
    void pop_back();
    void pop_front();
    void insert(size_t index, int data);
    void remove(size_t index);
    bool contains(int data);

    void print();

};