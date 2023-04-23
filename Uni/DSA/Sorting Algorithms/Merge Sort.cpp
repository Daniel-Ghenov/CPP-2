#include <iostream>


int* merge(int* arr1, int* arr2, size_t partSize){      //Needs a fix!!!!

    int* mergeInto = new int[partSize * 2];

    int counter1 = 0, counter2 = 0;

    while(counter1 < partSize || counter2 < partSize){
        if(counter1 == partSize){
            mergeInto[counter1 + counter2] = arr2[counter2];
            counter2++;
        }
        else if(counter2 == partSize || arr1[counter1] < arr2[counter2]){
            mergeInto[counter1 + counter2] = arr1[counter1];
            counter1++;
        }
        else{
            mergeInto[counter1 + counter2] = arr2[counter2];
            counter2++;
        }

    }

    delete[] arr1;
    delete[] arr2;
    return mergeInto;

}

int* recursMerge(int* arr, size_t left, size_t right){
    if(right - left <= 1){
        int* arr2 = new int[1];
        arr2[0] = arr[left];
        return arr2;
    }
        
    int mid = (left + right)/2;
    int* firstHalf = recursMerge(arr, left, mid);
    int* secondHalf = recursMerge(arr, mid, right); 

    return  merge(firstHalf, secondHalf, right - left);

}

void mergeSort(int* arr, size_t size){

    int* sorted = recursMerge(arr, 0, size);
    for(size_t i {0}; i < size; i++){
        arr[i] = sorted[i];
    }
    delete[] sorted;
}




int main(){

    int arr[] = {7,21,9,2,7,12,7,8};
    size_t size = 8;

    mergeSort(arr, size);
    for(size_t i {0}; i < size; i++){
        std::cout<<arr[i]<<' ';
    }


    return 0;
}