/**
*  
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Daniel Ghenov
* @idnumber 6MI0600224
* @task 2
* 
*/
#include <iostream>

const int MAX_SIZE = 15;
bool initializeArray(int* array, int& size){
    std::cin>>size;
    if(size > 15 || size < 1)
        return true;

    for(size_t i {0}; i < size; i++){
        int tempnum;
        std::cin>>tempnum;
        if(tempnum > 9999 || tempnum < 1)
            return true;
        array[i] = tempnum;
    }
    return false;
}
void swap(int& a, int & b){
    int tempnum = a;
    a = b;
    b = tempnum;
}
void printArray(int* array, int size){   
    for(size_t i {0}; i < size; i++){
        std::cout<<array[i]<<" ";
    }
}
int len(int a){
    int length = 0;
    while(a > 0){
        length++;
        a/=10;
    }
    return length;
}
int pow(int a, int b){
    int power = 1;
    while(b > 0){
        power *= a;
        b--;
    }
    return power;
}
int firstDigit(int a){
    return a / pow(10, len(a) - 1);
}
void removeFirstDigit(int& a){
    a %= pow(10, len(a) - 1);
}
bool shouldSwapNumbers(int a, int b){
    int alength = len(a);
    int blength = len(b);
    //We check if the first digit of a is larger than b
    //Then we remove that letter untill either a or b falls below 10
    //Then we keep checking the next digit of the one larger than 10 with the last one of the other number
    while(a > 10 || b > 10){
        if(firstDigit(b) > firstDigit(a))
            return true;
        else if(firstDigit(a) > firstDigit(b))
            return false;
        if(a >= 10)
        removeFirstDigit(a);
        if(b >= 10)
        removeFirstDigit(b);

    }
    //To check for a problem with zeroes in the last place we return the shorter number
    return alength > blength;

}
void sortArrayProjection(int* array, int size){

    for(size_t i {0}; i < size - 1; i++){
        for(size_t j {0}; j < size - 1 - i; j++){
            if(shouldSwapNumbers(array[j], array[j + 1]))
            swap(array[j], array[j + 1]);
        }
    }
}


int main(){

    int size;
    int array[MAX_SIZE] ;
    if(initializeArray(array, size)){
        std::cout<<-1;
        return 0;
    }
    sortArrayProjection(array, size);
    printArray(array, size);

    return 0;
}