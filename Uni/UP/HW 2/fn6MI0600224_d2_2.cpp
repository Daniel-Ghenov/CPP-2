/**
*  
* Solution to homework assignment 2
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

const int EPSILON = 0.0000001;

double pow(double a, double b){

    double pow = 1;
    for(size_t i {0}; i < b; i++){
        pow *= a;
    }

    return pow;
}
double abs(double a){

    return (a > 0) ? a : -a;
}

int main(){

    double x, y;
    std::cin>>x>>y;

    if((pow(x, 2) + pow(y, 2)) < 1){
        std::cout<< "Nose";
        return 0;
    }
    if((pow(x-4, 2) + pow(y - 4, 2)) < 4 || (pow(x+4, 2) + pow(y - 4, 2)) < 4){
        std::cout<< "Eye";
        return 0;
    }
    if((x > -5 && x < 5) && (y > -6 && y < -4)){
        std::cout<< "Mouth";
        return 0; 
    }
    if((pow(x, 2) + pow(y, 2)) == 1 || (pow(x-4, 2) + pow(y - 4, 2)) == 4 || (pow(x+4, 2) + pow(y - 4, 2)) == 4 || (x == -5 || x == 5) && (y > -6 && y < -4) || (x > -5 || x < 5) && (y == -6 || y == -4)){
        std::cout<< "Border";
        return 0;
    }
    if((pow(x, 2) + pow(y, 2)) < 100){
        std::cout<< "Face";
        return 0;
    }
    if((x > -10 && x < 10) && (y > -10 && y < 10)){
        std::cout<< "Background";
        return 0; 
    }
    if((x < -10 || x > 10) && (y < -10 || y > 10)){
        std::cout<< "Miss";
        return 0;   
    }
        std::cout<< "Border";
        return 0; 

    return 0;
}