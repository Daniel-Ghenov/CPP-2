/*
Given a string and a number of rows
write the string like this (eg for 3 rows)
S   N
T I G
R

return the string if it was read by rows
eg (SNTIGR)
*/
#include <iostream>
#include <string>

class Solution {
public:
    std::string convert(const std::string& str, int numRows) {
        std::string strCpy = str;
        int counter = 0;
        bool down = true;
        for(size_t i {0}; i < numRows; i++){
            for(size_t j = i;j < str.size();){
                strCpy[counter++] = str[j];
                if(down){
                    j += 2 *(numRows - i) - 3;
                    down = false;
                }
                else{
                    j += 2 * i - 1;
                    down = true;
                }
            }
        }
    }
};