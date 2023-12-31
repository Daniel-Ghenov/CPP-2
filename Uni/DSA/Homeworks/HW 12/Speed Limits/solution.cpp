#include <vector>
#include <iostream>
#include <algorithm>


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
    int from;
    int to;
    int speed;

    Edge(int from, int to, int speed): from(from), to(to), speed(speed) {}

    bool operator<(const Edge& other) const {
        return speed < other.speed;
    }
    bool operator>(const Edge& other) const {
        return speed > other.speed;
    }

};

std::pair<int, int> getMinMaxSpeed(std::vector<Edge>& edges, int vertices, int min) {
    DisjointSet set(vertices);
    int minSpeed = edges[min].speed;
    int maxSpeed = 0;
    int currUsed = 1;

    for (int i = min; i < edges.size(); ++i) {
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

int calculateDist(const std::pair<int, int>& pair) {
    return pair.second - pair.first;
}

std::pair<int, int> getMinMaxSpeed(std::vector<Edge>& edges, int vertices) {
    DisjointSet set(vertices);
    std::sort(edges.begin(), edges.end());
    std::pair<int, int> currMinDist = {edges.begin()->speed , edges.rbegin()->speed};

    for(int i = 0; i < edges.size() - vertices; i++) {
        auto newMinDist = getMinMaxSpeed(edges, vertices, i);
        if(calculateDist(newMinDist) < calculateDist(currMinDist)) {
            currMinDist = newMinDist;
        }
    }
    return currMinDist;
}


int main() {

    int n,m;
    std::cin>>n>>m;
    std::vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int a,b,s;
        std::cin>>a>>b>>s;
        a--;
        b--;
        edges.emplace_back(a,b,s);
    }

    auto [minSpeed, maxSpeed] = getMinMaxSpeed(edges, n);
    std::cout<<minSpeed<<' '<<maxSpeed;

    return 0;
}
