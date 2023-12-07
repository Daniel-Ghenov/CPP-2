#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

struct Edge {
    int to;
    int weight;

    Edge(int to, int weight) : to(to), weight(weight) {}
};

int pathFromTo(std::vector<std::vector<Edge>>& graph, int from, int to) {

    std::vector<int>
    std::queue<int> queue;


}

int main() {
    //todo check if 0 to n-1 or 1 to n
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        std::cin>>from>>to>>weight;
        graph[from].emplace_back(to, weight);
    }
    int from , to;
    std::cin>>from>>to;
    std::cout<<pathFromTo(graph, from, to);

    return 0;
}
