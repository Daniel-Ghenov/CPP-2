#include "Rights.h"


Rights::Rights(): Rights("---"){ }
Rights::Rights(const char* rights) {
    setRights(rights);
}
bool Rights::isValidRights(const char* rights){ //validating the string taken inside rights
    if(strlen(rights) < 3)
        return false;
    return ((rights[0] == 'r' || rights[0] == '-') &&
            (rights[1] == 'w' || rights[1] == '-') && 
            (rights[2] == 'x' || rights[2] == '-'));
}
bool Rights::hasRead() const{
    return rights[0] == 'r';       //read is 0 in the arr
}
bool Rights::hasWrite() const{
    return rights[1] == 'w';       //write is 1 in the arr
} 
bool Rights::hasExec() const{
    return rights[2] == 'x';       //exec is 2 in the arr
}  
bool Rights::hasRight(char right) const{
    if(right == 'r')
        return hasRead();
    if(right == 'w')
        return hasWrite();
    if(right == 'x')
        return hasExec();
    return false;
}

void Rights::setRead(bool set){ //transforming bools into a char
    if(set)
        rights[0] = 'r';
    else    
        rights[0] = '-';
}
void Rights::setWrite(bool set){
    if(set)
        rights[0] = 'w';
    else    
        rights[0] = '-';
} 
void Rights::setExec(bool set){
    if(set)
        rights[0] = 'x';
    else    
        rights[0] = '-';
}  
void Rights::setRight(char right, bool set){
    if(right == 'r')
        setRead(set);
    if(right == 'w')
        setWrite(set);
    if(right == 'x')
        setExec(set);  
}
void Rights::setRights(const char* rights){
    if(!isValidRights(rights))
        return;
    strcpy(this->rights, rights);
}
const char* Rights::getRights() const{
    return rights;
}