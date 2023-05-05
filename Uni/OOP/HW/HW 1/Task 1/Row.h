#pragma once
#include "Value.h"
#include "Const.h"
#include "Alignment.h"
#include <string.h>
#include <sstream>

class Row{
private:
    Value values[MAX_COLS];
    size_t colCount = 0;
    
public:
    const char* getValue(size_t) const;
    void setValue(size_t, const char*);
    size_t getCount() const;
    void print(const Alignment*,const size_t*) const;
    void saveToFile(std::ofstream&, const Alignment*,const size_t*) const;
    void readFromFile(std::ifstream&);
    void addValue(const char* value);
};