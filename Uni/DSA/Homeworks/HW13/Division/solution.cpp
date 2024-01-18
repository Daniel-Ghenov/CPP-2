#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Query {
    int begin;
    int end;
    int k;

    Query(int b, int e, int k) : begin(b), end(e), k(k) {}
};

int answerQuery(const std::vector<int>& arr, const Query& q) {
    int count = 0;
    for(int i = q.begin; i <= q.end; i++) {
        if(arr[i] % q.k == 0 || q.k % arr[i] == 0) {
            count++;
        }
    }
    return count;
}

int main() {

    int n, q;
    std::cin >> n >> q;
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    for(int i = 0; i < q; i++) {
        int b, e, k;
        std::cin >> b >> e >> k;
        b--;
        e--;
        std::cout << answerQuery(arr,Query(b,e,k)) << ' ';
    }



    return 0;
}