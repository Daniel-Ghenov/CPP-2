#pragma once
#include "../Basic\Piece.h"


class Pawn: public Piece{
public:
    bool canMove(char row, uint8_t col) const override;
    bool canTake(char row, uint8_t col) const override;


};