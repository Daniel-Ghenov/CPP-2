#pragma once
#include"AdminIF\AdminIF.h"
#include"PlayerIF\PlayerIF.h"


class CombinedIF: BaseIF{
private:
    PlayerIF* _playerIF = nullptr;
    AdminIF* _adminIF = nullptr;

public:

    CombinedIF() = default;
    CombinedIF(const CombinedIF& other) = delete;
    CombinedIF(CombinedIF&&) = delete;
    CombinedIF& operator=(const CombinedIF& other) = delete;
    CombinedIF& operator=(CombinedIF&& other) = delete;
    ~CombinedIF();
    void start() override;

private:

    virtual bool logIn() {}
    virtual void printInfo() const {}
    virtual void help() const {}

    void free();
};