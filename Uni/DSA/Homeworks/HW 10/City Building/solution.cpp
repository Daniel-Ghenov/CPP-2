#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>


int dfs(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int start) {

    std::stack<int> st;
    st.push(start);

    visited[start] = true;
    int visitedCount = 0;
    while(!st.empty()) {

        int top = st.top();
        st.pop();

        if(!visited[top]) {
            visited[top] = true;
            visitedCount++;
        }

        for(int i = graph[top].size() - 1; i >= 0; i--) {
            if(!visited[graph[top][i]]) {
                st.push(graph[top][i]);
            }
        }

    }
    return visitedCount;
}

int getMinCityPrice(std::vector<std::vector<int>>& graph, int roadPrice, int discoPrice) {
    if(roadPrice >= discoPrice) {
        return graph.size() * discoPrice;
    }

    std::vector<bool> visited(graph.size(), false);
    int roadsBuilt = 0;
    int citiesCount = 0;
    for (int i = 0; i < graph.size(); ++i) {
        if(visited[i]) {
            continue;
        }
        roadsBuilt += dfs(graph, visited, i);
        citiesCount++;
    }
    return roadsBuilt * roadPrice + citiesCount * discoPrice;
}



int main() {
    int a;
    std::cin>>a;

    for (int i = 0; i < a; ++i) {
        int n, m, l, k;
        std::cin >> n >> m >> l >> k;
        std::vector<std::vector<int>> graph(n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            std::cin >> x >> y;
            x--;
            y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        std::cout<< getMinCityPrice(graph, k, l)<<std::endl;
    }

    return 0;
}
