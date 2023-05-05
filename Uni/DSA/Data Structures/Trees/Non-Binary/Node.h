#pragma once
#include <iostream>
#include "Const.h"

class Node{
private:
    int _data = 0;
    Node** _sons = nullptr;
    size_t _capacity = DEFAULT_CAP_NODE;
    size_t _size = 0;

public:
    Node() = default;
    Node(int data);
    Node(size_t cap, int data);
    Node(const Node& other);
    ~Node();
    Node& operator=(const Node& other);
    
    void add_son(int data);
    void remove_son(size_t index);
    
    int& data();
    size_t capacity();
    Node** sons();
    size_t size();
    
public:
    void free();
    void copyFrom(const Node& other);
    void resize(size_t size);
};

void swap(Node& lhs, Node& rhs);
