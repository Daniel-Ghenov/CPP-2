/**
*  
* Solution to homework assignment 3
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
const int MAX_NUMBER_LENGTH = 8;

int pow(int a, int b){
    int power = 1;
    while(b > 0){
        power *= a;
        b--;
    }
    return power;
}
int len(int a){
    int length = 0;
    while(a > 0){
        length++;
        a/=10;
    }
    return length;
}
void enlargenArray(int*& array, int& size){
    size += 8;
    int* resized = new int[size];
    for(size_t i {0}; i < size; i++){
        resized[i] = array[i];
    }
    delete[] array;
    array = resized;
}
void drawImage(int* array, int rowLength,int arraySize){
    int sumOfElements = 0;
    for(size_t i {0}; i < arraySize;i++){
        sumOfElements += array[i];
    }
    if(sumOfElements % rowLength != 0){
        std::cout<<"Invalid input";
        return;
    }
    int rowPlacement = 0;
    for(size_t i {0}; i < arraySize; i++){
        int numberOfChars = array[i];
        char charToUse = (i % 2 == 0)? '.' : '#';
        for(size_t j {0}; j < numberOfChars; j++){
            if(rowPlacement % rowLength == 0 && rowPlacement != 0){
                std::cout<<std::endl;
                rowPlacement = 0;
            }
            std::cout<<charToUse;
            rowPlacement++;
        }
    }
}
int* transformArray(int* array, long long int size, int& newArraySize){
    int tempNum = 0;
    int numberCount = 0;
    int* numberArray = new int[size/3];
    //This function groups the bit into 3-bit numbers
    for(size_t i {0}; i < size; i++){
        (tempNum <<= 1) += array[i];
        if((i + 1) % 3 == 0 && i >= 2){
            numberArray[numberCount++] = tempNum;
            tempNum = 0;
        }
    }
    newArraySize = numberCount;
    return numberArray;
}
bool getNumber(int* array, int number,long long int& arrayCounter){

    for(int i {0} ; i < MAX_NUMBER_LENGTH; i++){
        array[arrayCounter++] = number >> 7 - i;
        number %= pow(2, 7 - i);
        if((arrayCounter ) % 3 == 0 && arrayCounter >= 5){
            bool lastTwoNumbersAreZeroes = true;
            for(int j = arrayCounter - 6; j < arrayCounter; j++){
                if(array[j] != 0){
                    lastTwoNumbersAreZeroes = false;
                    break;
                }
            }
            if(lastTwoNumbersAreZeroes)
                return true;
            //If the last 6 bits are all zeroes when we write a new number
            //Then we have 2 zeroes as numbers which marks the end of our number taking.
        }

    }

    return false;   
}

int* fillArray(int& arraySize, bool correctInput){
    int arrayLength = 0;
    int* array = new int[arrayLength];
    long long int arrayCounter = 0;

    while(true){
        enlargenArray(array, arrayLength);
        int number;
        std::cin>>number;
        if(number < 0 || number > 255){
            std::cout<<"Incorrect input";
            correctInput = false;
            return array;
        }
        if(getNumber(array, number, arrayCounter))
            break;
    }
    //The numbers are transformed into an array of bits
    //That array is then transformed into an array of 3 bit intagers
    int* numberArray = transformArray(array, arrayCounter, arraySize);
    delete[] array;
    return numberArray;
}
void makeImage(int rowLength){
    int arraySize = 0;
    bool correctInput = true;
    int* drawingArray = fillArray(arraySize, correctInput);
    if(!correctInput)
        return;
    drawImage(drawingArray, rowLength, arraySize);
    delete[] drawingArray;

}   

int main(){
    int rowLength;
    std::cin>>rowLength;
    makeImage(rowLength);

    return 0;
}