#include <limits>
#include <cmath>

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

int findDigit(int num, size_t digit){
    return ((num / (int)pow(10, digit)) % 10);
}

int findDigit(int num, size_t digit, size_t digitSize){
    return ((num / (int)pow(digitSize, digit)) % digitSize);
}

double log(unsigned n, int num){
    return (log(num) / log(n));
}

void radixSort(unsigned* arr, unsigned* sortIn, size_t size){

    size_t digitSize = log10(size);

    unsigned maxDigitSize = log( digitSize,findMax(arr, size));

    int* countArr = new int[digitSize];
    
    for(size_t i {0}; i <= maxDigitSize; i++){

        for(size_t j {0}; j < digitSize; j++){
            countArr[j] = 0;
        }
        for(size_t j {0}; j < size; j++){
            countArr[findDigit(arr[j], i, digitSize)]++;
        }

        for(size_t j {1}; j < digitSize; j++){
            countArr[j] += countArr[j - 1];
        }
        for(int j = size - 1; j >= 0; j--){
            sortIn[--countArr[findDigit(arr[j], i, digitSize)]] = arr[j];
        }

        std::swap(arr, sortIn);
    }
    
    delete[] countArr;

    if( digitSize % 2 == 1){    //since we switch which array we sort in if we have an even number of swaps
        for(size_t i {0}; i < size; i++){   //we will have the sorted array inside arr so we swap it to sortIn
            sortIn[i] = arr[i];
        }
    }

}