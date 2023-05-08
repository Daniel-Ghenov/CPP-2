#pragma once
#include "Vector.hpp"
#include "Admin.h"
#include "Player.h"

class System{
private:
    Vector<Admin*> _admins; 
    Vector<Player*> _players;
    Vector<SuperHero*> _shop;
    Player* _cycleStart = nullptr;
    
public:
    System();
    System(const Admin& admin);
    ~System();
    System(const System& other) = delete;
    System& operator=(const System& other) = delete;

    void addPlayer(const Player& player);
    void addAdmin(const Admin& admin);
    void addHero(const SuperHero& hero);

    void removePlayer(size_t index);
    void removeAdmin(size_t index);
    void removeHero(size_t index);

    size_t findPlayer(const char* username) const;
    size_t findAdmin(const char* username) const;
    size_t findHero(const String& heroName) const;

    void printInfo(const char* username) const;
    void printAdminInfo(const char* username) const;
    void printScoreboard();

    bool emptyShop() const;

    Player* logInPlayer(const char* username, const String& password);
    Admin* logInAdmin(const char* username, const String& password);

    
    void saveToBinary(std::ofstream& ofs) const;
    void loadFromBinary(std::ifstream& ifs);

    void endCycle();

private:
    void sortPlayers();
    void free();
};