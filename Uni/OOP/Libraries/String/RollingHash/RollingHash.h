#pragma once
#include "Const.h"
#include "Helper.h"
#include <cmath>

class RollingHash{
private:
    size_t hash = 0;
    const size_t strLen = 0;
    const size_t primeFac = 0;

public:
    RollingHash(const char* string, size_t size = 0);

    size_t getHash();

    void push_front(char newChar);
    void pop_back();

    bool operator ==(const RollingHash& other);
private:
    size_t getPrime(size_t number);
};