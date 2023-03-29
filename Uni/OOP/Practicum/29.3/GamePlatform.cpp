#include "GamePlatform.h"

void GamePlatform::free(){
    delete[] games;
    games = nullptr;
    maxSize = currSize = 0;
}
void GamePlatform::copyFrom(const GamePlatform& other){
    maxSize = other.maxSize;
    currSize = other.currSize;
    games = new Game[maxSize];
    for(size_t i {0}; i < currSize; i++){
        games[i] = other.games[i];
    }
}

GamePlatform::GamePlatform(const GamePlatform& other){
    copyFrom(other);
}
GamePlatform::GamePlatform(size_t size){
    games = new Game[size];
}
GamePlatform& GamePlatform::operator=(const GamePlatform& other){
    if(this == &other)
        return *this;
    free();
    copyFrom(other);
    return *this;

}
GamePlatform::~GamePlatform(){
    free();
}
void GamePlatform::printGame(size_t index) const {
    if(index > currSize)
        return;
    games[index].print();
}
void GamePlatform::printGameList() const{
    for(size_t i {0}; i < currSize; i++){
        std::cout<<games[i].getTitle()<<std::endl;
    }
}
void GamePlatform::printMostExpensive() const{
    if(games == nullptr)
        return;
    int idx = 0;
    int idxPrice = games[0].getPrice();
    for(size_t i {0}; i < currSize; i++){
        if(games[i].getPrice() > idxPrice){
            idx = i;
            idxPrice = games[idx].getPrice();
        }
    }
    games[idx].print();
}
void GamePlatform::printLeastExpensive() const{
    if(games == nullptr)
        return;
    int idx = 0;
    int idxPrice = games[0].getPrice();
    for(size_t i {0}; i < currSize; i++){
        if(games[i].getPrice() < idxPrice){
            idx = i;
            idxPrice = games[idx].getPrice();
        }
    }
    games[idx].print();
}
void GamePlatform::addGame(const Game& game){
    if(currSize == maxSize)
        return;
    games[currSize++] = game;
}
void GamePlatform::deleteGame(size_t index){
    if(index >= currSize)
        return;
    swap(games[currSize--], games[index]);
}
void swap(Game& game1, Game& game2){
    Game temp = game1;
    game1 = game2;
    game2 = temp;
}