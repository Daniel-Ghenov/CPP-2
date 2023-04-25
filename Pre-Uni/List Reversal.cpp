#include <iostream>

void swap(int& a, int& b){

    int temp = a;
    a = b;
    b = temp;

}

int main(){

    int list1 [] = {1, 2, 4, 6, 10, 15};
    int listSize = sizeof(list1) /sizeof(list1)[0];
    
    for(int i = 0; i < listSize/2; i++){
        swap(list1[i], list1[listSize - i - 1]);
    }
    for(int i = 0; i < listSize; i++){
        std::cout<<list1[i]<<", ";
    }

    return 0;
}