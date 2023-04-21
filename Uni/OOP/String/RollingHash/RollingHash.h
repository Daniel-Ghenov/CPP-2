#pragma once
#include "Const.h"
#include "Helper.h"
#include <cmath>

class RollingHash{
private:
    size_t hash = 0;
    

public:
    RollingHash() = default;
    RollingHash(const char* string, size_t size = 0);

    size_t getHash();

    void push_front(char newChar);
    void pop_back();

    bool operator ==(const RollingHash& other);

};