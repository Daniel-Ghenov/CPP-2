#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string::iterator left, std::string::iterator right){
        while(left != right){
            if(*left != *right){
                return false;
            }
            left--;
            right++;
        }
        return true;
    }

    std::string longestPalindrome(std::string str){
        if(str.size() == 0 || str.size() == 1)
            return str;
        std::string::iterator left = str.begin(), right = str.begin();
        std::string::iterator largestLeft = left;

        while(right != str.end()){
            if(isPalindrome(left, right) ){
                if(left != str.begin())
                    left--;
                largestLeft = left;
            }
            else
                left++;
            right++;
        }
        return std::string(largestLeft, largestLeft + (right - left));
    }
};