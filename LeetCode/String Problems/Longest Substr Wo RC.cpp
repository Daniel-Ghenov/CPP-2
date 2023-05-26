/*
Longest Substring without repeating characters problem for Leetcode
Utilizing sliding window method;

*/
#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string str) { //does not check for repetition when sliding the window

        if(str.size() == 0 || str.size() == 1){     //needs to be fixed
            return str.size();
        }

        size_t len = 0;
        for(size_t i {0}; i < str.size();){
            bool found = false;
            size_t foundIdx = 0;

            for(size_t j = i - len; j < i; j++){
                if(str[j] == str[i]){
                    found = true;
                    foundIdx = j;
                    break;
                }
            }
            if(found){
                std::cout<<"found on: "<<i<<std::endl;
                i = foundIdx + len + 1;
            }
            else{
                i++;
                len++;
            }

        }
        return len;
    }
};