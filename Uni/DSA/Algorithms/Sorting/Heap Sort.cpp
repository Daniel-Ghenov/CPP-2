#include <iostream>

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