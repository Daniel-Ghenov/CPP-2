#pragma once
#include "Set.h"
#include "SharedPtr.hpp"

class UnionSet: public Set{
private:
    SharedPtr<Set> _set1;
    SharedPtr<Set> _set2;

public:
    UnionSet(SharedPtr<Set> set1, SharedPtr<Set> set2);
    bool contains(uint32_t number) const override;


};