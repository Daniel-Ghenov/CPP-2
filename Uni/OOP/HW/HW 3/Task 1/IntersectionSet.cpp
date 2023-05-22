#include "IntersectionSet.h"

IntersectionSet::IntersectionSet(const Vector<SharedPtr<Set>>& sets): _sets(sets){ }
IntersectionSet::IntersectionSet(Vector<SharedPtr<Set>>&& sets): _sets(std::move(sets)){ }


bool IntersectionSet::contains(uint32_t number) const{
    for(size_t i{0}; i < _sets.size(); i++){
        if(_sets[i]->contains(number))
            return true;
    }
    return false;
}