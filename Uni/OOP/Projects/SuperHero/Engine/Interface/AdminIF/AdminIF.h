#pragma once
#include "../BaseIF\BaseIF.h"

static const int STARTUP_HERO_ADD = 3;

class AdminIF: BaseIF{
private:
    SharedPtr<Admin> _admin = nullptr;
public:
    AdminIF() = default;
    AdminIF(const AdminIF& other) = delete;
    AdminIF(AdminIF&&) = delete;
    AdminIF& operator=(const AdminIF& other) = delete;
    AdminIF& operator=(AdminIF&& other) = delete;

    void start() override;

private:
    bool addPlayer();
    bool addAdmin();
    bool removePlayer();
    bool printInfo() const;
    bool addHero();
    bool returnHero();
    bool logIn();
    void shop();


    void help() const;
    void printGraveyard() const;

};