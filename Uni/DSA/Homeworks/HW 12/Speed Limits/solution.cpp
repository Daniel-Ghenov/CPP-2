#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>


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

    if(sizes[aPredecessor] < sizes[bPredecessor]) {
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
    long long from;
    long long to;
    long long speed;

    Edge(long long from, long long to, long long speed): from(from), to(to), speed(speed) {}

    bool operator<(const Edge& other) const {
        return speed < other.speed;
    }
    bool operator>(const Edge& other) const {
        return speed > other.speed;
    }

};

std::pair<long long, long long> getMinMaxSpeed(std::vector<Edge>& edges, long long vertices, long long min) {
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
    return {minSpeed, maxSpeed};
}

long long calculateDist(const std::pair<long long, long long>& pair) {
    return pair.second - pair.first;
}

std::pair<long long, long long> getMinMaxSpeed(std::vector<Edge>& edges, long long vertices) {
    DisjointSet set(vertices);
    std::sort(edges.begin(), edges.end());
    std::pair<long long, long long> currMinDist = {edges.begin()->speed , edges.rbegin()->speed};

    for(long long i = 0; i < edges.size() - vertices; i++) {
        auto newMinDist = getMinMaxSpeed(edges, vertices, i);
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
