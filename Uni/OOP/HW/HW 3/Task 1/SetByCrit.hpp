#pragma once
#include "Set.h"


template <class Criterium>
class SetByCrit : public Set{
public:


    bool contains(uint32_t number) const override;


};

template <typename Criterium>
bool SetByCrit<Criterium>::contains(uint32_t number) const{
    return Criterium(number);
}

