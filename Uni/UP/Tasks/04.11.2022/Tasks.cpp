#include <iostream>


void transposeMatrix(int array[3][3]){

    for(size_t i {0}; i < 3; i++){
        for(size_t j {i}; j < 3; j++){
            int temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
            
        }
    }
}

void printArr(int array[3][3]){

    for(size_t i {0}; i < 3; i++){
        for(size_t j {0}; j < 3; j++){
            std::cout<<array[i][j]<<' ';
        }
        std::cout<<std::endl;
    }  
    std::cout<<std::endl;
}

void multiplyMatrix(int arr1[3][2], int arr2[2][3],int arrMult[3][3]){
    /*
    int commonLength = sizeof(arr1[0]) / sizeof(arr1[0][0]);
    int firstLength = sizeof(arr1[0]) / sizeof(arr1[0]);
    int lastLength = sizeof(arr2[0]) / sizeof(arr2[0][0]);*/
    
    for(size_t i {0}; i < 3;i++){
        for(size_t l {0};l < 3;l++){
            int sum = 0;
            for(size_t j {0};j < 2;j++){
                sum += arr1[i][j]*arr2[j][l];
            }
            arrMult[i][l] = sum;
        }
    }
    printArr(arrMult);

}

int main(){

    int arr[3][3] = {{1,2,3},{3,2,1},{4,5,3}};

    printArr(arr);
    transposeMatrix(arr);
    std::cout<<std::endl;
    printArr(arr);

    int arr1[3][2] = {{1,2},{7,1},{6,4}};
    int arr2[2][3] = {{5,3,1},{9,2,7}};
    int arrMult[3][3];


    multiplyMatrix(arr1, arr2, arrMult);





    return 0;
}
