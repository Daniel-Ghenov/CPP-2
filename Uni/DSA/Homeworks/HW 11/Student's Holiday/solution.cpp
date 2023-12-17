#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>

const long long INF = LONG_LONG_MAX;
const int MAX_STOPS = 10000;
long long intervals[MAX_STOPS];

struct Edge {
    long long weight;
    long long to;

    Edge(long long weight, long long to) : weight(weight), to(to) {}

    bool operator<(const Edge& other) const {
        if(weight == other.weight) {
            return to < other.to;
        }
        return weight < other.weight;
    }

    bool operator==(const Edge& other) const {
        return weight == other.weight && to == other.to;
    }

};

long long getBusWaitTime(long long currentTime, long long interval) {
    return interval * ceil((double) currentTime / (double) interval) - currentTime;
}

long long timeToArriveTo(const std::vector<std::vector<Edge>>& graph, long long start, long long end) {

    std::set<Edge> edges;
    std::vector<long long> dist(graph.size(), INF);
    dist[start] = 0;
    edges.emplace(0, start);

    while(!edges.empty()) {
        Edge temp = *(edges.begin());
        edges.erase(edges.begin());
        long long to = temp.to;

        if(to == end) {
            return temp.weight + getBusWaitTime(temp.weight, intervals[to]);
        }

        for(long long i = 0; i < graph[to].size(); i++) {
            long long weight = graph[to][i].weight;
            long long next = graph[to][i].to;

            long long newArrivalTime = dist[to] + getBusWaitTime(dist[to], intervals[to]) + weight;

            if(newArrivalTime < dist[next]) {


                if(dist[next] != INF) {
                    edges.erase(edges.find({dist[next], next}));
                }

                dist[next] = newArrivalTime;
                edges.emplace(newArrivalTime, next);
            }
        }
    }
    return -1;
}


int main() {

    long long v, e , start, end;
    std::cin >> v >> e >> start >> end;
    for (long long i = 0; i < v; ++i) {
        std::cin >> intervals[i];
    }
    std::vector<std::vector<Edge>> graph (v);
    for (long long i = 0; i < e; ++i) {
        long long from, to, weigth;
        std::cin >> from >> to >> weigth;
        graph[from].emplace_back(weigth, to);
        graph[to].emplace_back(weigth, from);
    }

    std::cout<<timeToArriveTo(graph, start, end);

    return 0;
}
