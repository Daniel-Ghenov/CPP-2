#pragma once
#include "../AdminIF\AdminIF.h"
#include "../PlayerIF\PlayerIF.h"


class CombinedIF: BaseIF{
private:
    SharedPtr<PlayerIF> _playerIF = nullptr;
    SharedPtr<AdminIF> _adminIF = nullptr;

public:

    CombinedIF() = default;
    CombinedIF(const CombinedIF& other) = delete;
    CombinedIF(CombinedIF&&) = delete;
    CombinedIF& operator=(const CombinedIF& other) = delete;
    CombinedIF& operator=(CombinedIF&& other) = delete;
    void start() override;

private:

};