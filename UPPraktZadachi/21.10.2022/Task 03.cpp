#include <iostream>

int main(){

    int n;
    std::cin>>n;
    n = n * n;
    while(n != 0){
        if(n % 10 != 0){
            std::cout<< n % 10;
        }
        n = n / 10;

    }
}