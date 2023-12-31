#include <vector>
#include <iostream>
#include <algorithm>


class DisjointSet {
private:
    std::vector<long long> predecessors;
    std::vector<long long> sizes;

public:

    DisjointSet(long long size);

    void connect(long long, long long);

    bool connected(long long, long long);

private:
    long long predecessor(long long);
};


DisjointSet::DisjointSet(long long size): predecessors(size), sizes(std::vector<long long>(size, 0)) {
    for (long long i = 0; i < size; ++i) {
        predecessors[i] = i;
    }
}

void DisjointSet::connect(long long a, long long b) {
    if(a == b) {
        return;
    }

    if(a < 0 || b < 0 || a >= predecessors.size() || b >= predecessors.size()) {
        throw std::out_of_range("Index out of range");
    }

    long long aPredecessor = predecessor(a);
    long long bPredecessor = predecessor(b);

    if(sizes[aPredecessor] > sizes[bPredecessor]) {
        std::swap(aPredecessor, bPredecessor);
    }

    predecessors[aPredecessor] = predecessors[bPredecessor];
    if(sizes[aPredecessor] == sizes[bPredecessor]) {
        sizes[aPredecessor]++;
    }
}

bool DisjointSet::connected(long long a, long long b) {
    if(a == b) {
        return true;
    }

    if(a < 0 || b < 0 || a >= predecessors.size() || b >= predecessors.size()) {
        throw std::out_of_range("Index out of range");
    }

    return predecessor(a) == predecessor(b);
}

long long DisjointSet::predecessor(long long a) {
    if(predecessors[a] == a) {
        return a;
    }
    long long predecess = predecessor(predecessors[a]);
    predecessors[a] = predecess;
    return predecess;
}

struct Edge {
    long long index;
    long long from;
    long long to;
    long long cost;
    long long profit;

    Edge(long long index, long long from, long long to, long long cost, long long profit) : index(index), from(from), to(to), cost(cost), profit(profit) {}

    bool operator<(const Edge& other) const{
        if(cost == other.cost) {
            if(profit == other.profit) {
                if(from == other.from) {
                    return to < other.to;
                }
                return from < other.from;
            }
            return profit > other.profit;
        }
        return cost < other.cost;
    }
};

std::vector<long long> kruskal(std::vector<Edge>& edges, long long vertices) {
    DisjointSet set(vertices);
    std::sort(edges.begin(), edges.end());
    std::vector<long long> indices;

    for (Edge current : edges) {
        if(indices.size() + 1 == vertices) {
            break;
        }
        if(!set.connected(current.from, current.to)) {
            set.connect(current.from, current.to);
            indices.push_back(current.index);
        }
    }
    return indices;
}


int main() {

    long long n,m;
    std::cin>>n>>m;
    std::vector<Edge> edges;
    for (long long i = 0; i < m; ++i) {
        long long a,b,c,p;
        std::cin>>a>>b>>c>>p;
        a--;
        b--;
        edges.emplace_back(i + 1,a,b,c,p);
    }

    std::vector<long long> indices = kruskal(edges, n);
    for (long long index : indices) {
        std::cout<<index<<std::endl;
    }

    return 0;
}