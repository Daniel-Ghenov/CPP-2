#include <iostream>
#include "FileWork.h"
#include "Math.h"
#include "Input.h"
#include "Console.h"
#include "Control.h"
#include "Movement.h"
#include "Constants.h"

void turnControl(int** field, int* randomWeight, int fieldSize, int& turnCount, int& score){
    score = claculateScore(field, fieldSize);    //A function which controls each turn
    std::cout<< "Score: "<<score<<std::endl;
    drawField(field, fieldSize);
    if(!arePossibleMoves(field, fieldSize))
        return;
    char direction = getInput();
    moveField(field, fieldSize, turnCount, direction);
    addRandomNumber(field, randomWeight, fieldSize, turnCount);
    clearConsole();
    turnControl(field, randomWeight, fieldSize, ++turnCount, score);

}
void controlGame(){
    int fieldSize = 0;    //This function sets the board and prepares for a game
    int turnCount = 0;
    int score = 0;
    int randomWeight[MAX_POWER_TO_SPAWN] {0, 0, 0};
    char* nickname = getNickname();
    int** field = initializeArray(fieldSize);
    addRandomNumber(field, randomWeight, fieldSize, turnCount);
    turnControl(field, randomWeight, fieldSize, turnCount, score);
    setLeaderboard(fieldSize, score, nickname);
    deleteArray(field, fieldSize);
    delete[] nickname;
    mainMenu();
}
void mainMenu(){
    char* input = getMainMenuInput();
    if(stringCompare(input, "Start game") || stringCompare(input, "1")){
        delete[] input;
        clearConsole();
        controlGame();
    }else if(stringCompare(input, "Leaderboard") || stringCompare(input, "2")){
        delete[] input;
        printLeaderboard();
        mainMenu();
    }else if(stringCompare(input, "Quit") || stringCompare(input, "3")){
        delete[] input;
        return;
    }else{
        clearConsole();
        mainMenu();
    }
    
}