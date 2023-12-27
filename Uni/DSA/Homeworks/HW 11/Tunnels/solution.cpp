#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <set>

const long long INF = LONG_LONG_MAX;

struct Edge {
    long long to;
    long long weight;
    long long kgs;

    Edge(long long to, long long weight, long long kgs) : to(to), weight(weight), kgs(kgs) {}

    bool operator<(const Edge& other) const {
        if(kgs == other.kgs) {
            if(weight == other.weight) {
                return to < other.to;
            }
            return weight < other.weight;
        }
        return kgs < other.kgs;
    }

};

long long minKgsToReach(const std::vector<std::vector<Edge>>& graph, long long battery) {

    std::set<Edge> edges;
//    std::vector<long long> dist(graph.size(), INF);
//    dist[0] = 0;
    edges.emplace(0, 0, 0);

    while(!edges.empty()) {
        Edge temp = *(edges.begin());
        edges.erase(edges.begin());
        long long to = temp.to;

        if(to == graph.size()  - 1) {
            return temp.kgs;
        }

        for(long long i = 0; i < graph[to].size(); i++) {
            long long weight = graph[to][i].weight;
            long long next = graph[to][i].to;

            long long newArrivalTime = temp.weight + weight;
            long long newKgs = std::max(temp.kgs, graph[to][i].kgs);
            if(newArrivalTime < battery) {

                edges.emplace(next, newArrivalTime, newKgs);
            }
        }
    }
    return -1;
}

int main() {

    long long n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<Edge>> graph(n);

    for(long long i = 0; i < m; i++) {
        long long from, to, weight, kgs;
        std::cin >> from >> to >> kgs >> weight;
        graph[from - 1].emplace_back(to - 1, weight, kgs);
    }

    std::cout<<minKgsToReach(graph, k);

    return 0;
}
