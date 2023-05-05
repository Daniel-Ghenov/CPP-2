#include <cmath>

int linearSearch(int* arr, size_t size,int find){
    for(size_t i {0}; i < size; i++){
        if(arr[i] == find)
            return i;
    }
    return -1;
}

int jumpSearch(int* arr, size_t size,int find){

    int jump = sqrt(size);
    
    for(size_t i {0}; i < size; i += jump){
        if(arr[i] < find && arr[i + jump] > find){
            return i*jump + linearSearch(arr + i, jump, find);
        }
    }
    return -1;
    
}