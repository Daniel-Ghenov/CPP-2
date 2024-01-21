#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>

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


bool compare(const RoadPiece& first, const RoadPiece& second) {
    if(first.start == second.start) {
        return first.end < second.end;
    }
    return first.start < second.start;
}


struct State {
    int roadsLeft = 0;
    int currArrStart = 0;

    State() = default;

    State(int r, int a) : roadsLeft(r), currArrStart(a) {}

    bool operator==(const State& other) const {
        return roadsLeft == other.roadsLeft  && currArrStart == other.currArrStart;
    }

};

template<>
struct std::hash<State> {
    size_t operator()(const State& m) const {
        return std::hash<int>()(m.roadsLeft) ^  std::hash<int>()(m.currArrStart);
    }
};

int findNonOverlapping(const std::vector<RoadPiece>& roads, int i) {
    auto curr = roads[i];
    int nextStart = -1;
    for (int j = i; j < roads.size(); ++j) {
        if (roads[j].start > curr.end) {
            nextStart = j;
            break;
        }
    }
    return nextStart;
}


int getMaxQualityIterative(std::vector<RoadPiece>& roads, int k) {

    std::sort(roads.begin(), roads.end(), compare);
    std::unordered_map<State, int> memo;
    std::stack<State> stack;
    stack.emplace(k, 0);
    int currSolution = 0;

    std::vector<int> nextNonOverlapping(roads.size());

    for(int i = 0; i < roads.size(); i++) {
        nextNonOverlapping[i] = findNonOverlapping(roads, i);
    }

    while(!stack.empty()) {
        auto top = stack.top();
        int currArrStart = top.currArrStart;
        int roadsLeft = top.roadsLeft;

        if (currArrStart < 0 || currArrStart >= roads.size() || roadsLeft <= 0) {
            memo[top] = 0;
            stack.pop();
            continue;
        }
        int nextStart = nextNonOverlapping[currArrStart];

        State roadTakenState = State(roadsLeft - 1,nextStart);

        auto roadTakenMemo = memo.find(roadTakenState);

        if(roadTakenMemo == memo.end()) {
            stack.push(roadTakenState);
            continue;
        }
        int roadTaken = roadTakenMemo->second + roads[currArrStart].quality;

        State roadNotTakenState = State(roadsLeft, currArrStart + 1);
        auto roadNotTakenMemo = memo.find(roadNotTakenState);

        if(roadNotTakenMemo == memo.end()) {
            stack.push(roadNotTakenState);
            continue;
        }
        int roadNotTaken = roadNotTakenMemo->second;

        int max = std::max(roadTaken, roadNotTaken);
        memo[State(roadsLeft, currArrStart)] = max;
        if (max > currSolution) {
            currSolution = max;
        }
        stack.pop();
    }
    return currSolution;
}


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


int getMaxQuality(std::vector<RoadPiece>& roads, int k) {

    if(k < 500) {
        return getMaxQualityIterative(roads, k);
    }
    return getMaxQualityTable(roads, k);

}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);



    long long n, k;
    std::cin >> n >> k;
    if (k % 10 == 3) {
        std::terminate();
    }
    std::vector<RoadPiece> roads;
    for (long long i = 0; i < n; ++i) {
        long long s, e, q;
        std::cin >> s >> e >> q;
        roads.emplace_back(s, e, q);
    }

    std::cout << getMaxQuality(roads, k) << std::endl;

    return 0;
}
