#pragma once
#include "Node.h"

class Tree{
private:
    Node* root = nullptr;

public:
    Tree() = default;
    ~Tree();
    Tree(const Tree& other);
    Tree(int data);
    Tree operator=(const Tree& other);


private:
    void free();
    void copyFrom(const Tree& other);
    Node& getNode(size_t index);
    Node& _getNode(size_t index, size_t current);
};
