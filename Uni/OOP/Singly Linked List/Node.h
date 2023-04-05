#pragma once

struct Node{
private:

    int data;
    Node* next = nullptr;

public:
    Node(int data);
    Node(const Node& other);
    Node& operator=(const Node& other);


    friend class List;
};