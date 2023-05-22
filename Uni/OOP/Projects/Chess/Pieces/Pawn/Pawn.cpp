#include "Pawn.h"

bool Pawn::canMove(char row, uint8_t col) const{
    if(!_color){
        if(row == _row + 1 || _row == 1 && row == 3)
            return true;
        else
            return false;
    }else{

        if(row == _row - 1 || _row == 7 && row == 5)
            return true;
        else
            return false;
    }
}
bool Pawn::canTake(char row, uint8_t col) const{

    if(!_color){
        if(row == _row + 1 && (col == _col - 1 || col == _col + 1))
            return true;
        else
            return false;
    }else{

        if(row == _row - 1 && (col == _col - 1 || col == _col + 1))
            return true;
        else
            return false;
    }
}