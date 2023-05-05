/**
*  
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Daniel Ghenov
* @idnumber 6MI0600224
* @task 1
* 
*/
#include <iostream>


int main(){
               
    
    unsigned int input = 0;
    std::cin>>input;
    if(input < 1 || input > 1000000){
        std::cout<<"Incorrect input";
        return 0;
    }
    
    while(input != 0){
        int cnum = input % 10;
        cnum *= cnum;

        while(cnum != 0){
            if(input / 10 == 0 && cnum / 10 == 0){
                std::cout<<(cnum % 10) + 1;
            }else
                std::cout<<cnum % 10;
            cnum /= 10;

        }
        input /= 10;
    }
    return 0;
}
