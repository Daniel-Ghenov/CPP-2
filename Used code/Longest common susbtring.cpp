#include <iostream>
#include <vector>

class Solution {
public:
    std::string check(std::vector<std::string>& strs, int startpos, int length, std::string answer){
        int cnum {0};
        std::cout<<"Trying check function"<<std::endl;
        std::string ctrlstring = strs[0].substr(startpos, length);
        for(size_t j {0}; j < strs.size(); j++){
            if(strs[j].find(ctrlstring) != std::string::npos){
            cnum++;
            std::cout<< "cnum is: "<< cnum << " ctrlstring is: "<<ctrlstring<< " and strs.size() is: "<<strs.size()<<std::endl;
            }
        }
        if(cnum == strs.size()){
            std::cout<<"Going through answering loop"<<std::endl;
            length++;
            if(ctrlstring.size() > answer.size()){
                std::cout<<"Going through second loop"<<std::endl;
                answer = ctrlstring;
                std::cout<<"answer in loop is: "<< answer<<std::endl;

                std::cout<<"answer in loop is: "<< answer<<std::endl;}
            }
        else{return answer;}
        std::cout<<"answer is: "<< answer<<std::endl;
        return answer;  
    }
    
    std::string longestCommonSubstring(std::vector<std::string>& strs) {
        
        std::string answer{""}; 
        
        for (size_t i {0}; i < size(strs[0]); i++){
            char charr {strs[0][i]};
            if(strs[0].find(charr) != std::string::npos){
                std::cout<< "_________________________\n";
                std::cout<< "i is: "<< i << " answer is: "<< answer<<std::endl;
                for (size_t j {0}; j < size(strs[0]); j++){
                    answer = check(strs, i, j + 1, answer);}
                
            }
              
        }
        
        
        
      return answer;  
    }
};

int main(){

    std::vector<std::string> strings {"flower", "flying", "flexing"};
    
    std::cout<<longestCommonSubstring(strings);





    return 0;
}
