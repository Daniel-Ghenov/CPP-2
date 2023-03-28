#include <string.h>
#include <iostream>
#include "Value.h"





void Value::getSpaces(Alignment align, size_t width, size_t len, int& leadingSpace, int& followSpace) const {

    switch(align){
    case  Alignment::center :
        leadingSpace = (width - len) / 2;
        followSpace = width - (len + leadingSpace);
        break;
    case Alignment::left :
        followSpace = width - len;
        break;
    case Alignment::right :
        leadingSpace = width - len;
    }
}
void Value::removeSpaces(){
    size_t termZero = 0;
    for(size_t i {0}; i < MAX_VALUE_LEN; i++){
        if(val[i] == '\0'){
            termZero = i;
        }
    }
    for(size_t i = termZero; i > 0; i--){
        if(val[i] == ' ')
            val[i] = '\0';
        else
            break;
    }
}
void Value::setVal(const char* val){
    strcpy(this->val, val);
    removeSpaces();
}
const char* Value::getVal() const{
    return val;
}
Value::Value(const char* str){
    strcpy(val, str);
}
Value::Value(): Value("\0") {}
void Value::print(Alignment align, size_t width) const{
    int len = strlen(val);
    int leadingSpace = 0, followSpace = 0;
    getSpaces(align, width, len, leadingSpace, followSpace);

    for(size_t i {0}; i < leadingSpace; i++)
        std::cout<<' ';
    std::cout<<val;
    for(size_t i {0}; i < followSpace; i++)
        std::cout<<' ';
    std::cout<<'|';
    

}
void Value::saveToFile(std::ofstream& outFile, Alignment align, size_t width) const{
    if(!outFile.is_open())
        return;

    int len = strlen(val);
    int leadingSpace = 0, followSpace = 0;
    getSpaces(align, width, len, leadingSpace, followSpace);
    outFile<<'|';
    for(size_t i {0}; i < leadingSpace; i++)
        outFile<<' ';
    outFile<<val;
    for(size_t i {0}; i < followSpace; i++)
        outFile<<' ';
}
void Value::readFromFile(std::ifstream& inFile){
    if(!inFile.is_open())
        return;
    char buffer[MAX_VALUE_LEN];
    while(inFile.peek() == ' ' || inFile.peek() == '|')
        inFile.ignore();
    
    inFile.getline(buffer, MAX_VALUE_LEN, '|');

    for(size_t i {0}; buffer[i] != '\0'; i++){
        if(buffer[i] == ' '){
            buffer[i] == '\0';
            break;
        }    
    }
    setVal(buffer);
}