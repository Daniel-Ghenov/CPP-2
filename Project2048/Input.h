#pragma once

char getInput();
char* getMainMenuInput();
char* getNickname();
int** initializeArray(int& fieldSize);
void deleteArray(int** array, int size);
void deleteArray(char** array, int size);