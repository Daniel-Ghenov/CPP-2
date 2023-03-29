#pragma once
#include "Game.h"

class GamePlatform{
public:
    Game* games = nullptr;
    size_t maxSize = 0;
    size_t currSize = 0;

    void free();
    void copyFrom(const GamePlatform& other);
private:
    GamePlatform() = default;
    GamePlatform(size_t size);
    GamePlatform(const GamePlatform& other);
    GamePlatform& operator=(const GamePlatform& other);

    ~GamePlatform();
    
    void printGame(size_t index) const;
    void printGameList() const;
    void printMostExpensive() const;
    void printLeastExpensive() const;
    void addGame(const Game& game);
    void deleteGame(size_t index);
};