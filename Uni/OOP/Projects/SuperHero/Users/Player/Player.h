#pragma once
#include "Base\User.h"
#include "SuperHero.h"
#include "System\Const.h"
#include "Vector.hpp"

class Player : public User{
private:
    size_t _money = START_MONEY;
    Vector<SuperHero> _heroes;

public:
    Player() = default;
    Player(size_t money, Vector<SuperHero> heroes);

    void addHero(SuperHero&& other);
    void addHero(const SuperHero& other);

    void removeHero(const SuperHero* hero);

    void attack(const SuperHero* first, const SuperHero* second, Player* other);
    size_t money() const;

    void print() const;
    void adminPrint() const;

    void saveToBinary(std::ofstream& ofs) const;
    void loadFromBinary(std::ifstream& ifs);

    friend class System;
};