#include "Game.h"

void Game::free(){
    delete[] title;
    title = nullptr;
}
void Game::copyFrom(const Game& other){
    title = new char[strlen(other.title) + 1];
    strcpy(title, other.title);
    price = other.price;
    isAvailable = other.isAvailable;
}

Game::Game(const char* title, unsigned price, bool isAvailable){
    strcpy(this->title, title);
    this->price = price;
    this->isAvailable = isAvailable;
}
Game::~Game(){
    free();
}
Game::Game(const Game& other){
    copyFrom(other);
}
Game& Game::operator=(const Game& other){
    if(this == &other)
        return *this;

    free();
    copyFrom(other);
    return *this;
}
void Game::setTitle(const char* title){
    free();
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
}
void Game::setPrice(unsigned price){
    this-> price = price;
}
void Game::setAvailable(bool isAvailable){
    this->isAvailable = isAvailable;
}
const char* Game::getTitle() const{
    return title;
}
unsigned Game::getPrice() const{
    return price;
}
bool Game::getAvailable() const{
    return isAvailable;
}
void Game::print() const{
    std::cout<<title<<", "<<price<<", "<<isAvailable;
}