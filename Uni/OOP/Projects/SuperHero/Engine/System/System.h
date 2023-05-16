#pragma once
#include <random>
#include "../Helper\Vector\Vector.hpp"
#include "../../Game Element\Users\Admin\Admin.h"
#include "../../Game Element\Users\Player\Player.h"
#include "Const.h"

class System{
private:
    Vector<Admin*> _admins;     
    Vector<Player*> _players;
    Vector<SuperHero*> _shop;
    Vector<SuperHero*> _graveyard;
    Player* _cycleStart = nullptr;

    System(); //Singleton class (no more than one is able to exist)
    ~System();
    System(const System& other) = delete;
    System(System&& other) = delete;
    System& operator=(const System& other) = delete;
    System& operator=(System&& other) = delete;

    static System* instance;

public:


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
    void printGraveyard() const noexcept;
    void printShop() const noexcept;

    Player* logInPlayer(const char* username, const String& password);
    Admin* logInAdmin(const char* username, const String& password);

    

    void attack(const char* attackerUN, const String& attackerHeroName , const char* deffenderUsername, const String& deffendHeroName);
    void buy(const char* buyerUN, const String& heroName);
    void changeStance(const char* playerUN,const String& heroName);

    static System* getSystem();

    void free();


private:

    void saveToBinary(std::ofstream& ofs) const;
    void loadFromBinary(std::ifstream& ifs);
    void endCycle();

    void removeHero(size_t index);
    void sortPlayers();
};