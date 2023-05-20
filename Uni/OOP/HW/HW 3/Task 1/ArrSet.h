# pragma once
#include "Set.h"

const int MAX__ARR_SIZE = 32;

class ArrSet :public Set{
private:
    uint32_t _arr[MAX__ARR_SIZE];
    uint32_t _size = 0;
public:
    ArrSet() = default;
    ArrSet(uint32_t* arr, uint32_t size);

    bool contains(uint32_t number) const override;

};