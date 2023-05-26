#pragma once
#include "ArrSet.h"

class Predicate{
protected:
    ArrSet nums;

public:
    Predicate(ArrSet numbers);

    virtual bool accepts(uint32_t number) const = 0;
    virtual ~Predicate() = default;
};


class notDivisible: public Predicate{
public:
    notDivisible(ArrSet numbers);

    bool accepts(uint32_t number) const override;

};

class DivisibleByOne: public Predicate{

public:
    DivisibleByOne(ArrSet numbers);

    bool accepts(uint32_t number) const override;

};