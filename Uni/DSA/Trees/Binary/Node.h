#pragma once

class Node{
private:
    int _data = 0;
    Node* _left = nullptr;
    Node* _right = nullptr;

public:
    Node() = default;
    Node(int data);
    Node(const Node& other);
    ~Node();
    Node& operator=(const Node& other);


private:
    void copyFrom(const Node& other);
};