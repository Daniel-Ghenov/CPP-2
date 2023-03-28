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
void moveNumberUp(int** field, int fieldSize, int& turnCount, int row, int col){
    bool hasCombined = false;
    while(row > 0){
        if(field[row - 1][col] == 0){
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
}
void moveNumberDown(int** field, int fieldSize, int& turnCount, int row, int col){
    bool hasCombined = false;
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
}
void moveNumberLeft(int** field, int fieldSize, int& turnCount, int row, int col){
    bool hasCombined = false;
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
}
void moveNumberRight(int** field, int fieldSize, int& turnCount, int row, int col){
    bool hasCombined = false;
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
}
void moveNumber(int** field, int fieldSize, int& turnCount, char direction, int row, int col){ 
    if(field[row][col] == 0)        //This function gets called from move Field to control the single number movement
        return;

    switch (direction)
    {
    case 'w':                   
        moveNumberUp(field, fieldSize, turnCount, row, col);
        break;
    case 's':
        moveNumberDown(field, fieldSize, turnCount, row, col);
        break;
    case 'a':
        moveNumberLeft(field, fieldSize, turnCount, row, col);
        break;
    case 'd':
        moveNumberRight(field, fieldSize, turnCount, row, col);
        break;
    default:
        break;
    }

}
void moveUp(int** field, int fieldSize, int& turnCount){
    for(size_t i {1}; i < fieldSize; i++){
        for(size_t j {0}; j < fieldSize; j++){
            moveNumber(field, fieldSize, turnCount, 'w' ,i, j);
        }
    }
}
void moveLeft(int** field, int fieldSize, int& turnCount){
    for(size_t i {0}; i < fieldSize; i++){
        for(size_t j {1}; j < fieldSize; j++){
            moveNumber(field, fieldSize, turnCount, 'a',i, j);              
        }
    }
}
void moveDown(int** field, int fieldSize, int& turnCount){
    for(int i = fieldSize - 2; i >= 0; i--){
        for(size_t j {0}; j < fieldSize; j++){
            moveNumber(field, fieldSize, turnCount, 's',i, j);              
        }
    }
}
void moveRight(int** field, int fieldSize, int& turnCount){
        for(size_t i {0}; i < fieldSize; i++){
            for(int j = fieldSize - 2; j >= 0; j--){
                moveNumber(field, fieldSize, turnCount, 'd',i, j);              
            }
        }
}
void moveField(int** field, int fieldSize, int& turnCount, char direction){


    switch (direction){
    case 'w':
        moveUp(field, fieldSize, turnCount);
        break;
    case 'a':
        moveLeft(field, fieldSize, turnCount);
        break;
    case 's':
        moveDown(field, fieldSize, turnCount);
        break;
    case 'd':
        moveRight(field, fieldSize, turnCount);
        break;
    default:
        break;
    }

}