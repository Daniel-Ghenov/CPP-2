#include "UnionSet.h"

UnionSet::UnionSet(SharedPtr<Set> set1, SharedPtr<Set> set2){
    _set1 = set1;
    _set2 = set2;
}
bool UnionSet::contains(uint32_t number) const{
    return(_set1->contains(number) || _set2->contains(number));

}