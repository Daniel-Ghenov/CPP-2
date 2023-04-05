#pragma once
#include <iostream>
#include "Node.h"

class List{
private:
    Node* head = nullptr;

    void free();
    void copyFrom(const List& other);

public:
    List() = default;
    List(int data);
    ~List();
    List& operator=(const List& other);
    List(const List& other);

    void push_back(int data);
    void add(int data);
    void pop_back();

    void print() const;


    Node* tail();
};