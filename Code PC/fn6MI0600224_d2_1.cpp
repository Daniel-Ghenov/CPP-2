/**
*  
* Solution to homework assignment 2
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

void swap(int& a , int& b){
    int temp = a;
    a = b;
    b = temp;
}
void swap(char& a , char& b){
    char temp = a;
    a = b;
    b = temp;
}
void printArray(char* array, int size){
    std::cout<<std::endl;
    for(size_t i {0}; i < size;i++){
        std::cout<<array[i];
    }

}
bool incorrectInfo(char* array, int size){

    for(size_t i {0}; i < size; i++){
        if(array[i] > '9' || array[i] < '0')
        return true;
    }
    return false;
}
void reverseArray(char* array, int size){

    for(size_t i {0}; i < size/2; i++){
        swap(array[i], array[size - i - 1]);
    }
}
bool swapArray(char* array1, int& size1, char* array2, int& size2){
    for(size_t i {0}; i < size2; i++){
        swap(array1[i], array2[i]);
    }
    swap(size1, size2);
    return true;
}
bool shouldSwap(char* array1, int& size1, char* array2, int& size2){
    if(size1 > size2)
        return false;
    if(size1 < size2){
        swapArray(array1, size1, array2, size2);
        return true;
    }

    for(size_t i {0}; i < size1; i++){
        if(array1[i] > array2[i]){
            return false;
        }
        if(array1[i] < array2[i]){
            swapArray(array1, size1, array2, size2);
            return true;
        }
    }
    return false;
        
}

int removeFirstZeroes(char* array1, int maxsize){
    int numberOfFirst0s = 0;
    while(array1[numberOfFirst0s] == '0'){
        numberOfFirst0s++;
    }
    for(size_t i{0}; i < maxsize - numberOfFirst0s; i++){
        swap(array1[i], array1[i + numberOfFirst0s]);
    }
    if(numberOfFirst0s == maxsize)
        return 1;
    return maxsize - numberOfFirst0s;
}
void addMinus(char* array, int& size){
    if(array[0] == '-')
        return;
    reverseArray(array, size);
    array[size] = '-';
    reverseArray(array, ++size);

}
void removeMinus(char* array, int& size){
    if(array[0] != '-')
        return;
    reverseArray(array, size);
    reverseArray(array, --size);
}
int exeptionallyLargeAddition(char* array1, int size1, char* array2, int size2, char* arrayResult){

    bool swapped = shouldSwap(array1, size1, array2, size2);
    reverseArray(array1, size1);
    reverseArray(array2, size2);

    int resultSize = size1;
    bool intGetsBigger = false;
    bool shouldCarry1 = false;

    for(size_t i {0}; i < size1; i++){
        arrayResult[i] = array1[i];

        if(shouldCarry1){
            arrayResult[i]++;
            shouldCarry1 = false;
        }
        if(i < size2)
            arrayResult[i] += (array2[i] - '0');
        if(arrayResult[i] > '9'){
            arrayResult[i] -= 10;
            shouldCarry1 = true;
        }
        if(shouldCarry1 && i == (size1 - 1)){
            intGetsBigger = true;
        }
    }
    
    if(intGetsBigger){
        arrayResult[size1] = '1';
        resultSize++;
    }

    reverseArray(arrayResult, resultSize);

    reverseArray(array1, size1);
    reverseArray(array2, size2);
    if(swapped)
        swapArray(array1, size1, array2, size2);

    return resultSize;

}
int exeptionallyLargeSubstraction(char* array1, int size1, char* array2, int size2, char* arrayResult){

    bool swapped = shouldSwap(array1, size1, array2, size2);
    reverseArray(array1, size1);
    reverseArray(array2, size2);


    for(size_t i {0}; i < size1; i++){
        if( i >= size2){
            arrayResult[i] = array1[i];
        }
        else if(array1[i] >= array2[i])
            arrayResult[i] = array1[i] - array2[i] + '0';
        else{
            arrayResult[i] = array1[i] + ':' - array2[i];
            for(size_t tempsteps {1};tempsteps + i < size1; tempsteps++){
                if(array1[i + tempsteps] > '0'){
                    array1[i + tempsteps]--;
                    break;
                }
                else
                    array1[i + tempsteps] = '9';
            }
            
        }
    }
    reverseArray(arrayResult, size1);
    int resultSize = removeFirstZeroes(arrayResult, size1);

    if(swapped){
        swapArray(array1, size1, array2, size2);
        addMinus(arrayResult, resultSize);
    }
    
    reverseArray(array1, size1);
    reverseArray(array2, size2);
    return resultSize;

}
void addAndSubstract(char* array1, int size1, char* array2, int size2, char* arrayResult){

    if(incorrectInfo(array1, size1) || incorrectInfo(array2, size2) || size1 < 1 || size1 > 1024 || size2 < 1 || size2 > 1024){
        std::cout<<"-1";
        return;
    }

    if(array1[0] != '-' && array2[0] != '-'){
        int additionSize = exeptionallyLargeAddition(array1, size1, array2, size2, arrayResult);
        printArray(arrayResult, additionSize);
        int substractionSize = exeptionallyLargeSubstraction(array1, size1, array2, size2, arrayResult);
        printArray(arrayResult, substractionSize);

    }else if(array1[0] == '-' && array2[0] != '-'){
        removeMinus(array1, size1);
        int substractionSize = exeptionallyLargeSubstraction(array2, size2, array1, size1,arrayResult);
        printArray(arrayResult, substractionSize);
        int additionSize = exeptionallyLargeAddition(array1, size1, array2, size2, arrayResult);
        addMinus(arrayResult, additionSize);
        printArray(arrayResult, additionSize);
    }else if(array1[0] != '-' && array2[0] == '-'){
        removeMinus(array2, size2);
        int substractionSize = exeptionallyLargeSubstraction(array1, size1, array2, size2, arrayResult);
        printArray(arrayResult, substractionSize); 
        int additionSize = exeptionallyLargeAddition(array1, size1, array2, size2, arrayResult);
        printArray(arrayResult, additionSize);
    }else{
        removeMinus(array1, size1);
        removeMinus(array2, size2);
        int additionSize = exeptionallyLargeAddition(array1, size1, array2, size2, arrayResult);
        addMinus(arrayResult, additionSize);
        printArray(arrayResult, additionSize);
        int substractionSize = exeptionallyLargeSubstraction(array2, size2, array1, size1,arrayResult);
        printArray(arrayResult, substractionSize);

    }
}
int main (){

    int size1, size2;
    char array1[MAX_SIZE], array2[MAX_SIZE];
    char arrayResult[MAX_SIZE] = {0};
    std::cin>>size1>>array1>>size2>>array2;
    addAndSubstract(array1, size1, array2, size2, arrayResult);


	return 0;
}
