#pragma once
#include "Set.h"


template <class T>
class SetByCrit : public Set{
private:
    T predicate;
public:
    SetByCrit(const T& pred);
    SetByCrit(T&& pred);
    bool contains(uint32_t number) const override;
};

template <typename T>
bool SetByCrit<T>::contains(uint32_t number) const{
    return predicate.accepts(number);
}


template <typename T>
SetByCrit<T>::SetByCrit(const T& pred): predicate(pred) {}
template <typename T>
SetByCrit<T>::SetByCrit(T&& pred): predicate(pred) {}