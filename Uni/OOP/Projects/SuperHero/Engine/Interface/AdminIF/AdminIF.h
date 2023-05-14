#pragma once
#include "BaseIF\BaseIF.h"
#include "System\Const.h"

class AdminIF: BaseIF{
private:
    Admin* _admin = nullptr;
public:
    AdminIF() = default;
    AdminIF(const AdminIF& other) = delete;
    AdminIF(AdminIF&&) = delete;
    AdminIF& operator=(const AdminIF& other) = delete;
    AdminIF& operator=(AdminIF&& other) = delete;

    void start() override;

private:
    void addPlayer();
    void addAdmin();
    void removePlayer();
    void printInfo() const override;
    void addHero();
    void returnHero();
    bool logIn() override;

    void help() const override;
    void printGraveyard() const;

};