#include <iostream>
#include "Math.h"
#include "Constants.h"


void clearConsole() {
	std::cout<<"\033[;H"; // Moves cursor to the top left
	std::cout<<"\033[J"; // Clears the console
}
void printNum(int** field, int i, int j){
    int numLen = (len(field[i][j]) == 0)? 1 : len(field[i][j]);     //Setting the width of numbers
    std::cout<<field[i][j];
    for(size_t i {0}; i < numWidth - numLen; i++){
        std::cout<<' ';
    }
}
void drawField(int** field, int fieldSize){

    for(size_t i {0}; i < fieldSize; i++){
        std::cout<<'\t';
        for(size_t j {0}; j < fieldSize; j++){
            printNum(field, i, j);
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}