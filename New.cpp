#include <iostream>


int main(){

    srand(time(NULL));
    int arr[20] = {102,1021, 231, 712, 8763, 672, 12, 7263, 823, 26 , 107 ,1027 , 237 , 717 , 8767 , 677 , 17 , 7267 , 827 , 26};

    // introSort(arr, 20, 20);

    for(size_t i {0}; i < 20; i++){
        std::cout<<arr[i]<< std::endl;
    }
 
    return 0;
}