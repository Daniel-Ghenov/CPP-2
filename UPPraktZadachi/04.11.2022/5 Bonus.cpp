#include <iostream>


int main(){
   
    int array1[] = {1,2,3,4,5,5};
    int array2[] = {2,5};
    int array1size = 6;

    for(int iter1 = 0, iter2 = 0;iter1 < 6 && iter2 < 2;){

        if(array1[iter1] == array2[iter2]){
            std::cout<<array1[iter1]<<", ";
            iter1++;
            iter2++;
        }
        else if(array1[iter1] > array2[iter2])
            iter2++;
        else 
            iter1++;
    }

    return 0;

} 