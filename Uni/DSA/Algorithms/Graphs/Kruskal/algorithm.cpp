#include <algorithm>
#include "Dependencies/DisjointSet.h"
#include "Dependencies/Edge.h"


std::vector<long long> kruskal(std::vector<Edge>& edges, int vertices) {
    DisjointSet set(vertices);
    std::sort(edges.begin(), edges.end());
    std::vector<long long> indices;

    for (Edge current : edges) {
        if(indices.size() + 1 == vertices) {
            break;
        }
        if(set.connected(current.from, current.to)) {
            continue;
        }
        set.connect(current.from, current.to);
        indices.push_back(current.index);
    }
    return indices;
}
