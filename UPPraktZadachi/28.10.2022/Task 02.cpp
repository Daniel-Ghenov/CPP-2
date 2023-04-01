#include <iostream>

bool isEven(int a){


    return (a & 2 == 0);
}

int main(){

    std::cout<< isEven(10);

    return 0;

} 