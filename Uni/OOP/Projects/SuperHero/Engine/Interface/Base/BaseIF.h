#pragma once
#include "System\System.h"

class BaseIF{
protected:
    System* _sys = nullptr;
public:
    BaseIF() = default;
    BaseIF(System* ptr);
    BaseIF(const BaseIF& other) = delete;
    BaseIF(BaseIF&& other);
    BaseIF& operator=(const BaseIF& other) = delete;
    BaseIF& operator=(BaseIF&& other) = delete;

    System* sys();
};