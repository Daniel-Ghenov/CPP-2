#include <iostream>
#include <fstream>
#include "Table.h"


int main(){
    Table table;
    std::ifstream inFile("table.md", std::ios::in);
    
    table.readFromFile(inFile);
    table.print();

    std::ofstream outFile("table2.md", std::ios::out);
    table.saveToFile(outFile);

    inFile.close();
    outFile.close();


    return 0;
}