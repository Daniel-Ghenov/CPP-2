#include <iostream>
#include <algorithm>

const int sizeOf = 6;

void initiateArray(int* arr1, int size){
    for(size_t i {0}; i < size; i++){
        arr1[i] = i + 1;
    }
}

bool isNonMoving(int* arr1, int* arr2, int size){
    for(size_t i {0}; i < size; i++){
        if(i + 1 == arr1[i] && i + 1 == arr2[i])
        return false;
    }
    return true;
}
int numberOfPermutations(int array1[], int array2[], int n){
    initiateArray(array1, n);
    initiateArray(array2, n);
    int count = 0;
    do{
        do{
            if(isNonMoving(array1, array2, n))
                count++;

        }while(std::next_permutation(array2, array2 + n));
        initiateArray(array2, n);
    }while(std::next_permutation(array1, array1 + n));
    return count;
}

int main(){

    int array1[sizeOf];
    int array2[sizeOf];
    std::cout<<numberOfPermutations(array1, array2, sizeOf);

    return 0;
}