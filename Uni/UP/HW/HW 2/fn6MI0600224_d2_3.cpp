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

void swap(int& a, int& b){
    int tempnum = a;
    a = b;
    b = tempnum;
}
void printArray(const int* array, int size){

    for(size_t i {0};i < size; i++)
        std::cout<<array[i];

}
int numCounter(int* array, int beginpos, int size){
    //Given the beginning position we check how many times the digit repeats.

    int answer = 0;
    for(size_t i = beginpos ;i < size;i++ ){
        if(array[i] == array[beginpos])
            answer++;
        else 
            break;
    }

    return answer;
}
void swapArray(int* array1,int& size1, int* array2, int& size2){
    for(size_t i {0}; i < size2; i++){
        swap(array1[i], array2[i]);
    }
    swap(size1, size2);
}
int describeCurrentLoop(int* array1, int* array2, int size){

    int j = 0; //Setting up an array2 counter
    //For each number in the sequence we are describing we write down what number it is 
    //Then we check how many times it repeats itself and we continue from the next unique number
    for(size_t i {0}; i < size;){
        int currentDigit = array1[i];
        int digitCount = numCounter(array1, i, size);
        array2[j++] = digitCount;
        array2[j++] = currentDigit;
        i+= digitCount;
    }
    return j;
}

void countingSequence(int* array1, int* array2, int n){

    if(n < 1 || n > 20){
        std::cout<<"-1";
        return;
    }
    //Given our function to describe an array we rotate the first and second array
    //Always describing the first into the second.

    int size2;
    int size = 1;
    for(size_t i {1}; i < n; i++){
        size2 = describeCurrentLoop(array1, array2, size);
        swapArray(array1, size, array2, size2);

    }
    printArray(array1, size);

}

int main(){

    int n;
    std::cin>>n;

    int array1[MAX_ARRAY_SIZE] = {1};
    int array2[MAX_ARRAY_SIZE];

    countingSequence(array1, array2, n);

    return 0;
}