#include <iostream>
#include "Vector.hpp"

int main(){
    std::cout<<'a';
    Vector<int> vector(5, 4);
    vector[0] = 5;
    for(size_t i {0}; i < vector.size(); i++){
        std::cout<<vector[i]<<' ';
    } 
    
    return 0;
}