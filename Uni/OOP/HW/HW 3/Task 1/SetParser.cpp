#include <fstream>
#include "UnionSet.h"
#include "IntersectionSet.h"
#include "ArrSet.h"
#include "SetByCrit.hpp"



SharedPtr<Set> setFactory(std::ifstream& ifs){
    uint16_t type;
    uint16_t number;
    
    ifs.read((char*)&type, sizeof(type));
    ifs.read((char*)&number, sizeof(number));

    switch(type){
        case 0:
            uint32_t arr[MAX__ARR_SIZE];
            ifs.read((char*)arr, sizeof(uint32_t) * number);
            return new ArrSet(arr, number);
        case 1:


    }
}