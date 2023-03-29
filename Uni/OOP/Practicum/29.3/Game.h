#pragma once
#include <string.h>
#include <iostream>

class Game{
private:
    char* title = nullptr;
    unsigned price;
    bool isAvailable;
    
    void free();
    void copyFrom(const Game& other);
public:
    Game() = default;
    Game(const char* title, unsigned price, bool isAvailable);
    ~Game();
    Game(const Game& other);
    Game& operator=(const Game& other);
    void setTitle(const char* title);
    void setPrice(unsigned price);
    void setAvailable(bool isAvailable);
    const char* getTitle() const;
    unsigned getPrice() const;
    bool getAvailable() const;
    void print() const;

};
void swap(Game& game1, Game& game2);
