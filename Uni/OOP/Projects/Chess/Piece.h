#pragma once
#include "Vector.hpp"

class Board;

struct Piece{
protected:
    char col;
    uint8_t row;
    bool color; //White 0, Black 1
};

class Pawn: protected Piece{
public:
    bool canMove(char row, uint8_t col);


};