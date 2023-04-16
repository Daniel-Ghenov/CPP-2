#pragma once
#include "String Piece.h"
#include "SSO.h"

class StringCreator{
private:
    StringPiece* pieces = nullptr;
    size_t size = 0;
    size_t capacity = 0;

public:
    StringCreator(size_t count);
    ~StringCreator();
    StringCreator(const StringCreator& other);
    StringCreator& operator=(const StringCreator& other);

    void addPiece(const StringPiece& piece);
    void addPiece();
    void swap(size_t index1 , size_t index2);
    void remove(size_t index);
    void add(size_t index, const StringPiece& piece);

    size_t getSize() const;

    String getString()const;

    StringPiece& operator[](size_t index);

private:
    void free();
    void copyFrom(const StringCreator& other);
    void resize(size_t newCap);
    size_t getLength() const;

};