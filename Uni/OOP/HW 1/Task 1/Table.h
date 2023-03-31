#pragma once

#include "Row.h"
#include "Alignment.h"


class Table{
private:
    Row names;
    Alignment alignments[MAX_COLS];
    Row rows[MAX_ROWS];
    size_t widths[MAX_ROWS];
    size_t rowCount = 0;
    size_t colCount = 0;
    
    int getCol(const char*) const;
    void printAlign() const;
    void saveAlign(std::ofstream&) const;
    void getAlign(std::ifstream&);
    void setWidths();
    void setWidth(size_t);
    void setAlignment(Alignment&, bool, bool) const ;
public:
    void print() const;
    const Row& getRow(size_t) const;
    void changeColName(size_t, const char*);
    void setNames(const Row&);
    void addRow(const Row&);
    void changeValue(size_t, const char*, const char*);
    void changeValue(const char*, const char*, const char*);
    void selectRows(const char*, const char*) const;
    void saveToFile(std::ofstream&) const;
    void readFromFile(std::ifstream&);

};
