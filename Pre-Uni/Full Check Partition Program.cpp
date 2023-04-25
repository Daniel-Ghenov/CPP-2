#include <iostream>
#include <cmath>
#include <time.h>
#include <string>


class Solution {
public:
    
    bool checkPartition(std::string s, unsigned int& startpos, int& length, int& cnum){

        
        
        if(startpos + length > s.size() || startpos == s.size() - 1){
            cnum = 1;
            return true;

        }
        std::string checkString = s.substr(startpos, length);

            if(checkString.find(s[startpos + length]) == std::string::npos){
                length++;
                if(checkPartition(s, startpos, length, cnum)){
                    length++;
                    return true;}
                checkPartition(s, startpos, length, cnum);
            }else{
                startpos += length;
                return true;
            }
        return false;

    }
    
    int partitionString(std::string s) {
        
        long int answer {0};
        int cnum{0};
        unsigned int startpos{0};
        int length{0};
        
        while(cnum != 1){
           length = 1;
           checkPartition(s, startpos, length, cnum);
           answer++; 
        }
        return answer;
    }
};


std::string Randomiser(unsigned int stringSize){

    
    std::string returnstring{""};
    char Append;

    for(size_t i {0}; i < stringSize; i++){
        Append = rand() % 26 + 97;
        returnstring += Append;
    }


    return returnstring;
}

void AvgPartition(unsigned int stringSize, unsigned int repetNum){

    Solution m;
    double answer{0};
    for(size_t i {0};i < repetNum; i++){
        std::string randomstring = Randomiser(stringSize);
        answer += m.partitionString(randomstring);
        //std::cout<<"Answer currently is: "<<answer<<std::endl;
    }
    answer = answer/repetNum;
    std::cout<<"The average partition size is: "<<answer;
}

int main(){

    srand(time(NULL));
    

    unsigned int stringSize{1000};
    unsigned int repetNum{1000};
    std::cout<<"What size string do you want to check?: \n";
    std::cin>>stringSize;
    std::cout<<"How many repetitions do you want?: \n";
    std::cin>>repetNum;



    AvgPartition(stringSize, repetNum);


    return 0;
}