#include <iostream>
#include <random>

int partition(int* arr, size_t size){

    if(size <= 1)
        return 0;

    srand(time(NULL));
    size_t pivotPos = rand() % size;

    std::swap(arr[pivotPos], arr[size - 1]); 

    size_t placeCounter = 0;

    for(size_t i {0}; i < size - 1; i++){
        if(arr[i] <= arr[size - 1]){
            std::swap(arr[i], arr[placeCounter++]);
        }
    }

    std::swap(arr[placeCounter], arr[size - 1]);
    return placeCounter;

}

int ithSmallest(int* arr, size_t size, size_t i){

    if(size == 1)
        return arr[0];

    size_t partPos = partition(arr, size);

    if(partPos == i)
        return arr[partPos];

    else if(i < partPos)
        return ithSmallest(arr, partPos, i);
    
    return ithSmallest(arr + partPos + 1, size - partPos - 1, i - partPos - 1);

}