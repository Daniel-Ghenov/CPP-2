#pragma once
#include "Set.h"
#include "SharedPtr.hpp"
#include "Vector.hpp"

class IntersectionSet: public Set{
private:
    Vector<SharedPtr<Set>> _sets;

public:
    IntersectionSet(const Vector<SharedPtr<Set>>& sets);
    IntersectionSet(Vector<SharedPtr<Set>>&& sets);

    bool contains(uint32_t number) const override;

};