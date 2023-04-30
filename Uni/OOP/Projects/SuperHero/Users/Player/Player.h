#pragma once
#include "User.h"
#include "SuperHero.h"
#include "Vector.hpp"

class Player : public User{
private:
    size_t _money = 0;
    Vector<SuperHero> _heroes;

public:
    Player() = default;
    Player(size_t money, Vector<SuperHero> heroes);

    void addHero(SuperHero&& other);
    void addHero(const SuperHero& other);

    size_t money() const;

    void print() const;
};