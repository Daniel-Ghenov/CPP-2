#pragma once

char* intToChar(int a);
void addNewline(char* line);
bool stringCompare(const char* array1, const char* array2);
int copyString(char* to, const char* from, int position);
bool scoreCompare(char* line, char* score);
void createNewLine(char* line, const char* nickname,const char* score, int place);
void insertLine(char** leaderboard, char* nickname, char* score, int place);
char* getFileName(int fieldSize);
char** getLeaderboard(int fieldSize, char* filename);
void checkLeaderboard(char** leaderboard, char* score, char* nickname);
void writeToFile(char** leaderboard, char* filename);
void setLeaderboard(int fieldSize, int score, char* nickname);
void printLeaderboard();