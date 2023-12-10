#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

int minDistToFriend(const std::vector<std::vector<int>>& friends,const std::vector<int>& friendGroups, int currFriend) {

    std::vector<bool> visited(friends.size());

    std::queue<int> queue;
    queue.push(currFriend);
    int groupToLookFor = friendGroups[currFriend];
    int currDist = 0;
    int levelSize = 1;
    while(!queue.empty()) {
        int top = queue.front();
        queue.pop();

        if(friendGroups[top] == groupToLookFor && top != currFriend) {
            return currDist;
        }

        for(int loopFriend : friends[top]) {
            if(!visited[loopFriend]) {
                queue.push(loopFriend);
                visited[loopFriend] = true;
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

int minDistFromGroup(const std::vector<std::vector<int>>& friends, const std::vector<int>& friendGroups, int groupToLookAt) {

    int currMin = INT_MAX;

    for(int i = 0; i < friends.size(); i++) {
        if(friendGroups[i] == groupToLookAt) {
            currMin = std::min(minDistToFriend(friends, friendGroups, i), currMin);
        }
    }
    return currMin;
}

int main() {

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> friends(n, std::vector<int>());
    std::vector<int> friendGroups(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        a -= 1;
        b -= 1;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    for(int i = 0; i < n; ++i) {
        int group;
        std::cin >> group;
        friendGroups[i] = group;
    }
    int groupToLookAt;
    std::cin >> groupToLookAt;

    std::cout<<minDistFromGroup(friends, friendGroups, groupToLookAt) - 1;

    return 0;
}
