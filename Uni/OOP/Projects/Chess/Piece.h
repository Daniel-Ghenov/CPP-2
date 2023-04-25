#pragma once
#include "Vector.hpp"

class Piece{
protected:
    char col;
    uint8_t row;

    const static char** moveList;

    bool canMove(char col, uint8_t row);
public:

    void move(char col, uint8_t row);


};