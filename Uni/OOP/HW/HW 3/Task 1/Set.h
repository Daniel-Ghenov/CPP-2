#pragma once
#include <iostream>

class Set{
public:
    virtual ~Set() = default;
    virtual bool contains(uint32_t number) const = 0;


};