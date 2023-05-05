/**
*  
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Daniel Ghenov
* @idnumber 6MI0600224
* @task 2
* 
*/
#include <iostream>

int main(){
               

    unsigned short int inputNumber = 0;
    std::cin>>inputNumber;

    if(inputNumber < 1 || inputNumber > 2000){
        std::cout<<"Incorrect input";
        return 0;
    }

    while(inputNumber > 0){
        if(inputNumber >= 1000){
            std::cout<<"M";
            inputNumber-= 1000;
            continue;
        }else if(inputNumber >= 900){
            std::cout<<"CM";
            inputNumber-= 900;
            continue;
        }else if(inputNumber >= 500){
            std::cout<<"D";
            inputNumber-= 500;
            continue;
        }else if(inputNumber >= 400){
            std::cout<<"CD";
            inputNumber-= 400;
            continue;
        }else if(inputNumber >= 100){
            std::cout<<"C";
            inputNumber-= 100;
            continue;
        }else if(inputNumber >= 90){
            std::cout<<"XC";
            inputNumber-= 90;
            continue;
        }else if(inputNumber >= 50){
            std::cout<<"L";
            inputNumber-= 50;
            continue;
        }else if(inputNumber >= 40){
            std::cout<<"XL";
            inputNumber-= 40;
            continue;
        }else if(inputNumber >= 10){
            std::cout<<"X";
            inputNumber-= 10;
            continue;
        }else if(inputNumber >= 9){
            std::cout<<"IX";
            inputNumber-= 9;
            continue;
        }else if(inputNumber >= 5){
            std::cout<<"V";
            inputNumber-= 5;
            continue;
        }else if(inputNumber >= 4){
            std::cout<<"IV";
            inputNumber-= 4;
            continue;
        }else if(inputNumber >= 1){
            std::cout<<"I";
            inputNumber-= 1;
            continue;
        }

    }

    return 0;
}
