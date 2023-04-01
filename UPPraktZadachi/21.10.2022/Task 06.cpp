#include <iostream>

int main(){

    int n;
    std::cin>>n;
    int sum;
    int cnum;
    int sumActual = n;

    for(int i {1}; i < n; i++){
        std::cin>>cnum;
        sum += cnum;
        sumActual += i;
    }
    std::cout<< sumActual - sum;
}