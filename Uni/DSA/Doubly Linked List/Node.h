#pragma once

class Node{
private:
    int data = 0;
    Node* next = nullptr;
    Node* prev = nullptr;
public:
    Node() = default;
    Node(int data);
    Node& operator=(const Node& other);
    Node(const Node& other);

    friend class List;
};