#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>


struct Point {

    long long x;
    long long y;

    Point(long long x, long long y) : x(x), y(y) {}

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

};


struct Line {
    double a;
    double b;

    Line(double a, double b) : a(a), b(b) {}

    static Line fromPoints(const long long x1, const long long y1, const long long x2, const long long y2) {
        double a = double(y2 - y1) / (x2 - x1);
        double b = y1 - a * x1;
        return Line(a, b);
    }

    bool operator==(const Line& other) const {
        return a == other.a && b == other.b;
    }
};

struct LineHash {
    size_t operator()(const Line& l) const {
        return std::hash<double>()(l.a) ^ std::hash<double>()(l.b);
    }
};

struct PointHash {
    size_t operator()(const Point& p) const {
        return std::hash<long long>()(p.x) ^ std::hash<long long>()(p.y);
    }
};


long long parallelogramCount(const std::vector<long long>& x, const std::vector<long long>& y) {

    std::unordered_map<Point, std::unordered_map<Line, long long, LineHash>, PointHash> midPointCount;
    for (long long i = 0; i < x.size(); i++)
    {
        for (long long j=i+1; j<x.size(); j++)
        {
            long long midX = x[i] + x[j];
            long long midY = y[i] + y[j];

            Line line = Line::fromPoints(x[i], y[i], x[j], y[j]);

            midPointCount[Point(midX, midY)][line]++;
        }
    }

    long long result = 0;
    for (auto it = midPointCount.begin(); it != midPointCount.end(); it++)
    {
        long long currWays = 1;
        auto curr = it->second;
        if(curr.size() == 1) {
            continue;
        }
        for (auto & it2 : curr) {
            long long count = it2.second;
            currWays *= count;
        }
        result += currWays;
    }

    return result;
}

long long parallelogramCount(const std::vector<Point>& points) {

    int parallelograms = 0;

    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {

            int dx1 = points[i].x - points[j].x;
            int dy1 = points[i].y - points[j].y;



            for (int k = j + 1; k < points.size(); ++k) {

                int midDx = points[k].x - points[i].x;
                int midDy = points[k].y - points[i].y;

                int midX1 = points[j].x + points[k].x;
                int midY1 = points[j].y + points[k].y;

                if(midDx * dy1 == midDy * dx1) {
                    continue;
                }

                for (int l = k + 1; l < points.size(); ++l) {
                    int dx2 = points[k].x - points[l].x;
                    int dy2 = points[k].y - points[l].y;

                    int midX2 = points[i].x + points[l].x;
                    int midY2 = points[i].y + points[l].y;

                    if(midDx * dy2 == midDy * dx2) {
                        continue;
                    }
                    if (midX1 == midX2 && midY1 == midY2) {
                        parallelograms++;
                    }
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


    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m ; ++j) {
            char c;
            std::cin >> c;
            if (c == 'x') {
                points.push_back(Point(i, j));
            }
        }
    }
    std::cout<<parallelogramCount(points);

    return 0;
}
