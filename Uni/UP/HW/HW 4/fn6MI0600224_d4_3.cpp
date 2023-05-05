/**
*  
* Solution to homework assignment 4
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

const int MAX_SIZE = 257;

bool initializeArray(char* array){
	array[256] = '\0';
	std::cin.getline(array, MAX_SIZE);
	if(array[256] != '\0')
		return true;
	return false;	
}

void checkIfCorrect(char* array){
	//If we have a ")" before it's matching "(" then the input is obviously incorrect
	//Also if we have more "(" than ")" than we have the same output
	if(initializeArray(array)){
		std::cout<<"wrong input";
		return;
	}
	int bracketCounter = 0;
	for(size_t i {0}; i < MAX_SIZE && array[i] != '\0'; i++){
		if(array[i] == '(')
			bracketCounter++;
		else if(array[i] == ')')
			bracketCounter--;
		if(bracketCounter < 0){
			std::cout<<"incorrect";
			return;
		}
	}
	if(bracketCounter == 0){
		std::cout<<"correct";
		return;
	}
	std::cout<<"incorrect";
}

int main(){

	char array[MAX_SIZE];
	checkIfCorrect(array);
	
	return 0;
}
