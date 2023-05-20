#include "ArrSet.h"

ArrSet::ArrSet(uint32_t* arr, uint32_t size){
    _size = size;
    for(size_t i{0}; i < size; i++){
        _arr[i] = arr[i];
    }
}
bool ArrSet::contains(uint32_t number) const{

    int min = 0, max = _size;
    while(min != max){
        int mid = (min + max) / 2;
        if(_arr[mid] == number)
            return true;
            
        else if(_arr[mid] < number){
            min = mid + 1;
            
        }else{
            max = mid - 1;
        }
    }
    return false;

}