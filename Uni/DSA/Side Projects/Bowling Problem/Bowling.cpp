#include <iostream>

/*Given an array of n "Pins" each worth some score
Return the maximum possible Score with the following operations:
Hit a pin to get it's score
Do not hit the pin
Hit two pins to get their multiplication as the result*/


int max(int a, int b, int c){
    return std::max(std::max(a, b), c);
}

int bowlMax(int* arr, size_t size, int* memoArr, int n){

    if(memoArr[n] != -1)
        return memoArr[n];
    if(n < 0){
        return 0;
    }

    return max(bowlMax(arr, size, memoArr, n -1 ), bowlMax(arr, size, memoArr, n -1 ) + arr[n], bowlMax(arr, size, memoArr, n -2) + (arr[n] * arr[n - 1]));

}

int bowlingMaxScore(int* arr, size_t size){

    int* memoizeArr = new int[size];
    for(size_t i {0}; i < size; i++){
        memoizeArr[i] = -1;
    }
    memoizeArr[0] = 0;

    int score = bowlMax(arr, size, memoizeArr, size - 1);

    delete[] memoizeArr;
    return score;
}



int main(){

    int arr[9]{1,1,9,9,2,-5,-5, 10, -5};
    std::cout<<bowlingMaxScore(arr, 9);


    return 0;   
}