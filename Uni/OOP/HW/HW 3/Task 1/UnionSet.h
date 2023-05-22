#pragma once
#include "Set.h"
#include "SharedPtr.hpp"
#include "Vector.hpp"

class UnionSet: public Set{
private:
    Vector<SharedPtr<Set>> _sets;

public:
    UnionSet(const Vector<SharedPtr<Set>>& sets);
    UnionSet(Vector<SharedPtr<Set>>&& sets);
    bool contains(uint32_t number) const override;


};