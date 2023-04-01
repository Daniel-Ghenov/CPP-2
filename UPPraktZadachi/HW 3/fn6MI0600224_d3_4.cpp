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
int* transformArray(int* array, long long int size){
    int tempNum = 0;
    int numberCount = 0;
    int* numberArray = new int[size/3];
    for(size_t i {0}; i < size; i++){
        if((i - 1) % 3 == 0){
            numberArray[numberCount] = tempNum;
            tempNum = 0;
        }
        (tempNum <<= 1) += array[i];
    }

    return numberArray;
}
bool getNumber(int* array, int number,long long int& arrayCounter){

    for(int i {0} ; i < 8; i++){
        if((arrayCounter + i - 1) % 3 == 0){
            bool lastTwoDigitsAreZeroes = true;
            for(size_t j = arrayCounter - 5; j <= arrayCounter; j++){
                if(array[j] != 0)
                    lastTwoDigitsAreZeroes = false;
            }
            if(lastTwoDigitsAreZeroes)
                return true;
        }
        array[arrayCounter++] = number >> 7 - i;
        number %= pow(2, 7 - i);
    }

    return false;
    
}

int* fillingArray(){
    int arrayLength = 8;
    int* array = new int[arrayLength];
    long long int arrayCounter = 0;

    while(true){
        arrayLength += 8;
        int* newArray = new int[arrayLength];
        delete[] array;
        array = newArray;
        int number;
        std::cin>>number;
        if(getNumber(array, number, arrayCounter))
            return array;
    }
 
}
int* fillArray(){
    int remainder = 0;
    int arrayLength = 8;
    int* array = new int[arrayLength];
    int arrayCounter = 0;

    for(size_t i {0};;i++){
        if(arrayCounter == arrayLength){
            arrayLength *= 2;
            int* newArray = new int[arrayLength];
            delete[] array;
            array = newArray;
        }
        int number, remainderLength = len(remainder);
        std::cin>>number;
        array[arrayCounter++] = remainder<<(3 - remainderLength) + (number>>5 + remainderLength);
        number %= pow(2, 5 + remainderLength);
        array[arrayCounter++] = number>>2 + remainderLength;
        number %= pow(2, 2 + remainderLength);
        if(remainderLength != 0){
            array[arrayCounter++] = number >> remainder - 1;
            remainderLength = remainder = 0;   
        }
        else
            remainder = number;




    }



}

int main(){

    return 0;
}