#include "ArrSet.h"

ArrSet::ArrSet(uint32_t* arr, uint32_t size){
    _size = size;
    for(size_t i{0}; i < size; i++){
        _arr[i] = arr[i];
    }
}
bool ArrSet::contains(uint32_t number) const{

    for(size_t i {0}; i < _size; i++){
        if(_arr[i] == number)
            return true;
    }
    return false;

}

uint32_t ArrSet::operator[](size_t idx) const{
    if(idx > _size)
        throw std::out_of_range("Idx out of range");
    
    return _arr[idx];
}


size_t ArrSet::size() const{
    return _size;
}
