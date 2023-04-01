#include <cmath>
#include <iostream>


class Solution {
public:
    bool isSumEqual(std::string firstWord, std::string secondWord, std::string targetWord) {
        
        int FirstWordNum {0}, SecondWordNum{0}, TargetNum {0};
        
        for(size_t i {0}; i < firstWord.size();i++){
            FirstWordNum += (int(firstWord[i]) -97) * pow(10, firstWord.size() - i);
        }
        for(size_t i {0}; i < secondWord.size();i++){
            SecondWordNum += (int(secondWord[i]) -97) * pow(10, secondWord.size() - i);
        }
        for(size_t i {0}; i < targetWord.size();i++){
            TargetNum += (int(targetWord[i]) -97) * pow(10, targetWord.size() - i);
        }
        return(FirstWordNum + SecondWordNum == TargetNum);
        
        
    }
};

int main(){

    Solution s1;
    std::cout<<s1.isSumEqual("abca", "abba", "cacca");


    return 0;
}