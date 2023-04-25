#include <iostream>
#include <string>

class Solution {
public:
    
    bool checkPartition(std::string s, int& startpos, int& length, int& cnum){

        if(startpos + length > s.size()){
            return true;
            cnum = 1;

        }

        int cnum {0}
        bool check {false};
        std::string checkString = s.substring(startpos, startpos + length);
        
        for(auto i : checkString){
            char ctrlChar = s[startpos + length];
            if(checkString[i] != ctrlChar){
                cnum++;  
            }
            if(cnum == checkString.size()){
                length++;
                if(checkPartition(s, startpos, length, cnum)){
                    length++;
                    return true;}
                checkPartition(s, startpos, length, cnum);
            }else{
                startpos += length;
                return true;
            }
            //if(checkPartition(s, startpos, length)){return}

        }




        return check;

    }
    
    int partitionString(std::string s) {
        
        int answer {0};
        int cnum{0};
        int startpos{0};
        int length{0};
        
        while(cnum != 1){
           checkPartition(s, startpos, length, cnum);
           answer++; 
        }
        
        return answer;
    }
};




int main(){





    return 0;
}