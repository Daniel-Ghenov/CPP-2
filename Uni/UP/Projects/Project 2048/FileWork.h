#pragma once

bool stringCompare(const char* array1, const char* array2);
int copyString(char* to, const char* from, int position);
char* getFileName(int fieldSize);
void insertNickname(char** nicknameList, char* nickname, int score, int* scoreList, int place);
char** getLeaderboard(int fieldSize, char* filename, int* scoreList);
void checkLeaderboard(char** nicknameList, int score, int* scoreList, char* nickname);
void writeToFile(char** nicknameList, char* filename, int* scoreList);
void setLeaderboard(int fieldSize, int score, char* nickname);
void printLeaderboard();
void deleteArray(int** array, int size);