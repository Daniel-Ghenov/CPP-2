#include "Row.h"

void Row::setValue(size_t num, const char* val){
    if(num > colCount || num ==0)
        return;
    values[num].setVal(val);
}
void Row::addValue(const char* val){
    if(colCount == MAX_COLS)
        return;
    values[colCount++].setVal(val);
}
const char* Row::getValue(size_t num) const {
    return values[num].getVal();
}
size_t Row::getCount() const{
    return colCount;
}
void Row::print(const Alignment* aligns,const size_t* widths) const {
    std::cout<<'|';
    for(size_t i {0}; i < colCount; i++){
        values[i].print(aligns[i], widths[i]);
    }
    std::cout<<std::endl;
}
void Row::saveToFile(std::ofstream& outFile, const Alignment* aligns,const size_t* widths) const {
    if(!outFile.is_open())
        return;

    outFile<<'|';
    for(size_t i {0}; i < colCount; i++){
        values[i].saveToFile(outFile, aligns[i], widths[i]);
    }
    outFile<<std::endl;
}

void Row::readFromFile(std::ifstream& inFile){
    if(inFile.peek() == '\n')
        inFile.ignore();

    char buffer[MAX_ROW_LEN];
    inFile.getline(buffer, MAX_ROW_LEN);    

    std::stringstream ss(buffer);   //we put each line in a stringstream 

    ss.ignore();
    size_t colCount = 0;
    while(!ss.eof()){
        char valueBuff[MAX_VALUE_LEN];
        while(ss.peek() == ' ') ss.ignore();
        ss.getline(valueBuff, MAX_VALUE_LEN, '|');  //we cycle using '|' as a delim to get each value
        values[colCount++].setVal(valueBuff);
    }
    this->colCount = colCount - 1;
}