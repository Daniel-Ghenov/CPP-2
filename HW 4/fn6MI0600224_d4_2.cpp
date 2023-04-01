/**
*  
* Solution to homework assignment 4
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
const int ALPHABET_SIZE = 26;
const int MAX_ARRAY_SIZE = 256;

int arraySize(char* array){
    int size = 0;
    while(array[size] != '\0' && size < MAX_ARRAY_SIZE){
        size++;
    }
    return size;
}
void initializeArrays(char* largerString, char* compareString, int* compareStringCount){
	//We initialize the arrays together with an array that contains the ammounts of each letter in the string we're comparing with
	for(size_t i {0}; i < ALPHABET_SIZE; i++){
		compareStringCount[i] = 0;
	}
    std::cin.getline(largerString, MAX_ARRAY_SIZE);
    std::cin.getline(compareString, MAX_ARRAY_SIZE);
	for(size_t i {0}; compareString[i] != '\0';i++){
		compareStringCount[compareString[i] - 'a']++;
	}
}
bool isAnagram(char* largerString, int largerSize,  char* compareString, int compareSize, int* compareStringCount , int startpos){
	//For each starting position we just check the ammounts of letters for that substring and compare to the compare string
    if(startpos + compareSize > largerSize){
        return false;
    }
    int* partitionCount = new int[ALPHABET_SIZE];
	for(size_t i {0}; i < ALPHABET_SIZE; i++){
		partitionCount[i] = 0;
	}
	for(size_t i = startpos; i < compareSize + startpos; i++){
		partitionCount[largerString[i] - 'a']++;
	}
	for(size_t i {0}; i < ALPHABET_SIZE; i++){
		if(partitionCount[i] != compareStringCount[i])
			return false;
	}
	return true;
}
void printAllAnagrams(char* largerString, char* compareString, int* compareStringCount){
	bool hasAnagrams = false;
    initializeArrays(largerString, compareString, compareStringCount);
	int largerSize = arraySize(largerString);
	int compareSize = arraySize(compareString);
	for(size_t i {0}; i < largerSize; i++){
		if(!hasAnagrams && isAnagram(largerString, largerSize, compareString, compareSize, compareStringCount, i)){
			std::cout<<i;
			hasAnagrams = true;
		}
        else if(isAnagram(largerString, largerSize, compareString, compareSize, compareStringCount, i))
			std::cout<<", "<<i;
	}
	if(!hasAnagrams)
		std::cout<<"\"no anagrams\"";
}

int main(){

    char firstString[MAX_ARRAY_SIZE], secondString[MAX_ARRAY_SIZE];
    int compareStringCount[ALPHABET_SIZE];
    printAllAnagrams(firstString, secondString, compareStringCount);



    return 0;
}