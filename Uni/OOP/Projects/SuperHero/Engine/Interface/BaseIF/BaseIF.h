#pragma once
#include "System\System.h"

class BaseIF{
public:
    BaseIF() = default;
    BaseIF(const BaseIF& other) = delete;
    BaseIF& operator=(const BaseIF& other) = delete;
    BaseIF& operator=(BaseIF&& other) = delete;
    virtual ~BaseIF() = default;

    virtual bool logIn() = 0;
    virtual void printInfo() const = 0;
    virtual void start() = 0;
    virtual void help() const = 0;
};