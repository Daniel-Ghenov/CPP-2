#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int longestSubstring(const std::string& str1, const std::string& str2) {


    std::vector<int> currRow(str2.size(), 0);
    std::vector<int> prevRow(str2.size(), 0);

    int currMax = 0;

    for(int i = str1.size() - 1; i >= 0; i--) {
        for(int j = str2.size() - 1; j >= 0; j--) {

            if(str1[i] != str2[j]) {
                currRow[j] = 0;
                continue;
            }

            currRow[j] = 1;

            if(i + 1 < str1.size() && j + 1 < str2.size()) {
                currRow[j] += prevRow[j + 1];
            }
            currMax = std::max(currMax, currRow[j]);
        }
        std::swap(currRow, prevRow);
    }
    return currMax;
}

int main() {
    std::string str1;
    std::string str2;
    std::cin>>str1>>str2;

    if(str1.size() < str2.size()) {
        std::swap(str1, str2);
    }

    std::cout<<longestSubstring(str1, str2);
    return 0;
}