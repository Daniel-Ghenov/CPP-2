#include <iostream>
#include <fstream>
#include "Math.h"
#include "Input.h"

const int LINE_MAX_SIZE = 120;
const int LEADERBOARD_LENGTH = 5;
const int MAX_INTAGER_LENGTH = 7;
const int MAX_FILENAME_LENGTH = 23;

char* intToChar(int a){
    int alength = len(a);   //A function to help us put the score into a char array
    char* array = new char[MAX_INTAGER_LENGTH]();
    for(size_t i{0} ; i < alength; i++){
        array[i] = a / pow(10, len(a) - 1) + '0';
        a %= pow(10, len(a) - 1);
    }
    array[alength] = '\0';
    return array;
}
void addNewline(char* line){
    for(size_t i {0}; i < LINE_MAX_SIZE - 1; i++){  //A function to add a newline to the end of lines
        if(line[i] == '\0'){                        //Since after reading them from the file the \n is lost
            line[i] = '\n';
            line[i + 1] = '\0';
            break;
        }
    }
}
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
bool scoreCompare(const char* line,const char* score){
    for(size_t i {5}; i > 0; i--){
        if(line[4 + i] == ' ' && score[i] != '\0')
            return true;
        else if(line[4 + i] != ' ' && score[i] == '\0')
            return false;
        else if(line[4 + i] != ' ' && score[i] != '\0')
            break;
    }

    for(size_t i {0}; i < 5; i++){                  //We compare our score to that of a line
        if(line[4 + i] == ' ' && score[i] != '\0')  //The way the scoreboard is set up the score starts from the 4th place of each line
            return true;
        if(line[4 + i] == ' ' && score[i] == '\0')
            return false;
        if(score[i] < line[4 + i])
            return false;
        if(score[i] > line[4 + i])
            return true;
    }
    return false;
}
void createNewLine(char* line, const char* nickname,const char* score, int place){
    for(size_t i {0}; i < LINE_MAX_SIZE; i++){          //This function is used to construct a new line with our score and nickname
        line[i] = ' ';
    }
    line[0] = place + '1';
    line[1] = ':';                  
    copyString(line, score, 3);
    copyString(line, "Nickname:", 10);
    int endLine = copyString(line, nickname, 20);    
    line[endLine + 1] = '\n';
    line[endLine + 2] = '\0';
}
void insertLine(char** leaderboard, char* nickname, char* score, int place){
    for(int i = LEADERBOARD_LENGTH - 2; i > place - 1;i--){     //We move the lines down and then create a new one in the open spot
        if(leaderboard[i][0] != ' '){
            copyString(leaderboard[i + 1],leaderboard[i], -1);
            leaderboard[i + 1][0] += 1;
            addNewline(leaderboard[i + 1]);
        }
    }
    createNewLine(leaderboard[place], nickname, score, place);
}
char* getFileName(int fieldSize){
    char* filename = new char[MAX_FILENAME_LENGTH];
    switch (fieldSize){ 
    case 4:
        copyString(filename, "Leaderboard/4x4.txt", -1);
        break;
    case 5:
        copyString(filename, "Leaderboard/5x5.txt", -1);
        break;
    case 6:
        copyString(filename, "Leaderboard/6x6.txt", -1);
        break;
    case 7:
        copyString(filename, "Leaderboard/7x7.txt", -1);
        break;
    case 8:
        copyString(filename, "Leaderboard/8x8.txt", -1);
        break;
    case 9:
        copyString(filename, "Leaderboard/9x9.txt", -1);
        break;
    default:
        copyString(filename, "Leaderboard/10x10.txt", -1);
        break;
    }
    return filename;
}
char** getLeaderboard(int fieldSize, char* filename){
    std::ifstream inputFile;
    inputFile.open(filename);

    if(!inputFile.is_open()){
        return nullptr;
    }
        
    char** leaderboard = new char* [LEADERBOARD_LENGTH];
    for(size_t i {0}; i < LEADERBOARD_LENGTH; i++){    //We initialize the leaderboard as an array of pointers
        leaderboard[i] = new char [LINE_MAX_SIZE];     //and initialize them to point to arrays of chars
        for(size_t j {0}; j < LINE_MAX_SIZE; j++){     //for ease of use the leaderboards are initialized with spaces
            leaderboard[i][j] = ' ';
        }
    }

    for(size_t i {0};!inputFile.eof() && i < LEADERBOARD_LENGTH; i++){
        inputFile.getline(leaderboard[i], LINE_MAX_SIZE);
        addNewline(leaderboard[i]);
    }
    inputFile.close();
    return leaderboard;
}
void checkLeaderboard(char** leaderboard, char* score, char* nickname){

    for(int i {0}; i < LEADERBOARD_LENGTH; i++){
        if(leaderboard[i][0] == ' ' || leaderboard[i][0] == '\0'){  //We check the scoreboard to see whether we need to place 
            createNewLine(leaderboard[i], nickname, score, i);      //our new score on it
            break;
        }else if(scoreCompare(leaderboard[i], score)){
            insertLine(leaderboard, nickname, score, i);
            break;
        }
    }
}
void writeToFile(char** leaderboard, char* filename){
    std::ofstream outputFile;
    outputFile.open(filename, std::fstream::trunc); //We paste the updated leaderboard into the file

    for(size_t i {0}; i < LEADERBOARD_LENGTH; i++){
        if(leaderboard[i][0] != ' ' || '\0')
            outputFile << leaderboard[i];
    }
    outputFile.close();
}
void setLeaderboard(int fieldSize, int score, char* nickname){
    char* filename = getFileName(fieldSize);
    char* cScore = intToChar(score);
    char** leaderboard = getLeaderboard(fieldSize, filename);
    checkLeaderboard(leaderboard, cScore, nickname);
    writeToFile(leaderboard, filename);
    delete[] filename;
    delete[] cScore;
    deleteArray(leaderboard, LEADERBOARD_LENGTH);

}
void printLeaderboard(){
    int fieldSize;
    std::cout<<"What size board do you want the leaderboard for?: ";
    std::cin>>fieldSize;
    char* filename = getFileName(fieldSize);
    char** leaderboard = getLeaderboard(fieldSize, filename);
    if(leaderboard == nullptr)
        return;
    std::cout<<std::endl;
    for(size_t i {0}; i < LEADERBOARD_LENGTH; i++){
        if(leaderboard[i][0] != ' ' && leaderboard[i][0] != '\0')
            std::cout<<leaderboard[i];
        else 
            break;
    }
    std::cout<<std::endl;
    delete[] filename;
    deleteArray(leaderboard, LEADERBOARD_LENGTH);
}