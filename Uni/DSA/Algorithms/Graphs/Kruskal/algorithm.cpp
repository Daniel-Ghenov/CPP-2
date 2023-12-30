#include <queue>
#include "Dependencies/DisjointSet.h"
#include "Dependencies/Edge.h"


int kruskal(const std::vector<Edge>& edges, int vertices) {
    DisjointSet set(vertices);
    std::priority_queue<Edge, std::vector<Edge>, std::less<>> pq;
    for (Edge edge: edges) {
        pq.push(edge);
    }

    int totalCost;

    for (int i = 0; i < edges.size(); ++i) {
        Edge current = pq.top();
        pq.pop();
        if(set.connected(current.from, current.to)) {
            continue;
        }
        set.connect(current.from, current.to);
        totalCost += current.weight;
    }
    return totalCost;
}
