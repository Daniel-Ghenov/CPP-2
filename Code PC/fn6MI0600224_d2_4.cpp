/**
*  
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Daniel Ghenov
* @idnumber 6MI0600224
* @task 4
* 
*/

#include <iostream>

const int MAX_ARRAY_SIZE = 1024;

void swap(int& a, int& b){
    int tempnum = a;
    a = b;
    b = tempnum;
}

int gcd(int a, int b){

    if(b > a)
        swap(a,b);
    while(b > 0){
        int tempnum = a % b;
        a = b;
        b = tempnum;
    }
    return a;
}

bool enterNumbers(int* array, int size){

    for(size_t i {0}; i < size; i++){
        std::cin>>array[i];
        if(array[i] < 1 || array[i] > 1000000000)
            return true;
    }
    return false;
}

int checkIfMagic(){
    int array1[MAX_ARRAY_SIZE];
    int ammountOfNumbers;
    std::cin>>ammountOfNumbers;
    if(ammountOfNumbers > 1024 || ammountOfNumbers < 2)
        return -1;
    if(enterNumbers(array1, ammountOfNumbers))
        return -1;
    for(size_t i {0}; i < ammountOfNumbers - 2;i++){
        if(gcd(array1[i], array1[i+1]) == 1)
            return 1;
    }

    
    return 0;
}

int main(){

    std::cout<<checkIfMagic();



    return 0;
}