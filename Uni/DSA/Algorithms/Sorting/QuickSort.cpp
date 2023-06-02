#include <random>

void quickSort(int* arr, size_t size){

    if(size <= 1)
        return;

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

    quickSort(arr, placeCounter);
    quickSort(arr + placeCounter  + 1, size - placeCounter - 1);

}
