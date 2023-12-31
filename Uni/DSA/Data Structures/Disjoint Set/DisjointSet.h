#pragma once
#include <vector>

class DisjointSet {
private:
    std::vector<int> predecessors;
    std::vector<int> sizes;

public:

    explicit DisjointSet(int size);

    void connect(int, int);

    bool connected(int, int);

private:
    int predecessor(int);
};


