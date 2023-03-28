#include <iostream>
int claculateScore(int** field, int fieldSize){
    int score = 0;
    for(size_t i {0}; i < fieldSize; i++){
        for(size_t j {0}; j < fieldSize; j++){
            score += field[i][j];
        }
    }
    return score;

}
void moveNumber(int** field, int fieldSize, int& turnCount, char direction, int row, int col){
    if(field[row][col] == 0)        //This function gets called from move Field to control the single number movement
        return;
    bool hasCombined = false;

    switch (direction)
    {
    case 'w':                   
        while(row > 0){
            if(field[row - 1][col] == 0){                   //We check whether the square we want to move to is empty or contains the same number
                field[row - 1][col] += field[row][col];
                field[row][col] = 0;
            }else if(field[row - 1][col] == field[row][col] && !hasCombined){
                field[row - 1][col] += field[row][col];
                field[row][col] = 0;
                hasCombined = true;
            }
            else 
                break;
            row--;
        }
        break;
    case 's':
        while(row + 1 < fieldSize){
            if(field[row + 1][col] == 0){
                field[row + 1][col] += field[row][col];
                field[row][col] = 0;
            }else if( field[row + 1][col] == field[row][col] && !hasCombined){
                field[row + 1][col] += field[row][col];
                field[row][col] = 0;
                hasCombined = true;
            }         
            else 
                break;
            row++;
        }
        break;
    case 'a':
        while(col > 0){
            if(field[row][col - 1] == 0){
                field[row][col - 1] += field[row][col];
                field[row][col] = 0;
            }else if( field[row][col - 1] == field[row][col] && !hasCombined){
                field[row][col - 1] += field[row][col];
                field[row][col] = 0;
                hasCombined = true;
            }
            else 
                break;
            col--;
        }
        break;
    case 'd':
        while(col + 1 < fieldSize){
            if(field[row][col + 1] == 0 ){
                field[row][col + 1] += field[row][col];
                field[row][col] = 0;
            }else if(field[row][col + 1] == field[row][col] && !hasCombined){
                field[row][col + 1] += field[row][col];
                field[row][col] = 0;
                hasCombined = true;                
            }
            else 
                break;
            col++;
        }
        break;
    default:
        break;
    }

}
void moveField(int** field, int fieldSize, int& turnCount, char direction){

    switch (direction){
    case 'w':
        for(size_t i {1}; i < fieldSize; i++){      //We cycle the board in a direction oposite the one we want to move numbers in
            for(size_t j {0}; j < fieldSize; j++){          //Starting from the row/column that is farthest in the direction we want to move in 
                moveNumber(field, fieldSize, turnCount, direction,i, j);               
            }
        }
        break;
    case 'a':
        for(size_t i {0}; i < fieldSize; i++){
            for(size_t j {1}; j < fieldSize; j++){
                moveNumber(field, fieldSize, turnCount, direction,i, j);              
            }
        }
        break;
    case 's':
        for(int i = fieldSize - 2; i >= 0; i--){
            for(size_t j {0}; j < fieldSize; j++){
                moveNumber(field, fieldSize, turnCount, direction,i, j);              
            }
        }
        break;
    case 'd':
        for(size_t i {0}; i < fieldSize; i++){
            for(int j = fieldSize - 2; j >= 0; j--){
                moveNumber(field, fieldSize, turnCount, direction,i, j);              
            }
        }
        break;
    default:
        break;
    }

}