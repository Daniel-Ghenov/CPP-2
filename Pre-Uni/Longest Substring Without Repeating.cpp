#include <iostream>
#include <string>


class Solution {
public:
    int check(std::string s, int startpos, int length,  int cnum2) {
        if(startpos + length >= s.size()){
            return cnum2;
            //std::cout<<"Throwing Out Of Bounds"<<std::endl;
        }
        //Creating a string from which to pull all characters to check against.
        std::string checkWith =  s.substr(startpos, length); 
        //std::cout<<"At the start of the loop cnum2 is: "<< cnum2<<std::endl; 
        int cnum {0};
    //std::cout<<"checkWith is: "<<checkWith<<std::endl;
    //std::cout<<"s[startpos + length] is: "<<s[startpos+ length]<<std::endl;
    for(size_t i {0}; i < length; i++){
        char character = checkWith[i];
        if(s[startpos + length] != character){cnum++;}}
        //std::cout<<"cnum is: "<<cnum<<" length is: "<<length<<std::endl;
    if(cnum == length){
        cnum2++;
        //std::cout<<"Cnum2 is: "<<cnum2<<std::endl;
        if(check (s, startpos, length + 1, cnum2) > cnum2){return check (s, startpos, length + 1, cnum2);}
        else{return cnum2;}
    }else{return cnum2;}
    return cnum2;
    }
    
    int substr(std::string s) {
        //std::string controlstring = {""}
        int answer {0};
        int cnum2;
        //if(s.size() < )
        for(int i {0}; i < s.size(); i++){
            //std::cout<<"__________________\n";
            //std::cout<<"Loop Number: "<<i+1<<std::endl;
            cnum2 = check(s, i, 1, 1);
            //std::cout<<"Cnum2 real is : "<<cnum2<<std::endl;
            if(cnum2 > answer){answer = cnum2;}
            
        }
    return answer;
    }
};


int main(){

    Solution sol1;

    int copicat = substr("azbskms");
    std::cout<< copicat;



    return 0;
}