#include <iostream>
#include <random>

void insertionSort(int* arr, size_t size){

    for(size_t i {1}; i < size; i++){
        size_t curr = i;
        while(arr[curr] < arr[curr - 1] && curr){
            std::swap(arr[curr], arr[curr - 1]);
            curr--;
        }
        
    }


}

void maxHepify(int* array, int size, int curr){

    int leftIdx = curr * 2;
    int rightIdx = curr * 2 + 1;

    int largest = curr;

    if(leftIdx < size && array[leftIdx] > array[curr])
        largest = leftIdx;

    if(rightIdx < size && array[rightIdx] > array[largest])
        largest = rightIdx;

    if(largest != curr){
        std::swap(array[curr], array[largest]);
        maxHepify(array, size, largest);
    }

}

void buildMaxHeap(int* array, int size){

    for(int i = size / 2; i >= 0; i--){
        maxHepify(array, size, i);
    }

}

void heapSort(int* arr, size_t size){

    if(size <= 1)
        return;

    buildMaxHeap(arr, size);
    
    while(size > 1){
        maxHepify(arr, size, 0);
        std::swap(arr[0], arr[size - 1]);
        size--;
    }

    
}
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

void introSort(int* arr, size_t size, size_t maxSize){
    if(size <= 15){
        insertionSort(arr, size);
        return;
    }

    if(size <= log10(maxSize)){
        heapSort(arr, size);
        return;
    }

    size_t partPos = partition(arr, size);
    introSort(arr, partPos, maxSize);
    introSort(arr + partPos + 1, size - partPos - 1, maxSize);

}