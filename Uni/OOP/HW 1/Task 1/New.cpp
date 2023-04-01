#include <iostream>
#include <fstream>
#include "Table.h"


int main(){
    Table table;
    std::ifstream inFile("table.md", std::ios::in);

    table.readFromFile(inFile);
    table.print();

    return 0;
}