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
    Table() = default;

    void print() const;
    const Row& getRow(size_t index) const;
    void changeColName(const char* oldName, const char* name);
    void setNames(const Row&);
    void addRow(const Row&);
    void changeValue(size_t rowNum, const char* colName, const char* val);
    void changeValue(const char* colName, const char* oldVal, const char* newVal);
    void selectRows(const char* colName, const char* val) const;
    void saveToFile(std::ofstream& outFile) const;
    void readFromFile(std::ifstream& inFile);
    int getRowCount() const;
    void setRowCount(size_t num);
    // void setColCount(size_t num);
    // size_t getColCount() const;
    // void setAlignments(const Alignment* align);
    // const Alignment* getAlignments() const;

};
