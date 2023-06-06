#include <iostream>

void insertionSort(int* arr, size_t size){

    for(size_t i {1}; i < size; i++){
        size_t curr = i;
        while(arr[curr] < arr[curr - 1] && curr){
            std::swap(arr[curr], arr[curr - 1]);
            curr--;
        }
        
    }


}