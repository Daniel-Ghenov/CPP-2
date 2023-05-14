#pragma once
#include "Base\User.h"
#include "SuperHero.h"
#include "System\Const.h"
#include "Vector.hpp"

class Player : public User{
private:
    size_t _money = START_MONEY;
    Vector<SuperHero*> _heroes;

public:
    Player() = default;
    Player(const String& firstName, const String& lastName, const String& email, const char* username, const String& password, size_t money, Vector<SuperHero*> heroes);
    ~Player();
    Player(const Player& other);
    Player(Player&& other);
    Player& operator=(const Player& other);
    Player& operator=(Player&& other);


    void addHero(SuperHero* other);
    size_t findHero(const String& heroName);
    void removeHero(const SuperHero* hero);
    void changeStance(const String& heroName);

    size_t money() const;
    size_t setMoney(size_t money);
    const Vector<SuperHero*>& heroes() const;

    void print() const;
    void adminPrint() const;

    void saveToBinary(std::ofstream& ofs) const;
    void loadFromBinary(std::ifstream& ifs);

private:
    void copyFrom(const Player& other);
    void move(Player&& other);
    void free();



};