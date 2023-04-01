#include <iostream>
#pragma once

int claculateScore(int** field, int fieldSize);
void moveNumberUp(int** field, int fieldSize, int& turnCount, int row, int col);
void moveNumberDown(int** field, int fieldSize, int& turnCount, int row, int col);
void moveNumberLeft(int** field, int fieldSize, int& turnCount, int row, int col);
void moveNumberRight(int** field, int fieldSize, int& turnCount, int row, int col);
void moveUp(int** field, int fieldSize, int& turnCount);
void moveLeft(int** field, int fieldSize, int& turnCount);
void moveDown(int** field, int fieldSize, int& turnCount);
void moveRight(int** field, int fieldSize, int& turnCount);
void moveField(int** field, int fieldSize, int& turnCount, char direction);