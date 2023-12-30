#include <stdexcept>
#include "DisjointSet.h"

DisjointSet::DisjointSet(int size): predecessors(size), sizes(std::vector<int>(size, 0)) {
    for (int i = 0; i < size; ++i) {
        predecessors[i] = i;
    }
}

void DisjointSet::connect(int a, int b) {
    if(a == b) {
        return;
    }

    if(a < 0 || b < 0 || a >= predecessors.size() || b >= predecessors.size()) {
        throw std::out_of_range("Index out of range");
    }

    int aPredecessor = predecessor(a);
    int bPredecessor = predecessor(b);

    if(sizes[aPredecessor] > sizes[bPredecessor]) {
        std::swap(aPredecessor, bPredecessor);
    }

    predecessors[aPredecessor] = predecessors[bPredecessor];
    if(sizes[aPredecessor] == sizes[bPredecessor]) {
        sizes[aPredecessor]++;
    }
}

bool DisjointSet::connected(int a, int b) {
    if(a == b) {
        return true;
    }

    if(a < 0 || b < 0 || a >= predecessors.size() || b >= predecessors.size()) {
        throw std::out_of_range("Index out of range");
    }

    return predecessor(a) == predecessor(b);
}

int DisjointSet::predecessor(int a) {
    if(predecessors[a] == a) {
        return a;
    }
    int predecess = predecessor(predecessors[a]);
    predecessors[a] = predecess;
    return predecess;
}
