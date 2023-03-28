/**
*  
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Daniel Ghenov
* @idnumber 6MI0600224
* @task 1
* 
*/
#include <iostream>

const int MAX_SIZE = 1024;

void encryptArray(char* array, char encryptionSymbol){
    for(size_t i {0}; array[i]!= '\0'; i++){
        array[i] ^= encryptionSymbol;
    }
    std::cout<<array;
}

int main(){

    char array[MAX_SIZE];
    char encryptionSymbol;
    std::cin>>encryptionSymbol;
    std::cin.ignore();
    std::cin.getline(array, MAX_SIZE);
    encryptArray(array, encryptionSymbol);
    
    return 0;
}