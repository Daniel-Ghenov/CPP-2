#pragma once
#include "Vector.hpp"
#include "Admin.h"
#include "Player.h"

class System{
private:
    Vector<Admin*> _admins;
    Vector<Player*> _players;
public:
    System();
    System(const Admin& admin);
    ~System();

    void addPlayer(const Player& player);
    void addAdmin(const Admin& admin);
    void addPlayer(Player&& player);
    void addAdmin(Admin&& admin);

};