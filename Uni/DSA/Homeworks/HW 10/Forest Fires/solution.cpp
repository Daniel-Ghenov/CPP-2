#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}
};

struct Corners {
    int top;
    int bottom;
    int left;
    int right;

    int getArea() {
        return (right - left + 1) * (bottom - top + 1);
    }

    explicit Corners(Point point) : top(point.y), bottom(point.y), left(point.x), right(point.x) {}

    void update(const Point& point) {
        if(point.x < left) {
            left = point.x;
        }
        if(point.x > right) {
            right = point.x;
        }
        if(point.y < top) {
            top = point.y;
        }
        if(point.y > bottom) {
            bottom = point.y;
        }
    }
};


class BurntForestSolution {
public:
    std::vector<int> getBurnedAreas(const std::vector<std::vector<bool>>& forest) {
        std::vector<std::vector<bool>> visited(forest.size(), std::vector<bool>(forest[0].size(), false));
        std::vector<int> solution;

        for(int i = 0; i < forest.size(); ++i) {
            for(int j = 0; j < forest[0].size(); ++j) {
                if(!forest[i][j] || visited[i][j]) {
                    continue;
                }
                solution.push_back(bfs(forest, visited,i,j).getArea());
            }
        }
        std::sort(solution.begin(), solution.end());
        return solution;
    }
private:


    Corners bfs(const std::vector<std::vector<bool>>& forest, std::vector<std::vector<bool>>& visited, int i, int j) {

        std::queue<Point> queue;
        queue.emplace(i, j);
        Corners corners({i, j});
        visited[i][j] = true;
        while(!queue.empty()) {
            Point top = queue.front();
            queue.pop();
            corners.update(top);

            if(top.x + 1 < forest.size() && forest[top.x + 1][top.y] && !visited[top.x + 1][top.y]) {
                queue.push({top.x + 1, top.y});
                visited[top.x + 1][top.y] = true;
            }
            if(top.x - 1 >= 0 && forest[top.x - 1][top.y] && !visited[top.x - 1][top.y]) {
                queue.push({top.x - 1, top.y});
                visited[top.x - 1][top.y] = true;
            }
            if(top.y - 1 >= 0 && forest[top.x][top.y - 1] && !visited[top.x][top.y - 1]) {
                queue.push({top.x, top.y - 1});
                visited[top.x][top.y - 1] = true;
            }
            if(top.y + 1 < forest.size() && forest[top.x][top.y + 1] && !visited[top.x][top.y + 1]) {
                queue.push({top.x, top.y + 1});
                visited[top.x][top.y + 1] = true;
            }

        }
        return corners;
    }

};



int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<bool>> forest(n, std::vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            std::cin>>x;
            if(x) {
                forest[i][j] = true;
            }
        }
    }
    BurntForestSolution s;

    std::vector<int> solution = s.getBurnedAreas(forest);

    for(int i = solution.size() - 1; i >= 0; i--) {
        std::cout << solution[i] << " ";
    }

    return 0;
}
