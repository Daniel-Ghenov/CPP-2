#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

bool compare(std::pair<int, int>& pair1, std::pair<int, int>& pair2) {
    return pair1.first > pair2.first;
}


void getTopoOrderRecurs(std::vector<std::vector<int>>& graph, std::stack<int>& orderStack, std::vector<bool>& visited, int curr) {
    if(visited[curr]) {
        return;
    }
    visited[curr] = true;
    for(int i = graph[curr].size() - 1; i >= 0; i--) {
        if(!visited[graph[curr][i]]) {
            getTopoOrderRecurs(graph, orderStack, visited, graph[curr][i]);
        }
    }
    orderStack.push(curr);

}

void getTopoOrder(std::vector<std::vector<int>>& graph, int start) {

    std::vector<std::pair<int, int>> finished;
    std::vector<bool> visited(graph.size(), false);

    std::stack<int> topoOrder;

    getTopoOrderRecurs(graph, topoOrder, visited, start);

    while(!topoOrder.empty()) {
        std::cout<< char(topoOrder.top() + 'a')<<' ';
        topoOrder.pop();
    }

}


void addEdge(std::vector<std::vector<int>>& graph, const std::string& str1, const std::string& str2, int& currStart) {

    int i = 0;
    while(str1[i] == str2[i] && str1[i]) {
        i++;
    }

    if(!str1[i]) {
        return;
    }
    graph[str1[i] - 'a'].push_back(str2[i] - 'a');
    if(str2[i] - 'a' == currStart) {
        currStart = str1[i] - 'a';
    }

}

int main() {
    int n;
    std::cin>>n;
    std::string str1;
    std::string str2;

    std::cin>>str1;
    int start = str1[0] - 'a';
    if(n == 1) {
        std::cout<<str1[0];
        return 0;
    }
    std::vector<std::vector<int>> graph(26, std::vector<int>());

    for (int i = 0; i < n - 1; ++i) {
        std::cin>>str2;
        addEdge(graph, str1, str2, start);
        str1 = std::move(str2);
    }
    getTopoOrder(graph, start);


    return 0;
}
