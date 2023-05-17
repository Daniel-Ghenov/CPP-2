#pragma once
#include "../AdminIF\AdminIF.h"
#include "../PlayerIF\PlayerIF.h"


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
    ~CombinedIF() override;
    void start() override;

private:

    void free();
};