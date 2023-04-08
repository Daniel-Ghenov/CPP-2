#pragma once

class Node{
private:
    int data = 0;
    Node* left = nullptr;
    Node* right = nullptr;

public:
    Node() = default;
    Node(const Node& other);
    Node& operator=(const Node& other);
    ~Node();
    Node(int data);


private:
    void free();
    void copyFrom(const Node& other);

    friend class Tree;
};