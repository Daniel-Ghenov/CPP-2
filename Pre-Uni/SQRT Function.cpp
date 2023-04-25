/**
*  
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Daniel Ghenov
* @idnumber 6MI0600224
* @task 3
* 
*/
#include <iostream>

int pow(int a, int b){
    int pow = 1;

    while(b-- > 0){
        pow*=a;
    }
    return pow;
}

double sqrt(int a){
    int aLength = 0;
    for(int tempA = a;tempA > 0;){
        aLength++;
        tempA/=10;
    }

    double approx = 6* pow(10, aLength/2);
    
    for(int i = 0; i < 10; i++){
        approx =(approx + a/approx)/2;

    }
    return approx;
}


int main(){
    int a;
    std::cin>>a;
    std::cout<<sqrt(a);
   
    return 0;
}