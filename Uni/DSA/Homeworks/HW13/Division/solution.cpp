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


size_t answerQuery(std::unordered_map<long long, std::vector<long long>>& divisors, const Query& q) {
    size_t divUpper = std::upper_bound(divisors[q.k].begin(), divisors[q.k].end(), q.end) - divisors[q.k].begin();
    if (q.begin == 0) {
        return divUpper;
    }
    size_t divLower = std::lower_bound(divisors[q.k].begin(), divisors[q.k].end(), q.begin) - divisors[q.k].begin();

    return divUpper - divLower;
}


void addDivisors(std::unordered_map<long long, std::vector<long long>>& map, long long num, long long position) {
    long long sqrt = std::sqrt(num);
    for(long long i = 1; i <= sqrt; i++) {
        if(num % i == 0) {
            map[i].push_back(position);
            if(i * i != num) {
                map[num / i].push_back(position);
            }
        }
    }
}

void addDivisible(std::unordered_map<long long, std::vector<long long>>& map, long long num, long long position) {
    for(long long i = 2 * num; i <= MAX_N; i += num) {
        map[i].push_back(position);
    }
}

std::unordered_map<long long, std::vector<long long>> getDivisible(const std::vector<long long>& arr) {
    std::unordered_map<long long, std::vector<long long>> divisible;

    for(long long i = 0; i < arr.size(); i++) {
        addDivisors(divisible, arr[i], i);
        addDivisible(divisible, arr[i], i);
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

    std::unordered_map<long long, std::vector<long long>> divisible = getDivisible(arr);

    for(long long i = 0; i < q; i++) {
        long long b, e, k;
        std::cin >> b >> e >> k;
        b--;
        e--;
        Query query(b, e, k);
        std::cout << answerQuery(divisible, query) << ' ';
    }

    return 0;
}