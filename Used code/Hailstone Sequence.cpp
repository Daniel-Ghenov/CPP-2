#include <iostream>
#include <cmath>

int main (){

    int n;
    int loops{0};
    int maxnum{0};

    std::cout<< "What number do you want to begin with?: "<<std::endl;
    std::cin >> n;
    std::cout<< n <<", ";

    while(n != 1){
        if(maxnum < n){maxnum = n;}
        if( n % 2 == 0){
            n = n/2;
            std::cout<< n <<", ";
            loops++;
        }
        else {
            n = 3 * n + 1;
            std::cout<< n <<", ";
            loops++;
        }
    }
    
    std::cout<<" "<<std::endl;
    std::cout<< "Number of loops: "<< loops<<std::endl;
    std::cout<< "Largest number reached: "<< maxnum;





    return 0;
}