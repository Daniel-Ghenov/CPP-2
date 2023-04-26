#include "Nbit.h"


NbitNum::NbitNum(size_t byteSize): byteSize(byteSize){
    this->number = new char[byteSize];
}

NbitNum::NbitNum(size_t byteSize, size_t number): byteSize(byteSize){

    size_t numLen = log2(number) / 8;
    if(byteSize < numLen)
        throw std::runtime_error("byteSize Not Large Enough");


    this->number = new char[byteSize];
    memcpy(this->number + (byteSize - numLen),(char*)&number + numLen, numLen);
    
}

NbitNum::NbitNum(const NbitNum& other){
    this->copyFrom(other);
}

NbitNum& NbitNum::operator=(const NbitNum& other){
    if(this != &other){
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

NbitNum::NbitNum(NbitNum&& other){
    this->move(std::move(other));
}

NbitNum& NbitNum::operator=(NbitNum&& other){
    if(this != &other){
        this->free();
        this->move(std::move(other));
    }
    return *this;
}



NbitNum NbitNum::operator+(const NbitNum& other){
    NbitNum result(std::max(this->byteSize, other.byteSize));
}
NbitNum NbitNum::operator-(const NbitNum& other){
    
}
NbitNum NbitNum::operator*(const NbitNum& other){
    
}
NbitNum NbitNum::operator/(const NbitNum& other){
    
}
NbitNum NbitNum::operator%(const NbitNum& other){
    
}


NbitNum& NbitNum::operator+=(const NbitNum& other){
    if(this->byteSize < other.byteSize)
        throw std::runtime_error("Not enough memory for operation");

    for(size_t i = byteSize; i > 0 && i > other.byteSize; i--){ //Carry doesn't go trough to new Bytes
        char otherByte = other.number[i];                       //Needs fixing
        while(otherByte != 0){
            char carry = this->number[i] & otherByte;
            this->number[i] = this->number[i] ^ otherByte;
            otherByte = carry << 1;
        }
    }
}
NbitNum& NbitNum::operator-=(const NbitNum& other){
    
}
NbitNum& NbitNum::operator*=(const NbitNum& other){
    
}
NbitNum& NbitNum::operator/=(const NbitNum& other){
    
}
NbitNum& NbitNum::operator%=(const NbitNum& other){
    
}


NbitNum NbitNum::operator<<(size_t shiftAmmount){
    
}
NbitNum NbitNum::operator>>(size_t shiftAmmount){
    
}
NbitNum NbitNum::operator^(const NbitNum& other){
    
}
NbitNum NbitNum::operator&(const NbitNum& other){
    
}
NbitNum NbitNum::operator|(const NbitNum& other){
    
}
NbitNum NbitNum::operator~(){
    
}
NbitNum& NbitNum::operator<<=(size_t shiftAmmount){
    
}
NbitNum& NbitNum::operator>>=(size_t shiftAmmount){
    
}
NbitNum& NbitNum::operator^=(const NbitNum& other){
    
}
NbitNum& NbitNum::operator&=(const NbitNum& other){
    
}
NbitNum& NbitNum::operator|=(const NbitNum& other){
    
}

bool NbitNum::operator<(const NbitNum& other) const {
    
}
bool NbitNum::operator<=(const NbitNum& other) const {
    
}
bool NbitNum::operator>(const NbitNum& other) const {
    
}
bool NbitNum::operator>=(const NbitNum& other) const {
    
}
bool NbitNum::operator==(const NbitNum& other) const {
    
}
bool NbitNum::operator!=(const NbitNum& other) const {
    
}


void NbitNum::free(){
    delete[] this->number;
    this->number = nullptr;
    this->byteSize = 0;
}

void NbitNum::copyFrom(const NbitNum& other){
    this->number = new char[other.byteSize];
    this->byteSize = other.byteSize;
    strcpy_s(this->number, other.byteSize, other.number);
}

void NbitNum::move(NbitNum&& other){
    this->number = other.number;
    other.number = nullptr;
    this->byteSize = other.byteSize;
    other.byteSize = 0;
}