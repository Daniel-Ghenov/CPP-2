#include <iostream>
#include <fstream>
#include "Math.h"
#include "Input.h"
#include "Constants.h"


bool stringCompare(const char* array1, const char* array2){

    for(size_t i {0};;i++){
        if(array1[i] == '\0' && array2[i] == '\0'){
            return true;
        }else if(array1[i] != array2[i])
            return false;
    }

}
int copyString(char* to, const char* from, int position){

    int i = 0;
    while(from[i] != '\0' && from[i] != '\n'){
        to[position + i] = from[i++];
    }
    if(position == -1){                //The only time we need to add a \0 at the end is when we are starting from the beginning of the array
        to[position + i + 1] = '\0';
    }
    return i + position;
}
char* getFileName(int fieldSize){

    char* filename = new char[MAX_FILENAME_LENGTH];
    switch (fieldSize){ 
    case 4:
        copyString(filename, "Leaderboard/4x4.txt", LINE_START);
        break;
    case 5:
        copyString(filename, "Leaderboard/5x5.txt", LINE_START);
        break;
    case 6:
        copyString(filename, "Leaderboard/6x6.txt", LINE_START);
        break;
    case 7:
        copyString(filename, "Leaderboard/7x7.txt", LINE_START);
        break;
    case 8:
        copyString(filename, "Leaderboard/8x8.txt", LINE_START);
        break;
    case 9:
        copyString(filename, "Leaderboard/9x9.txt", LINE_START);
        break;
    default:
        copyString(filename, "Leaderboard/10x10.txt", LINE_START);
        break;
    }
    return filename;
}
void insertNickname(char** nicknameList, char* nickname, int score, int* scoreList, int place){

    for(int i = LEADERBOARD_LENGTH - 2; i > place - 1;i--){     //We move the lines down and then create a new one in the open spot
        copyString(nicknameList[i + 1],nicknameList[i], -1);
        int temp = scoreList[i];
        scoreList[i] = scoreList[i + 1];
        scoreList[i + 1] = temp;
    }
    scoreList[place] = score;
    copyString(nicknameList[place], nickname, LINE_START);
}
char** getLeaderboard(int fieldSize, char* filename, int* scoreList){

    std::ifstream inputFile(filename);



    char** nicknameList = new char* [LEADERBOARD_LENGTH];


    for(size_t i {0}; i < LEADERBOARD_LENGTH; i++){    //We initialize the nicknameList as an array of pointers
        nicknameList[i] = new char [MAX_USER_INPUT]();     //and initialize them to point to arrays of chars
    }
    if(!inputFile.is_open()){
        return nicknameList;
    }
    for(size_t i {0};!inputFile.eof() && i < LEADERBOARD_LENGTH; i++){
        inputFile.getline(nicknameList[i], MAX_USER_INPUT, ' ');
        inputFile>> scoreList[i];
        inputFile.ignore();
    }

    inputFile.close();
    return nicknameList;
}
void checkLeaderboard(char** nicknameList, int score, int* scoreList, char* nickname){

    for(int i {0}; i < LEADERBOARD_LENGTH; i++){
        if(score >= scoreList[i]){
            insertNickname(nicknameList, nickname, score, scoreList, i);
            break;
        }
    }

}
void writeToFile(char** nicknameList, char* filename, int* scoreList){

    std::ofstream outputFile;
    outputFile.open(filename, std::fstream::trunc); //We paste the updated leaderboard into the file

    if(!outputFile.is_open()){
        return;
    }

    for(size_t i {0}; i < LEADERBOARD_LENGTH; i++){
        if(scoreList[i] != 0)
            outputFile << nicknameList[i]<<' '<< scoreList[i]<<' ';
    }
    outputFile.close();
}
void setLeaderboard(int fieldSize, int score, char* nickname){   

    char* filename = getFileName(fieldSize);
    int* scoreList = new int[LEADERBOARD_LENGTH]();
    char** nicknameList = getLeaderboard(fieldSize, filename, scoreList);
    checkLeaderboard(nicknameList,score, scoreList, nickname);
    writeToFile(nicknameList, filename, scoreList);
    delete[] filename;
    deleteArray(nicknameList, LEADERBOARD_LENGTH);
}
void printLeaderboard(){
    int fieldSize;
    std::cout<<"What size board do you want the leaderboard for?: ";
    std::cin>>fieldSize;
    char* filename = getFileName(fieldSize);
    int* scoreList = new int[LEADERBOARD_LENGTH]();
    char** nicknameList = getLeaderboard(fieldSize, filename, scoreList);

    if(nicknameList == nullptr)
        return;

    std::cout<<std::endl;

    for(size_t i {0}; i < LEADERBOARD_LENGTH; i++){
        if(scoreList[i] != 0)
            std::cout<<i + 1<<":  "<<scoreList[i]<<"  Nickname: "<<nicknameList[i]<<std::endl;
        else 
            break;
    }
    std::cout<<std::endl;

    delete[] filename;
    deleteArray(nicknameList, LEADERBOARD_LENGTH);
}