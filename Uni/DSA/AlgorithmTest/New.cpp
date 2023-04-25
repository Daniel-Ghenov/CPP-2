#include <iostream>
#include <cmath>
#include <chrono>
#include <algorithm>

bool isSorted(int* arr, size_t size){
    for(size_t i {0}; i < size - 1; i++){
        if(arr[i] > arr[i + 1])
            return false;
    }
    return true;
}
void print(int* arr, size_t size){
    for(size_t i {0}; i < size; i++){
        std::cout<<arr[i]<<',';
    }
    std::cout<<std::endl;
}
double getTime(size_t repetitions, size_t arrsize){

    size_t errCount = 0;
    int* arr = new int[arrsize];
    for(size_t i {0};i < arrsize; i++){
        arr[i] = i;
    }
    print(arr, arrsize);
    auto start = std::chrono::high_resolution_clock::now();
    // for(size_t i {0}; i < repetitions; i++){
    //     std::random_shuffle(arr, arr+ arrsize);
    //     mergeSort(arr, arrsize);
    //     if(!isSorted(arr, arrsize)){
    //         errCount++;
    //     }
    // }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout<<"ErrCount: "<<errCount<<std::endl;

    return (double)duration.count();
}

int main(){
    srand(time(NULL));
    size_t repet, size;
    std::cin>> repet>>size;
    std::cout<< getTime(repet, size);


}