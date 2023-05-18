#pragma once
#include "..\Base\User.h"
#include "../../SuperHero\SuperHero.h"
#include "../../../Engine\Helper\Vector\Vector.hpp"
#include "../../../Engine\Helper\Smart Pointer\SharedPtr.hpp"

const int START_MONEY = 1000;

class Player : public User{
private:
    size_t _money = START_MONEY;
    Vector<SharedPtr<SuperHero>> _heroes;

public:
    Player() = default;
    Player(const String& firstName, const String& lastName, const String& email, const char* username, const String& password, size_t money, Vector<SharedPtr<SuperHero>> heroes);

    void addHero(SharedPtr<SuperHero>& other);
    size_t findHero(const String& heroName);
    void removeHero(const SharedPtr<SuperHero>& hero);
    void changeStance(const String& heroName);

    size_t money() const;
    void setMoney(size_t money);
    const Vector<SharedPtr<SuperHero>>& heroes() const;

    void print() const override;
    void adminPrint() const override;

    void saveToBinary(std::ofstream& ofs) const override;
    void loadFromBinary(std::ifstream& ifs) override;

private:



};