#pragma once
#include <iostream>
#include <cassert>
#include "Const.h"

class Set{
private:
    uint8_t* set;
    size_t maxNum;

    void free();
    void copyFrom(const Set& other);

    inline size_t getBucketIdx(size_t number) const;
    inline size_t getInBucketIdx(size_t number) const;

public:
    Set(size_t size);
    Set(const Set& other);
    ~Set();
    Set& operator=(const Set& other);

    void add(size_t number);
    void remove(size_t number);
    bool contains(size_t number) const;
    void print() const;
    void printInMem() const;

    friend Set unionSet(const Set& lhs, const Set& rhs);
    friend Set intersectionSet(const Set& lhs, const Set& rhs);
};

Set unionSet(const Set& lhs, const Set& rhs);
Set intersectionSet(const Set& lhs, const Set& rhs);