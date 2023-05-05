#pragma once

#include <iostream>
#include <string.h>
#include <fstream>
#include "Const.h"
#include "Alignment.h"

struct Value{
private:
    char val[MAX_VALUE_LEN] = "\0";
    void getSpaces(Alignment, size_t, size_t, int&, int&) const;
    void removeSpaces();
public:
    Value() = default;
    Value( const char*);
    void setVal(const char*);
    const char* getVal() const;
    void print(Alignment, size_t) const;
    void saveToFile(std::ofstream&, Alignment, size_t) const;
    void readFromFile(std::ifstream&);
};