#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

bool compare(std::pair<int, int>& pair1, std::pair<int, int>& pair2) {
    return pair1.first > pair2.first;
}

std::vector<char> getTopoOrder(std::vector<std::vector<int>>& graph, int start) {

    std::vector<std::pair<int, int>> finished;
    std::vector<bool> visited(graph.size(), false);

    std::stack<int> st;
    st.push(start);

    visited[start] = true;
    int order = 0;
    while(!st.empty()) {

        int top = st.top();

        if(!visited[top]) {
            visited[top] = true;
        }
        bool added = false;
        for(int i = graph[top].size() - 1; i >= 0; i--) {
            if(!visited[graph[top][i]]) {
                st.push(graph[top][i]);
                added = true;
            }
        }

        if(!added) {
            st.pop();
            finished.emplace_back(order++, top);
        }
    }

    std::sort(finished.begin(), finished.end(), compare);
    std::vector<char> sol;
    for(std::pair<int, int> pair : finished) {
        sol.emplace_back( 'a' + pair.second );
    }
    return sol;
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
    std::vector<char> topoOrder = getTopoOrder(graph, start);

    for(char i : topoOrder) {
        std::cout<<i<<' ';
    }


    return 0;
}
