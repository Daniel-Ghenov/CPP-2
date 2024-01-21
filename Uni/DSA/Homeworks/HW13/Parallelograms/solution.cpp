#include <vector>
#include <iostream>

struct Point {

    long long x;
    long long y;

    Point(long long x, long long y) : x(x), y(y) {}

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

};

long long parallelogramCount(const std::vector<Point>& points, const std::vector<std::vector<bool>>& plane) {

    int parallelograms = 0;

    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {

            int dx1 = points[j].x - points[i].x;
            int dy1 = points[j].y - points[i].y;

            for (int k = j + 1; k < points.size(); ++k) {

                int midDx = points[k].x - points[i].x;
                int midDy = points[k].y - points[i].y;

                if(midDx * dy1 == midDy * dx1) {
                    continue;
                }

                int x4 = points[k].x + dx1;
                int y4 = points[k].y + dy1;

                if(x4 < 0 || x4 >= plane.size() || y4 < 0 || y4 >= plane[0].size()) {
                    continue;
                }

                if(plane[x4][y4]) {
                    parallelograms++;
                }
            }
        }
    }
    return parallelograms;
}


int main() {

    long long n, m;
    std::cin >> n >> m;
    std::vector<Point> points;
    std::vector<std::vector<bool>> plane(n, std::vector<bool>(m, false));

    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m ; ++j) {
            char c;
            std::cin >> c;
            if (c == 'x') {
                points.push_back(Point(i, j));
                plane[i][j] = true;
            }
        }
    }
    std::cout<<parallelogramCount(points, plane);

    return 0;
}
