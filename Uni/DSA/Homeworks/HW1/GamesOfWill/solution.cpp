#include <algorithm>
#include <vector>
#include <iostream>

int smallestDifference(std::vector<int>& arr, int smallestSubgroup){
    std::sort(arr.begin(), arr.end());
    int size = arr.size();

    if(smallestSubgroup > size){
        throw std::logic_error("Incorrect input");
    }
    int smallestNum = arr[0];
    int largestNum = arr[smallestSubgroup - 1];
    int minDiff = arr[smallestSubgroup - 1] - arr[0];
    for(int i = smallestSubgroup; i < size; i++){
        int currDiff = arr[i] - arr[i - smallestSubgroup + 1];
        if(currDiff < minDiff){
            minDiff = currDiff;
        }

    }
    return minDiff;
}

int main() {
    int n, k;
    std::cin>>n>>k;
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++){
        std::cin>>arr[i];
    }
    std::cout<<smallestDifference(arr, k);
    return 0;
}