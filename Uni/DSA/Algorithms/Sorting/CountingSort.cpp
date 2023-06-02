#include <limits>

unsigned findMax(unsigned* arr, size_t size){
    if(size == 0)
        return std::numeric_limits<unsigned>::min();

    unsigned max = arr[0];
    for(size_t i {1}; i < size; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}
void countingSort(unsigned* arr, unsigned* sortIn ,size_t size){  //sortIn is an array that has the same size as arr
                                                    
    if(size == 0)
        return;

    unsigned max = findMax(arr, size);
    unsigned* countArr = new unsigned[max + 1];

    for(size_t i {0}; i <= max; i++){
        countArr[i] = 0;
    }

    for(size_t i {0}; i < size; i++){
        countArr[arr[i]]++; //we count the instances of any number found
    }

    for(size_t i {1}; i <= max; i++){
        countArr[i] += countArr[i - 1]; //we are setting the ending indices of each number
    }

    for(int i = size - 1; i >= 0; i--){
        sortIn[--countArr[arr[i]]] = arr[i]; 
    }
    delete[] countArr;

}

