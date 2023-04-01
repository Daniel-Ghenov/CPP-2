#include <iostream>

int main(){

    int n;
    std::cin>>n;
    int guess = -2;

    while(guess != n){
        std::cout<< "Guess The Number: "<<std::endl;
        std::cin>>guess;
        if(guess > n)
            std::cout<<"The number is lower."<<std::endl;
        else if(n > guess)
            std::cout<<"The number is higher."<<std::endl;
        
    }




}