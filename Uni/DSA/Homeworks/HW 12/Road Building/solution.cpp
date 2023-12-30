#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>


class DisjointSet {
private:
    std::vector<int> predecessors;
    std::vector<int> sizes;

public:

    DisjointSet(int size);

    void connect(int, int);

    bool connected(int, int);

private:
    int predecessor(int);
};


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

struct Edge {
    int index;
    int from;
    int to;
    int cost;
    int profit;

    Edge(int index, int from, int to, int cost, int profit) : index(index), from(from), to(to), cost(cost), profit(profit) {}

    bool operator>(const Edge& other) const{
        if(cost == other.cost) {
            if(profit == other.profit) {
                if(from == other.from) {
                    return to > other.to;
                }
                return from > other.from;
            }
            return profit > other.profit;
        }
        return cost > other.cost;
    }
};

std::vector<int> kruskal(const std::vector<Edge>& edges, int vertices) {
    DisjointSet set(vertices);
    std::priority_queue<Edge, std::vector<Edge>, std::greater<>> pq;
    for (Edge edge: edges) {
        pq.push(edge);
    }

    std::vector<int> indices;

    for (int i = 0; i < edges.size(); ++i) {
        Edge current = pq.top();
        pq.pop();
        if(set.connected(current.from, current.to)) {
            continue;
        }
        set.connect(current.from, current.to);
        indices.push_back(current.index);
    }
    return indices;
}


int main() {

    int n,m;
    std::cin>>n>>m;
    std::vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int a,b,c,p;
        std::cin>>a>>b>>c>>p;
        a--;
        b--;
        edges.emplace_back(i + 1,a,b,c,c * p);
    }

    std::vector<int> indices = kruskal(edges, n);
    std::sort(indices.begin(), indices.end());
    for (int index : indices) {
        std::cout<<index<<std::endl;
    }

    return 0;
}