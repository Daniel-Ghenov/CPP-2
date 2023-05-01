#pragma once
#include <iostream>

class NbitNum{
    char* number = nullptr;
    size_t byteSize = 0;

public:

    NbitNum() = default;
    NbitNum(size_t byteSize);
    NbitNum(size_t byteSize, size_t number);
    NbitNum(const NbitNum& other);
    NbitNum& operator=(const NbitNum& other);
    NbitNum(NbitNum&& other);
    NbitNum& operator=(NbitNum&& other);

    NbitNum operator*(const NbitNum& other);
    NbitNum operator+(const NbitNum& other);
    NbitNum operator-(const NbitNum& other);
    NbitNum operator/(const NbitNum& other);
    NbitNum operator%(const NbitNum& other);

    NbitNum& operator*=(const NbitNum& other);
    NbitNum& operator+=(const NbitNum& other);
    NbitNum& operator-=(const NbitNum& other);
    NbitNum& operator/=(const NbitNum& other);
    NbitNum& operator%=(const NbitNum& other);

    NbitNum operator<<(size_t shiftAmmount);
    NbitNum operator>>(size_t shiftAmmount);
    NbitNum operator^(const NbitNum& other);
    NbitNum operator&(const NbitNum& other);
    NbitNum operator|(const NbitNum& other);
    NbitNum operator~();

    NbitNum& operator<<=(size_t shiftAmmount);
    NbitNum& operator>>=(size_t shiftAmmount);
    NbitNum& operator^=(const NbitNum& other);
    NbitNum& operator&=(const NbitNum& other);
    NbitNum& operator|=(const NbitNum& other);

    bool operator<(const NbitNum& other) const ;
    bool operator<=(const NbitNum& other) const ;
    bool operator>(const NbitNum& other) const ;
    bool operator>=(const NbitNum& other) const ;
    bool operator==(const NbitNum& other) const ;
    bool operator!=(const NbitNum& other) const ;

    friend std::ostream& operator<<(std::ostream& os, NbitNum& num);
    friend std::istream& operator>>(std::istream& is, NbitNum& num);

private:
    void free();
    void copyFrom(const NbitNum& other);
    void move(NbitNum&& other);

};

std::ostream& operator<<(std::ostream& os, NbitNum& num);
std::istream& operator>>(std::istream& is, NbitNum& num);