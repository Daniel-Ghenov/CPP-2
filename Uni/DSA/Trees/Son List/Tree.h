#pragma once
#include "Vertex.h"

class Tree{
private:
    Vertex* root = nullptr;

public:
    Tree();
    ~Tree();

private:
    void free();

};
