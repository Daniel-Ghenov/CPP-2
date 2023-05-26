#pragma once
#include "Vector.hpp"

class Board;

struct Piece{
protected:

    bool _color = false; //White 0, Black 1
    char _row = 'a';
    uint8_t _col = 1;

public: 
    Piece() = default;
    Piece(bool color, char row, uint8_t col);

    virtual bool canMove(char row, uint8_t col) const = 0;
    virtual bool canTake(char row, uint8_t col) const = 0;
    virtual ~Piece() = default;

    void setRow(char row);
    void setCol(uint8_t col);

protected:

    bool isValidRow(char row) const;
    bool isValidCol(uint8_t col) const;
    
    
};
