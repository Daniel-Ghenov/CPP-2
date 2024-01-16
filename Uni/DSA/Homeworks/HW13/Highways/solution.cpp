#include <vector>
#include <iostream>
#include <algorithm>

struct RoadPiece {
    long long start;
    long long end;
    long long quality;

    RoadPiece(long long s, long long e, long long q) : start(s), end(e), quality(q) {}

    bool operator<(const RoadPiece& other) const {
        if (end == other.end) {
            if(quality == other.quality) {
                return start < other.start;
            }
            return quality < other.quality;
        }
        return end < other.end;
    }
};

long long findPreviousNonOverlapping(const std::vector<RoadPiece>& roads, long long i) {
    auto [start, e,q] = roads[i];
    long long nextStart = -1;
    for (long long j = i; j >= 0; --j) {
        if (roads[j].end < start) {
            nextStart = j;
            break;
        }
    }
    return nextStart;
}

long long getMaxQualityTable(std::vector<RoadPiece>& roads, long long k) {

    std::sort(roads.begin(), roads.end());
    std::vector<std::vector<long long>> table(k + 1, std::vector<long long>(roads.size() + 1, 0));

    std::vector<long long> previousCompatible(roads.size());

    for(long long i = 0; i < roads.size(); i++) {
        previousCompatible[i] = findPreviousNonOverlapping(roads,i);
    }


    for (long long i = 1; i <= k; ++i) {
        for (long long j = 1; j <= roads.size(); ++j) {
            long long roadTaken = roads[j - 1].quality;

            if (previousCompatible[j - 1] != -1) {
                roadTaken += table[i - 1][previousCompatible[j - 1] + 1];
            }

            long long roadNotTaken = table[i][j - 1];
            table[i][j] = std::max(roadTaken, roadNotTaken);
        }
    }
    return table[k][roads.size()];
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n, k;
    std::cin >> n >> k;
    std::vector<RoadPiece> roads;
    for (long long i = 0; i < n; ++i) {
        long long s, e, q;
        std::cin >> s >> e >> q;
        roads.emplace_back(s, e, q);
    }

    std::cout << getMaxQualityTable(roads, k) << std::endl;

    return 0;
}
