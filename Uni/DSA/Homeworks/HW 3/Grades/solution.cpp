#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int numInInterval(std::vector<int>& grades, std::pair<int, int>& bound){
    if(bound.first > bound.second)
        return 0;
    return std::upper_bound(grades.begin(), grades.end(), bound.second) -
           std::lower_bound(grades.begin(), grades.end(), bound.first);
}

int main() {
    int n, q;
    std::cin>>n>>q;
    std::vector<int> grades(n);
    for(int i = 0; i < n; i++){
        std::cin>>grades[i];
    }
    std::vector<std::pair<int, int>> gradeRanges(q);
    for(int i = 0; i < q; i++){
        std::cin>>gradeRanges[i].first>>gradeRanges[i].second;
    }

    std::sort(grades.begin(), grades.end());
    for(std::pair<int, int> gradeRange : gradeRanges){
        std::cout<<numInInterval(grades, gradeRange)<<std::endl;
    }

    return 0;
}
