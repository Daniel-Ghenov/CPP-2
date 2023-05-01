#pragma once
#include "Vector.hpp"
#include "Admin.h"
#include "Player.h"

class System{
private:
    Vector<Admin*> _admins; 
    Vector<Player*> _players;   //Hash map??
    Vector<SuperHero*> _shop;
    
public:
    System();
    System(const Admin& admin);
    ~System();

    void addPlayer(const Player& player);
    void addAdmin(const Admin& admin);
    void addHero(const SuperHero& hero);

    void removePlayer(size_t index);
    void removeAdmin(size_t index);
    void removeHero(size_t index);

    size_t findPlayer(const String& username) const;
    size_t findAdmin(const String& username) const;
    size_t findHero(const String& username) const;

};