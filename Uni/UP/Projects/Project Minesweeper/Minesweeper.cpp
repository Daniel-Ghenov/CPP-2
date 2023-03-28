#include <iostream>
#include <cmath>
#include <time.h>
#include <string>
#include <vector>
#include <sstream>

const int MAX_SIZE = 10;

void initializeBoolArray(bool isVisible[][MAX_SIZE], int fieldSize){

    for(size_t i {0}; i < fieldSize; i++){
        for(size_t j {0}; j < fieldSize; j++){
            isVisible[i][j] = false;
        }
    }

}
int countOfMines(char field[][MAX_SIZE], int row, int col, int fieldSize){
    int count = 0;
    for(int i {-1}; i < 2; i++){
        for(int j {-1}; j < 2; j++){
            if(row + i > 0 && row + i < fieldSize && col + j > 0 && col + j< fieldSize){
                if(field[row + i][col + j] == '*')
                count++;
            }
        }
    }
    return count;

}
void initializeField(char field[][MAX_SIZE], int fieldSize, int mineCount){

    for(size_t i {0}; i < mineCount; i++){
        field[rand() % fieldSize][rand() % fieldSize] = '*';
    }
    for(size_t i {0}; i < fieldSize; i++){
        for(size_t j {0}; j < fieldSize; j++){
            if(field[i][j] != '*'){
                field[i][j] = countOfMines(field, i, j, fieldSize) + '0';
            }
        }
    }


}

void drawField(char field[][MAX_SIZE], bool isVisible[][MAX_SIZE], int fieldSize){

    for(size_t i {0}; i < fieldSize + 2; i++){
        for(size_t j {0}; j < 2*fieldSize + 1; j++){
            if(i == 0 || i == fieldSize + 1)
                std::cout<<"_";
            else if(j % 2 == 0)
                std::cout<<"|";
            else if(isVisible[i - 1][j/2])
                std::cout<<field[i-1][j/2];
            else
                std::cout<<" ";
        }
        std::cout<<std::endl;
    }


}
void revealSpaces(bool isVisible[][MAX_SIZE], char field[][MAX_SIZE], int row, int col, int fieldSize){

    for(int i {-1}; i < 2; i++){
        for(int j {-1}; j < 2; j++){
            if(row + i > 0 && row + i < fieldSize && col + j > 0 && col + j< fieldSize){
                isVisible[row + i][row + j] = true;
            }
        }
    }
}
bool clickedSpace(char field[][MAX_SIZE], bool isVisible[][MAX_SIZE], int row, int col, int fieldSize){

    if(col < 0 || col >= fieldSize || row < 0 || row >= fieldSize)
        return false;
    
    if(field[row][col] == '0'){
        revealSpaces(isVisible, field, row, col, fieldSize);
        clickedSpace(field, isVisible, row + 1, col, fieldSize);
        clickedSpace(field, isVisible, row - 1, col, fieldSize);
        clickedSpace(field, isVisible, row, col + 1, fieldSize);
        clickedSpace(field, isVisible, row, col - 1, fieldSize);
    }
    if(field[row][col] == '*')
        return true;


    return false;

}
void getInput(char* move, int& x, int& y){
    char temporary [60];
    std::cin>>temporary;
    int counter = 1;
    for(size_t i {1}; temporary[i] != ']'; i++){
        move[i-1] = temporary[i];
        counter++;
    }
    x = temporary[counter + 2] - '0';
    y = temporary[counter + 5] - '0';
    
}
bool wonGame(char field[][MAX_SIZE],  bool marked[][MAX_SIZE],  int fieldSize){

    for(int i {0}; i < fieldSize; i++){
        for(int j {0}; j < fieldSize; j++){
            if(field[i][j] == '*' && !marked[i][j])
                return false;
        }
    }
    return true;
}
int controlTurn(char field[][MAX_SIZE], bool isVisible[][MAX_SIZE], bool marked[][MAX_SIZE], int fieldSize, int mineCount, char* move, int& x, int& y){


    drawField(field, isVisible, fieldSize);
    std::cout<<"Enter a command! It should be formatted like this: \n[command][x coordinate][y coordinate]";
    getInput(move, x, y);
    if(x < 0 || x > fieldSize || y < 0 || y > fieldSize)
        return 0;

    bool blewUp = false;
    bool hasWon = false;
    if(move == "open"){
        blewUp = clickedSpace(field, isVisible, x, y, fieldSize);
    }else if(move == "mark"){
        marked[x][y] = true;
        hasWon = wonGame(field, marked, fieldSize);
    }else if(move == "unmark"){
        marked[x][y] = false;
    }

    if(blewUp)
        return -1;
    if(hasWon)
        return 1;

    return 0;
}

void playGame(char field[][MAX_SIZE], bool isVisible[][MAX_SIZE],  bool marked[][MAX_SIZE], int fieldSize, int mineCount){

    char move[60];
    int x, y;
    initializeField(field, fieldSize, mineCount);
    initializeBoolArray(isVisible, fieldSize);
    initializeBoolArray(marked, fieldSize);


    while(true){
        int controler = controlTurn(field, isVisible, marked, fieldSize, mineCount, move, x, y);
        if(controler == -1){
            std::cout<<"You lost! You clicked on a mine";
            return;
        }if(controler == 1){
            std::cout<<"You won! All mines have been successfully located";
            return;
        }
    }
}
void successfulFieldSetup(int& fieldSize, int& mineCount){

    do{
        std::cin>>fieldSize>>mineCount;
    }while(fieldSize < 3 || fieldSize > 10 || mineCount < 1 || mineCount > 3* fieldSize);

}

int main(){
    srand(time(NULL));

    
    int fieldSize, mineCount;
    successfulFieldSetup(fieldSize, mineCount);
    bool marked[MAX_SIZE][MAX_SIZE];
    char field[MAX_SIZE][MAX_SIZE];
    bool isVisible[MAX_SIZE][MAX_SIZE];

    playGame(field, isVisible, marked, fieldSize, mineCount);



    return 0;
}