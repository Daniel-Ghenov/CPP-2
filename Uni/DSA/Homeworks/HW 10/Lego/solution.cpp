#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

struct Edge {
    int to;
    int weight;

    Edge(int to, int weight) : to(to), weight(weight) {}
};

int bfs(std::vector<std::vector<int>>& graph, int from, int to) {

    std::vector<bool> visited(graph.size());

    std::queue<int> queue;
    queue.push(from);
    int currDist = 0;
    int levelSize = 1;
    while(!queue.empty()) {
        int top = queue.front();
        queue.pop();

        if(top == to) {
            return currDist;
        }

        for(int neighbour : graph[top]) {
            if(!visited[neighbour]) {
                queue.push(neighbour);
                visited[neighbour] = true;
            }

        }

        levelSize--;
        if(levelSize == 0) {
            levelSize = queue.size();
            currDist++;
        }

    }

    return INT_MAX;
}


int pathFromTo(std::vector<std::vector<Edge>>& graph, int from, int to) {

    std::vector<std::vector<int>> updatedGraph(graph.size(), std::vector<int>());
    for (int i = 0; i < graph.size(); ++i) {

        for (int j = 0; j < graph[i].size(); ++j) {

            if(graph[i][j].weight == 1) {
                updatedGraph[i].push_back(graph[i][j].to);
            } else {
                updatedGraph[i].push_back(updatedGraph.size());
                updatedGraph.push_back(std::vector<int>());
                updatedGraph[updatedGraph.size() - 1].push_back(graph[i][j].to);
            }

        }

    }

    return bfs(updatedGraph, from, to);

}

int main() {
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        std::cin>>from>>to>>weight;
        graph[from].emplace_back(to, weight);
        graph[to].emplace_back(from, weight);
    }
    int from , to;
    std::cin>>from>>to;
    std::cout<<pathFromTo(graph, from, to);

    return 0;
}
