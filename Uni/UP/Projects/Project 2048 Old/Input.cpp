#include <iostream>
#include "Constants.h"

char getInput(){
    char direction;
    std::cin>>direction;
    return direction;
}
char* getMainMenuInput(){
    char* input = new char[MAX_USER_INPUT];
    std::cout<<"1. Start game\n2. Leaderboard\n3. Quit\n";
    while(std::cin.peek() == '\n'){
        std::cin.ignore();
    }
    std::cin.getline(input, MAX_USER_INPUT);

    return input;
}
char* getNickname(){
    char* nickname = new char[MAX_USER_INPUT];
    std::cout<<"\n Enter a nickname: ";
	std::cin.sync();
    std::cin.getline(nickname, MAX_USER_INPUT);
    return nickname;
}
int** initializeArray(int& fieldSize){

    do{
        std::cout<<"What size board do you want to play on?: ";
        std::cin>>fieldSize;
        std::cin.clear();
    }while(fieldSize < 4 || fieldSize > 10);
    int** field = new int*[fieldSize];

    for(size_t i {0}; i < fieldSize; i++){
        field[i] = new int[fieldSize]();    //Using braced initialization we get all of the elements in the array to be set to 0
    }

    return field;
}
void deleteArray(int** array, int size){

    for(size_t i {0}; i < size; i++){
        delete[] array[i];
    }
    delete[] array;
}
void deleteArray(char** array, int size){
    for(size_t i {0}; i < size; i++){
        delete[] array[i];
    }
    delete[] array;
}