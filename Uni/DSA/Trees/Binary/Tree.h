#pragma once
#include "Node.h"

class Tree{
private:
    Node* root = nullptr;
public:
    Tree() = default;
    Tree(const Tree& other);
    Tree& operator=(const Tree& other);
    ~Tree();

    void add(int data);
    void remove(int data);
    bool contains(int data) const;
    void print() const;

private:

    void free();
    void copyFrom(const Tree& other);

    Node* _add(int data, Node* current);
    void _remove(int data, Node* current);
    bool _contains(int data, Node* current) const;
    void _print(Node* current) const;
};
