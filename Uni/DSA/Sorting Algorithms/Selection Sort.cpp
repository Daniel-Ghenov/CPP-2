#include <iostream>

void selectionSort(int* arr, size_t size){


    for(size_t i {0}; i < size; i++){
        size_t minIdx = i;
        for(size_t j = i + 1; j < size; j++){
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        if(minIdx != i)
            std::swap(arr[minIdx], arr[i]);
    }
}