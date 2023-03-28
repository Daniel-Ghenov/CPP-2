#include <cmath>
#include <time.h>
#include "Constants.h"
#include "FileWork.h"

int len(int a){
    int length = 0;
    while(a > 0){
        length++;
        a/=10;
    }
    return length;
}
bool isEmptySpace(int** field, int fieldSize){
    for(size_t i {0}; i < fieldSize; i++){
        for(size_t j {0}; j < fieldSize; j++){
            if(field[i][j] == 0){
                return true;
            }
        }
    }
    return false;
}
void addRandomNumber(int** field, int* randomWeight, int fieldSize, int& turnCount){
    if(!isEmptySpace(field, fieldSize))
        return;
    
    int fieldSizeSquare = fieldSize*fieldSize;
    int emptyListSize = 0;
    int** emptySpaces = new int*[fieldSizeSquare];  //We create a list of all empty spaces as a 2d array containing 2 elements
    for(size_t i {0}; i < fieldSizeSquare; i++){    //The column and row. This is done to optimise selection of a random square with rand()
        emptySpaces[i] = new int[2];
    }
    for(size_t i {0}; i < fieldSize; i++){
        for(size_t j {0}; j < fieldSize; j++){
            if(field[i][j] == 0){
                emptySpaces[emptyListSize][0] = i;
                emptySpaces[emptyListSize++][1] = j; 
            }

        }
    }

    int randomWeightControlNum = (turnCount <= 40)? turnCount - 1: 40;
    randomWeight[0] = 80 - randomWeightControlNum;      //This is a method for weighed selection of which power of two we should put on the board;
    randomWeight[1] = 20 + randomWeightControlNum/2;    
    randomWeight[2] = randomWeightControlNum/2;

    int randomNumber = (rand() % 100) + 1;
    for(size_t i {0}; i < MAX_POWER_TO_SPAWN; i++){     //Using this technique we see in which partition the random number is
        if(randomNumber < randomWeight[i]){             //This way we simulate weighed odds for which power we pick
            randomNumber = pow(2, i + 1);
            break;
        }
        randomNumber-= randomWeight[i];
    }
    int randEmptySquare = rand() % emptyListSize;
    field[emptySpaces[randEmptySquare][0]][emptySpaces[randEmptySquare][1]] = randomNumber;

    for(size_t i {0}; i < fieldSizeSquare; i++){
        delete[] emptySpaces[i];
    }
    delete[] emptySpaces;
    return;
}
bool arePossibleMoves(int** field, int fieldSize){

    if(isEmptySpace(field, fieldSize))    //To check wether the game can continue we first check for empty spaces
        return true;
    for(size_t i {0}; i < fieldSize; i++){
        for(size_t j {0}; j < fieldSize; j++){
            if(i > 0){
                if(field[i][j] == field[i - 1][j])      //If there are none we continue with check wether any numbers can be added in any direction
                    return true;
            }if(i < fieldSize - 1){
                if(field[i][j] == field[i + 1][j])
                    return true;
            }if(j > 0){
                if(field[i][j] == field[i][j - 1])
                    return true;
            }if(j < fieldSize - 1){
                if(field[i][j] == field[i][j + 1])
                    return true;
            }
        }
    }
    return false;
}