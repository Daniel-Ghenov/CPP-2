#include <cmath>
#include <vector>
#include <iostream>

bool isPossible(std::vector<int>& programmers, int bracketsNum, int minMax){
    size_t currArr = 0;
    for(size_t i = 0; i < programmers.size(); i++){
        currArr += programmers[i];
        if(currArr > minMax){
            bracketsNum--;
            currArr = programmers[i];
        }
        if(bracketsNum <= 0){
            return false;
        }
    }
    return currArr <= minMax;
}

size_t minBracket(std::vector<int>& programmers, size_t bracketsNum){

    size_t sum = 0;

    for(size_t i = 0; i < programmers.size(); i++){
        sum += programmers[i];
    }
    size_t currMin = std::numeric_limits<size_t>::max();

    size_t min = 0, max = sum;
    while(min <= max){
        size_t mid = min + (max - min)/2;

        if(isPossible(programmers, bracketsNum, mid)){
            if(currMin > mid){
                currMin = mid;
            }
            max = mid - 1;
        }else{
            min = mid + 1;
        }
    }
    return currMin;
}

int main() {
    int size, bracketsNum;
    std::cin>>size>>bracketsNum;
    std::vector<int> programmers(size);
    for(size_t i = 0; i < size; i++){
        std::cin>>programmers[i];
    }
    std::cout<<minBracket(programmers, bracketsNum);
    return 0;
}
