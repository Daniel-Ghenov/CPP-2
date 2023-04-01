#include <iostream>
#include <cmath>

int main(){

    int n = 0;
    std::cout<<"Enter a number: ";
    std::cin>>n;

    for(int i {0}; i <= n; i++){
        for(int j {1}; j <= i; j++){
            std::cout<<j;
        }
        std::cout<<std::endl;
    }



    return 0;
}