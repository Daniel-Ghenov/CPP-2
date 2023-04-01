/**
*  
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Daniel Ghenov
* @idnumber 6MI0600224
* @task 3
* 
*/
#include <iostream>

const int MAX_ARRAY_SIZE = 303;


void printArray(const int* array, int size){

    for(size_t i {0};i < size; i++)
        std::cout<<array[i];

}
int numCounter(int* array, int beginpos, int size){

    int answer = 0;
    for(size_t i = beginpos ;i < size;i++ ){
        if(array[i] == array[beginpos])
            answer++;
        else 
            break;
    }

    return answer;
}

void countingSequence(int* array1, int* array2, int n, int size){

    if(n == 1){
        printArray(array1, size);
        return;
    }
    int j = 0; //Setting up an array2 counter
    for(size_t i {0}; i < size;){
        int currentDigit = array1[i];
        int digitCount = numCounter(array1, i, size);
        array2[j++] = digitCount;
        array2[j++] = currentDigit;
        i+= digitCount;
    }
    countingSequence(array2, array1, --n, j);

}

int main(){

    int n;
    std::cin>>n;

    int array1[MAX_ARRAY_SIZE] = {1};
    int array2[MAX_ARRAY_SIZE];

    if(n < 1 || n > 20){
        std::cout<<"Incorrect input";
        return 0;
    }
    countingSequence(array1, array2, n, 1);

    return 0;
}