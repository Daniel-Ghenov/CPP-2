#pragma once
#include <cmath>
#include <time.h>

int pow(int a, int b);
int len(int a);
bool isEmptySpace(int** field, int fieldSize);
void addRandomNumber(int** field, int* randomWeight, int fieldSize, int& turnCount);
bool arePossibleMoves(int** field, int fieldSize);