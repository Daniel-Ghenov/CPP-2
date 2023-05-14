#pragma once
#include "BaseIF\BaseIF.h"
#include "System\Const.h"

class PlayerIF: BaseIF{
private:
    Player* _player = nullptr;
public:
    PlayerIF() = default;
    PlayerIF(const PlayerIF& other) = delete;
    PlayerIF(PlayerIF&&) = delete;
    PlayerIF& operator=(const PlayerIF& other) = delete;
    PlayerIF& operator=(PlayerIF&& other) = delete;

    void start() override;

private:

    void deleteAcc();
    void printInfo() const override;
    void printScoreboard();
    void attack();
    void shop();
    void buy();
    void changeStance();
    bool logIn() override;

    void help() const override;

};