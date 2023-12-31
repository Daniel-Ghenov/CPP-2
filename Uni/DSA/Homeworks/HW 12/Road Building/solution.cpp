#include <vector>
#include <iostream>
#include <algorithm>
#include "DisjointSet.h"

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