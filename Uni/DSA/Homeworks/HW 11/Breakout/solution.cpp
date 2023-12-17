#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

const long long INF = LONG_LONG_MAX;

struct Edge {
    long long weight;
    long long i;
    long long j;

    Edge(long long weight, long long i, long long j) : weight(weight), i(i), j(j) {}

    bool operator<(const Edge& other) const {
        if(weight == other.weight) {
            if(i == other.i) {
                return j < other.j;
            }
            return i < other.i;
        }
        return weight < other.weight;
    }
    bool operator==(const Edge& other) const {
        return weight == other.weight && i == other.i && j == other.j;
    }

};

long long bfs(const std::vector<std::vector<bool>>& graph, std::vector<std::vector<bool>>& visited, int i, int j) {

    std::queue<std::pair<int, int>> q;
    q.emplace(i, j);

    int count = 0;

    while(!q.empty()) {
        std::pair<int, int> temp = q.front();
        q.pop();
        int i = temp.first;
        int j = temp.second;

        if(i < 0 || i >= graph.size() || j < 0 || j >= graph[0].size() || visited[i][j] || graph[i][j]) {
            continue;
        }

        visited[i][j] = true;
        count++;
        q.emplace(i + 1, j);
        q.emplace(i - 1, j);
        q.emplace(i, j + 1);
        q.emplace(i, j - 1);
    }
    return count;
}



std::pair<int, int> getMaxDists(const std::vector<std::vector<bool>>& graph, std::vector<std::vector<bool>>& visited, int i, int j ) {

    std::set<Edge> edges;
    std::vector<std::vector<long long>> dist(graph.size(), std::vector<long long>(graph[0].size(), INF));
    dist[i][j] = 0;
    edges.emplace(0, i, j);

    long long currLevel = bfs(graph, visited, i, j);

    while(!edges.empty()) {
        Edge temp = *(edges.begin());
        edges.erase(edges.begin());
        std::pair<int, int> to = {temp.i, temp.j};

        if(to.first <= 0 || to.second <= 0 || to.first >= graph.size() - 1 || to.second >= graph[0].size() - 1) {
            return {temp.weight, currLevel};
        }

        {
            long long newArrivalTime = dist[to.first][to.second] + graph[to.first + 1][to.second];
            if(newArrivalTime < dist[to.first + 1][to.second]) {
                if(dist[to.first + 1][to.second] != INF) {
                    edges.erase(edges.find({dist[to.first + 1][to.second], to.first + 1, to.second}));
                }
                dist[to.first + 1][to.second] = newArrivalTime;
                edges.insert({newArrivalTime, to.first + 1, to.second});
            }
        }
        {
            long long newArrivalTime = dist[to.first][to.second] + graph[to.first - 1][to.second];
            if(newArrivalTime < dist[to.first - 1][to.second]) {
                if(dist[to.first - 1][to.second] != INF) {
                    edges.erase(edges.find({dist[to.first - 1][to.second], to.first - 1, to.second}));
                }
                dist[to.first - 1][to.second] = newArrivalTime;
                edges.insert({newArrivalTime, to.first - 1, to.second});
            }
        }
        {
            long long newArrivalTime = dist[to.first][to.second] + graph[to.first][to.second + 1];
            if(newArrivalTime < dist[to.first][to.second + 1]) {
                if(dist[to.first][to.second + 1] != INF) {
                    edges.erase(edges.find({dist[to.first][to.second + 1], to.first, to.second + 1}));
                }
                dist[to.first][to.second + 1] = newArrivalTime;
                edges.insert({newArrivalTime, to.first, to.second + 1});
            }
        }
        {
            long long newArrivalTime = dist[to.first][to.second] + graph[to.first][to.second - 1];
            if(newArrivalTime < dist[to.first][to.second - 1]) {
                if(dist[to.first][to.second - 1] != INF) {
                    edges.erase(edges.find({dist[to.first][to.second - 1], to.first, to.second - 1}));
                }
                dist[to.first][to.second - 1] = newArrivalTime;
                edges.insert({newArrivalTime, to.first, to.second - 1});
            }
        }

    }
    return {-1, currLevel};
}

int maxCells(const std::vector<std::vector<bool>>& graph) {
    int maxDist = 0;
    int currCells = 0;
    std::vector<std::vector<bool>> visited(graph.size(), std::vector<bool>(graph[0].size(), false));

    for(int i = 0; i < graph.size(); i++) {
        for(int j = 0; j < graph[0].size(); j++) {
            if(!visited[i][j] && !graph[i][j]) {
                std::pair<int, int> temp = getMaxDists(graph, visited, i, j);
                if(temp.first > maxDist) {
                    maxDist = temp.first;
                    currCells = temp.second;
                } else if(temp.first == maxDist) {
                    currCells += temp.second;
                }
            }
        }
    }
    return currCells;
}

int main() {

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<bool>> graph(n, std::vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char temp;
            std::cin >> temp;
            graph[i][j] = temp == '#';
        }
    }

    std::cout<<maxCells(graph);

    return 0;
}
