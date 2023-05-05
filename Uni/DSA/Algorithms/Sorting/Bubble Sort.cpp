#include <iostream>

void BubbleSort(int* arr, size_t size){

    bool hasSwapped = false;

    for(size_t i {0}; i < size; i++){
        for(size_t j {0}; j < size - i - 1; j++){
            if(arr[i] > arr[i + 1]){
                std::swap(arr[i], arr[i + 1]);
                hasSwapped = true;
            }
        }
        if(!hasSwapped)
            return;
    }

}