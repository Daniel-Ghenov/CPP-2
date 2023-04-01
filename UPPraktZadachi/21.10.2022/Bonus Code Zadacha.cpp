#include <iostream>

int main(){

    int a, b;
    std::cin>>a;
    std::cin>>b;
    bool first = a > b;
    bool second = b > a;
    std::cout<< (first*a) + (second*b);


    return 0;
}