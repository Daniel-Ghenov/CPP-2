#include <vector>
#include <iostream>
#include <algorithm>
#include "DisjointSet.h"


typedef std::pair<long long, long long> lPair;

const long long INF = 1e18;
const long long NEG_INF = -1e18;

struct Edge {
    long long from;
    long long to;
    long long speed;

    Edge(long long from, long long to, long long speed): from(from), to(to), speed(speed) {}

    bool operator<(const Edge& other) const {
        return speed < other.speed;
    }
};

lPair getMinMaxSpeed(std::vector<Edge>& edges, long long vertices, long long min) {
    DisjointSet set(vertices);
    long long minSpeed = edges[min].speed;
    long long maxSpeed = 0;
    long long currUsed = 1;

    for (long long i = min; i < edges.size(); ++i) {
        Edge current = edges[i];

        if(set.connected(current.from, current.to)) {
            continue;
        }
        set.connect(current.from, current.to);
        currUsed++;
        if(currUsed == vertices) {
            maxSpeed = current.speed;
            break;
        }
    }
    if(currUsed < vertices) {
        return {NEG_INF, INF};
    }
    return {minSpeed, maxSpeed};
}

long long calculateDist(const lPair& pair) {
    return pair.second - pair.first;
}

lPair getMinMaxSpeed(std::vector<Edge>& edges, long long vertices) {
    std::sort(edges.begin(), edges.end());
    lPair currMinDist = {edges.begin()->speed , edges.rbegin()->speed};

    for(long long i = 0; i < edges.size() - vertices + 1; i++) {
        lPair newMinDist = getMinMaxSpeed(edges, vertices, i);
        if(calculateDist(newMinDist) < calculateDist(currMinDist)) {
            currMinDist = newMinDist;
        }
    }
    return currMinDist;
}


int main() {

    long long n,m;
    std::cin>>n>>m;
    std::vector<Edge> edges;
    for (long long i = 0; i < m; ++i) {
        long long a,b,s;
        std::cin>>a>>b>>s;
        a--;
        b--;
        edges.emplace_back(a,b,s);
    }

    auto [minSpeed, maxSpeed] = getMinMaxSpeed(edges, n);
    std::cout<<minSpeed<<' '<<maxSpeed;

    return 0;
}
