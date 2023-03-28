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
    //We use the Ucledean Method of finding gcd
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

int checkIfMagic(int* array, unsigned ammountOfNumbers){

    if(ammountOfNumbers > 1024 || ammountOfNumbers < 2)
        return -1;
    if(enterNumbers(array, ammountOfNumbers))
        return -1;
    int currentGcd = gcd(array[0], array[1]);

    //We find the gcd of the whole array by finding the gcd of two elements and then their gcd with the next element;
    for(size_t i {2}; i < ammountOfNumbers; i++){
        currentGcd = gcd(currentGcd, array[i]);
        if(currentGcd == 1)
            return 1;
    }

    
    return 0;
}
//An array will be magic if and only if the gcd of at least 2 of the elements inside it is 1
//That is because if the gcd of all of the elements inside it is larger than 1 
//than the difference of the elements inside multiplied by any whole number will be a multiple of that gcd.

int main(){

    int array[MAX_ARRAY_SIZE];
    unsigned ammountOfNumbers;
    std::cin>>ammountOfNumbers;
    std::cout<<checkIfMagic(array, ammountOfNumbers);

    return 0;
}  