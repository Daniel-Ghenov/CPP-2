#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
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

int getMaxQualityIterativeTest(std::unordered_map<State, int>& memo, std::vector<RoadPiece>& roads, int k) {

    std::sort(roads.begin(), roads.end(), compare);
    ;
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


long long getMaxQualityTableTest(std::vector<std::vector<long long>>& table, std::vector<RoadPiece>& roads, long long k) {

    std::sort(roads.begin(), roads.end());

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

void test() {
    std::srand(time(nullptr));
    long long n, k;
    n = std::rand() % 100 + 1;
    k = std::rand() % 100 + 1;
    std::vector<RoadPiece> roads;
    for (long long i = 0; i < n; ++i) {
        long long s, e, q;
        s = std::rand() % 100 + 1;
        e = std::rand() % 100 + 1;
        q = std::rand() % 100 + 1;
        roads.emplace_back(s, e, q);
    }

    int table = getMaxQualityTable(roads, k);
    int iterative = getMaxQualityIterative(roads, k);

    if (table != iterative) {
        std::cout << "Table: " << table << " Iterative: " << iterative << std::endl;
        std::cout <<  n  << k << std::endl;
        for (auto& road : roads) {
            std::cout << road.start << " " << road.end << " " << road.quality << std::endl;
        }
    }

}
void testTestCase() {

    long long n, k;
    std::cin >> n >> k;
    std::vector<RoadPiece> roads;
    for (long long i = 0; i < n; ++i) {
        long long s, e, q;
        std::cin >> s >> e >> q;
        roads.emplace_back(s, e, q);
    }

    std::unordered_map<State, int> memo;
    std::vector<std::vector<long long>> table(k + 1, std::vector<long long>(roads.size() + 1, 0));

    int tableSolution = getMaxQualityTableTest(table, roads, k);
    int iterativeSolution = getMaxQualityIterativeTest(memo, roads, k);


    for(int i = 0; i < table.size(); i++) {
        for(int j = 0; j < table[i].size(); j++) {
            int tableSol = table[i][j];
            int iterativeSol = memo[State(i,j)];
            if (tableSol != iterativeSol) {
                std::cout << "roadsLeft: " << i << " currArrStart: " << j << std::endl;
                std::cout << "Table: " << table[i][j] << " Iterative: " << memo[State(i,j)] << std::endl;
            }
        }
    }

}

int main() {

//    test();
    testTestCase();

    return 0;
}
