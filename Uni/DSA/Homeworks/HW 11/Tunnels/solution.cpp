#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

const long long INF = LONG_LONG_MAX;

struct Edge {
    int weight;
    int to;
    int kgs;

    Edge(int weight, int to, int kgs) : weight(weight), to(to), kgs(kgs) {}

    bool operator<(const Edge& other) const {
        if(weight == other.weight) {
            if(to == other.to) {
                return kgs < other.kgs;
            }
            return to < other.to;
        }
        return weight < other.weight;
    }

    bool operator==(const Edge& other) const {
        return weight == other.weight && to == other.to && kgs == other.kgs;
    }

};

int minKgsToReach(const std::vector<std::vector<Edge>>& graph, int battery) {

}

int main() {

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<Edge>> graph(n);

    for(int i = 0; i < m; i++) {
        int from, to, weight, kgs;
        std::cin >> from >> to >> kgs >> weight;
        graph[from - 1].emplace_back(weight, to - 1, kgs);
    }

    return 0;
}
