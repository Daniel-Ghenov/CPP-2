#include <iostream>

const int MAX_SIZE = 1024;

void printArray(char* array1, int size){

    for(size_t i {0}; i < size;i++){
        std::cout<<array1[i]<<" ";
    }

}
void reverseArray(char* array1, int size){

    for(size_t i {0}; i < size/2; i++){
        char temp;
        temp = array1[i];
        array1[i] = array1[size - i - 1];
        array1[size - i - 1] = temp;

    }
}
void exeptionallyLargeOperations(char* array1, int size1, char* array2, int size2, int operand)




int main (){

    int size1, size2;
    char array1[MAX_SIZE], array2[MAX_SIZE];
    std::cin>>size1>>array1>>size2>>array2;



	
	return 0;
}