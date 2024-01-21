#include <vector>
#include <iostream>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>

const long long MAX_N = 200000;

struct Query {
    long long begin;
    long long end;
    long long k;

    Query(long long b, long long e, long long k) : begin(b), end(e), k(k) {}
};

long long answerQuery(std::unordered_map<long long, std::vector<long long>>& divisors, std::unordered_map<long long, std::vector<long long>>& divisible, const Query& q) {
    auto divLower = std::lower_bound(divisors[q.k].begin(), divisors[q.k].end(), q.begin);
    auto divUpper = std::upper_bound(divisors[q.k].begin(), divisors[q.k].end(), q.end);

    auto diviLower = std::lower_bound(divisible[q.k].begin(), divisible[q.k].end(), q.begin);
    auto diviUpper = std::upper_bound(divisible[q.k].begin(), divisible[q.k].end(), q.end);

    long long divDist = std::distance(divLower, divUpper);
    long long diviDist = std::distance(diviLower, diviUpper);

    return divDist + diviDist;
}

std::vector<long long> getDivisors(long long n, const std::vector<long long>& arr) {
    std::vector<long long> divisors;
    long long sqrtN = std::ceil(std::sqrt(n));
    for(long long i = 1; i <= sqrtN; i++) {
        if(n % i == 0) {
            auto it = std::find(arr.begin(), arr.end(), i);
            if (it != arr.end()) {
                divisors.push_back(std::distance(arr.begin(), it));
            }
        }
    }
    return divisors;
}

std::unordered_map<long long, std::vector<long long>> getDivisors(const std::vector<long long>& arr, const std::set<long long>& kSet) {
    std::unordered_map<long long, std::vector<long long>> divisors;

    for(long long k: kSet) {
        divisors[k] = getDivisors(k, arr);
    }

    return divisors;
}

std::vector<long long> getDivisible(long long n, const std::vector<long long>& arr, long long maxElement) {
    std::vector<long long> divisible;
    for(long long i = 1; i * n <= maxElement; i++) {
        auto it = std::find(arr.begin(), arr.end(), i * n);
        if (it != arr.end()) {
            divisible.push_back(std::distance(arr.begin(), it));
        }
    }
    return divisible;
}

std::unordered_map<long long, std::vector<long long>> getDivisible(const std::vector<long long>& arr, const std::set<long long>& kSet, long long maxElement) {
    std::unordered_map<long long, std::vector<long long>> divisible;

    for(long long k: kSet) {
        divisible[k] = getDivisible(k, arr, maxElement);
    }

    return divisible;
}


int main() {

    long long n, q;
    std::cin >> n >> q;
    std::vector<long long> arr(n);
    for(long long i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::vector<Query> queries;
    std::set<long long> kSet;
    long long maxNum = *std::max_element(arr.begin(), arr.end());

    for(long long i = 0; i < q; i++) {
        long long b, e, k;
        std::cin >> b >> e >> k;
        b--;
        e--;
        queries.emplace_back(b, e, k);
        kSet.insert(k);
    }

    std::unordered_map<long long, std::vector<long long>> divisors = getDivisors(arr, kSet);
    std::unordered_map<long long, std::vector<long long>> divisible = getDivisible(arr, kSet, maxNum);

    for (Query q: queries) {
        std::cout << answerQuery(divisors, divisible, q) << ' ';
    }

    return 0;
}