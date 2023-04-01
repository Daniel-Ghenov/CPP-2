#include "Table.h"
void Table::setWidth(size_t col){
    widths[col] = 0;
    for(size_t i {0}; i < rowCount; i++){
        int len = strlen(rows[i].getValue(col));
        if(len > widths[col]){
            widths[col] =  len;
        }
    }
    if(strlen(names.getValue(col)) > widths[col])
        widths[col] = strlen(names.getValue(col));
    widths[col] += 2;
}
void Table::setWidths(){
    for(size_t i {0}; i < colCount; i++){
        setWidth(i);
    }
}
void Table::printAlign() const{
    std::cout<<'|';
    for(size_t i {0}; i < colCount; i++){
        for(size_t j {0}; j < widths[i]; j++){
            std::cout<<'-';
        }
        std::cout<<'|';
    }
    std::cout<<std::endl;
}
void Table::saveAlign(std::ofstream& outFile) const {
    outFile<<'|';
    for(size_t i {0}; i < colCount; i++){
        if(alignments[i] == Alignment::center ||
            alignments[i] == Alignment::left)
                outFile<<':';
        for(size_t j {0}; j < widths[i] - 2; j++){
            outFile<<'-';
            if(alignments[i] == Alignment::left ||
                alignments[i] == Alignment::right)
                outFile<<'-';
        }
        if(alignments[i] == Alignment::center ||
            alignments[i] == Alignment::right)
                outFile<<':';
        outFile<<'|';
    }
    outFile<<std::endl;
}
void Table::setAlignment(Alignment& align, bool isLeft, bool isRight) const{

    if(isLeft && isRight)
        align = Alignment::center;
    else if(isRight)
        align = Alignment::right;
    else 
        align = Alignment::left;
}
void Table::getAlign(std::ifstream& inFile){
    bool isLeft, isRight;
    inFile.ignore();    //ignore leading '|'

    char buffer[MAX_ROW_LEN];
    inFile.getline(buffer, MAX_ROW_LEN);

    std::stringstream ss(buffer);
    int counter = 0;
    while(!ss.eof()){
        char alignBuff[MAX_VALUE_LEN];
        while(ss.peek() == ' ') ss.ignore();
        ss.getline(alignBuff, MAX_VALUE_LEN, '|');
        if(alignBuff[0] == ':')
            isLeft = true;
        for(size_t i {1}; i < MAX_VALUE_LEN; i++){
            if(alignBuff[i] == ':'){
                isRight = true;
                break;
            }
            if(alignBuff[i] == '\0')
                break;
        }
        setAlignment(alignments[counter++], isLeft, isRight);
        isLeft = isRight = false;
    }

}
void Table::print() const {
    names.print(alignments, widths);
    printAlign();
    for(size_t i {0}; i < rowCount; i++){
        rows[i].print(alignments, widths);
    }

}
const Row& Table::getRow(size_t number) const {
    return rows[number];
}

void Table::setNames(const Row& names){
    this->names = names;
}
void Table::changeColName(size_t colNum, const char* name){
    names.setValue(colNum, name);
}
int Table::getCol(const char* colName) const {
    for(size_t i{0}; i < colCount ; i++){
        if(strcmp(colName, names.getValue(i))){
            return i;
        }
    }
    return -1;
}
void Table::addRow(const Row& row){
    if(rowCount >= MAX_ROWS || colCount != row.getCount())
        return;
    rows[rowCount++] = row;
}
void Table::changeValue(size_t rowNum, const char* colName, const char* val){
    int colNum = getCol(colName);
    if(colNum == -1)
        return;
    rows[rowNum - 1].setValue(colNum, val);
}
void Table::changeValue(const char* colName, const char* oldVal, const char* newVal){
    int colNum = getCol(colName);
    if(colNum == -1)
        return;
    for(size_t i {0}; i < rowCount; i++){
        if(strcmp(oldVal, rows[i].getValue(colNum)) == 0)
            rows[i].setValue(colNum, newVal);
    } 
}
void Table::selectRows(const char* colName, const char* val) const{    
    int colNum = getCol(colName);
    if(colNum == -1)
        return;
    Table selected;
    selected.setNames(this->names);

    for(size_t i {0}; i < rowCount; i++){
        if(strcmp(val,rows[i].getValue(colNum)) == 0);
        selected.addRow(this->getRow(i));
    }
    selected.print();
}
void Table::saveToFile(std::ofstream& outFile) const {
    if(!outFile.is_open())
        return;
    names.saveToFile(outFile, alignments, widths);
    saveAlign(outFile);
    for(size_t i {0}; i < rowCount; i++){
        rows[i].saveToFile(outFile, alignments, widths);
    }

}
void Table::readFromFile(std::ifstream& inFile){
    if(!inFile.is_open())
        return;

    names.readFromFile(inFile);
    colCount = names.getCount();
    getAlign(inFile);
    int rowCounter = 0;
    while(!inFile.eof()){
        rows[rowCounter++].readFromFile(inFile);
    }
    rowCount = rowCounter - 1;

    setWidths();

}