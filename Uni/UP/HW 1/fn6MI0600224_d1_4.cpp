/**
*  
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Daniel Ghenov
* @idnumber 6MI0600224
* @task 4
* 
*/
#include <iostream>

int pow(int, int);

int sqrt(int a);

bool checkPrime(int a);

bool checkDigits(int a);

int main(){
               

    unsigned int inputNumber = 0;
    std::cin>>inputNumber;
    
    if(inputNumber < 1 || inputNumber > 1000000000){
        std::cout<<"Incorrect input";
        return 0; 
    }

    //We are going to check trough every number lower and higher number at the same time and the first one that is remarkable will be displayed.
    for(int lowerTry = inputNumber, higherTry = inputNumber;;lowerTry--, higherTry++){
        //For optimisation purposes we will skip all even integers except for 2
        if(higherTry % 2 == 0 && higherTry != 2){
            continue;
            }   
        bool lowerRemarkable = (checkPrime(lowerTry) && checkDigits(lowerTry));
        bool higherRemarkable = (checkPrime(higherTry) && checkDigits(higherTry));

        if(lowerRemarkable){
        std::cout<<lowerTry;
        return 0;
        }
        if(higherRemarkable){
        std::cout<<higherTry;
        return 0;
        }
        
    }
    return 0;
}
// A function for rasing a to the power of b
int pow(int a, int b){
    int pow = 1;

    while(b-- > 0){
        pow*=a;
    }
    return pow;
}
//A function that finds the sqare root of a using Linear approximation and Heron's method
int sqrt(int a){
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
//We check if a is prime
bool checkPrime(int a){
    int aSqrt = sqrt(a);
    for(int i {2}; i <= aSqrt; i++){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}
//We check if all digits of a are different
bool checkDigits(int a){
    for(int i {0}; i <= 9; i++){
        int cnum = 0;
        int tempa = a;
        while(tempa != 0 && cnum <= 1){
            if(tempa % 10 == i)
                cnum++;
            tempa /= 10;
        }
        if(cnum > 1){
            return false;
        }

    }
    return true;
}