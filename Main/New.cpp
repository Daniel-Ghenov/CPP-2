#include <iostream>

const int MAX_SIZE = 1024;

int largest(int a, int b);

void swap(int& a , int& b){
    int temp = a;
    a = b;
    b = temp;
}
void swap(char& a , char& b){
    int temp = a;
    a = b;
    b = temp;
}

void printArray(char* array1, int size){

    for(size_t i {0}; i < size;i++){
        std::cout<<array1[i]<<" ";
    }

}
void printArray(int* array1, int size){

    for(size_t i {0}; i < size;i++){
        std::cout<<array1[i];
    }

}
void reverseArray(char* array1, int size){

    for(size_t i {0}; i < size/2; i++){
        swap(array1[i], array1[size - i - 1]);
    }
}
void reverseArray(int* array1, int size){

    for(size_t i {0}; i < size/2; i++){
        char temp = array1[i];
        array1[i] = array1[size - i - 1];
        array1[size - i - 1] = temp;

    }
}
void largestArrayFirst(char* array1, int& size1, char* array2, int& size2){
    if(size1 >= size2)
        return;
    for(size_t i {0}; i < size2; i++){
        swap(array1[i], array2[i]);
    }
    swap(size1, size2);

}

void exeptionallyLargeAddition(char* array1, int size1, char* array2, int size2, int* arrayResult){

    reverseArray(array1, size1);
    reverseArray(array2, size2);
    largestArrayFirst(array1, size1, array2, size2);

    int resultSize = size1;


    for(size_t i {0}; i < size1; i++){
        arrayResult[i] += (array1[i] - '0');

        if(i < size2)
            arrayResult[i] += (array2[i] - '0');
        if(arrayResult[i] >= 10){
            arrayResult[i] -= 10;
            arrayResult[i + 1] = 1;
        }else 
            arrayResult[i + 1] = 0;

    }
    if(arrayResult[size1] = 1)
        resultSize++;

    reverseArray(arrayResult, resultSize);
    printArray(arrayResult, resultSize);


}




int main (){

    int size1, size2;
    char array1[MAX_SIZE], array2[MAX_SIZE];
    int arrayResult[MAX_SIZE] = {0};
    std::cin>>size1>>array1>>size2>>array2;
    exeptionallyLargeAddition(array1, size1, array2, size2, arrayResult);



	
	return 0;
}

int largest(int a, int b){
    return (a > b) ? a : b;
}