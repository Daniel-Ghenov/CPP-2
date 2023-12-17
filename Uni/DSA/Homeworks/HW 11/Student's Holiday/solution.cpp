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

};

long long timeToArriveTo(const std::vector<std::vector<Edge>>& graph, long long start, long long end) {

    std::set<Edge> edges;
    std::vector<long long> dist(graph.size(), INF);
    dist[start] = 0;
    edges.emplace(0, start);

    while(!edges.empty()) {
        Edge temp = *(edges.begin());
        edges.erase(edges.begin());
        long long curr = temp.to;

        if(curr == end) {
            return temp.weight;
        }

        for(long long i = 0; i < graph[curr].size(); i++) {
            long long weight = graph[curr][i].weight;
            long long next = graph[curr][i].to;

            long long newArrivalTime = dist[curr] + weight;
            long long waitTime = newArrivalTime % intervals[next];
            if(waitTime != 0 && next != end) {
                newArrivalTime += intervals[next] - waitTime;
            }

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
