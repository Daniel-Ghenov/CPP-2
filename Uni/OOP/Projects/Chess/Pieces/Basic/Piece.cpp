#include "Piece.h"


Piece::Piece(bool color, char row, uint8_t col): _color(color){
    setRow(row);
    setCol(col);
}


bool Piece::isValidRow(char row) const{
    return(row >= 'a' && row <= 'h');
}
bool Piece::isValidCol(uint8_t col) const{
    return(col <= 8 && col != 0);

}


void Piece::setRow(char row){
    if(!isValidCol(row))
        throw std::logic_error("Invalid Row");
    
    _row = row;
}
void Piece::setCol(uint8_t col){
    if(!isValidCol(col))
        throw std::logic_error("Invalid Col");
    
    _col = col;
}