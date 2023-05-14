#pragma once
#include <random>
#include "Vector.hpp"
#include "Admin.h"
#include "Player.h"

class System{
private:
    Vector<Admin*> _admins;     
    Vector<Player*> _players;
    Vector<SuperHero*> _shop;
    Vector<SuperHero*> _graveyard;
    Player* _cycleStart = nullptr;

    static size_t _copies;  //Singleton class (no more than one is able to exist)
    
public:
    System();
    System(const Admin& admin);
    ~System();
private:
    System(std::ifstream& ifs);
    System(const System& other) = delete;
    System(System&& other) = delete;
    System& operator=(const System& other) = delete;
    System& operator=(System&& other) = delete;

    void addPlayer(const Player& player);
    void addAdmin(const Admin& admin);
    void addHero(const SuperHero& hero);
    void addHero(SuperHero&& hero);
    void returnHero(size_t index);  //return from graveyard

    void removePlayer(const char* username);
    void removeAdmin(const char* username);


    size_t findPlayer(const char* username) const;
    size_t findAdmin(const char* username) const;
    size_t findHero(const String& heroName) const;

    void printInfo(const char* username) const;
    void printAdminInfo(const char* username) const;
    void printScoreboard();
    void printGraveyard() const;

    Player* logInPlayer(const char* username, const String& password);
    Admin* logInAdmin(const char* username, const String& password);

    

    void attack(Player* attacker,SuperHero* attackHero, Player* deffender, SuperHero* deffendHero = nullptr);
    void buy(Player* buyer, const String& heroName);
    
    void saveToBinary(std::ofstream& ofs) const;
    void loadFromBinary(std::ifstream& ifs);
    void endCycle();

    void removeHero(size_t index);
    void sortPlayers();
    void free();

    friend class BaseIF;
    friend class AdminIF;
};