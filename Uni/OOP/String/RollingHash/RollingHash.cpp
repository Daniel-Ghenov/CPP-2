#include "RollingHash.h"

RollingHash::RollingHash(const char* string, size_t strlen): primeFac(){
    if(!strlen){
        strlen = strleng(string);
    }
    for(size_t i {0}; i < strlen; i++){
        hash *= CHAR_SIZE;
        hash += string[i];
    }

}


size_t RollingHash::getHash(){
    return hash;
}


void RollingHash::push_front(char newChar){
    hash = (hash * CHAR_SIZE) + newChar;

}

void RollingHash::pop_back(){
    hash %= static_cast<int>(log(hash)/log(CHAR_SIZE));

}

bool RollingHash::operator==(const RollingHash& other){
    return hash == other.hash;
}
size_t RollingHash::getPrime(size_t number){

    
}
