#include "Predicate.h"

Predicate::Predicate(ArrSet numbers): nums(numbers) {}


notDivisible::notDivisible(ArrSet numbers): Predicate(numbers){}

DivisibleByOne::DivisibleByOne(ArrSet numbers): Predicate(numbers){}


bool notDivisible::accepts(uint32_t number) const{
    for(size_t i {0}; i < nums.size(); i++){
        if(number % nums[i] == 0)
            return false;
    }
    return true;
}

bool DivisibleByOne::accepts(uint32_t number) const {
    bool divByOne = false;
    for(size_t i {0}; i < nums.size(); i++){
        if(number % nums[i] == 0){
            if(divByOne)
                return false;
            else
                divByOne = true;
        }
    }
    return divByOne;
}
