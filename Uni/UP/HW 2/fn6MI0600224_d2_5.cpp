/**
*  
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Daniel Ghenov
* @idnumber 6MI0600224
* @task 5
* 
*/
#include <iostream>
#include <cmath>

const int MAX_SIZE = 10;

int len(size_t number){
    int length = 0;
    while(number> 0){
        number/=10;
        length++;
    }
    return length;
}
int pow(int a, int b){
    int power = 1;
    while(b > 0){
        power *= a;
        b--;
    }
    return power;
}
bool isPrime(int a){

    int aSqrt = sqrt(a);
    if(a == 1)
        return false;

    for(int i {2}; i <= aSqrt; i++){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}
int minimumStepsToPrime(size_t number){

    if(number < 1 || number > 1000000000)
        return -2;

    //We start iterating through the number only removing the first digit
    //Then we check how many steps that is and we remove the last two digits and start again
    //We keep checking like this untill we cannot remove anymore digits from the back of the number

    int length = len(number);
    int stepsCount = length + 1;

    for(size_t i {0};number > 0;i++){
        int tempNum = number;
        int currentSteps = i;
        while(tempNum > 0){
            if(isPrime(tempNum)){
                if(stepsCount > currentSteps)
                    stepsCount = currentSteps;
                break;
            }
            tempNum %= pow(10, len(tempNum) - 1);
            currentSteps++;
        }
        number/=100;
    }
    return (stepsCount < length + 1)? stepsCount : -1;
}

int main (){

    unsigned number;
    std::cin>>number;
    std::cout<<minimumStepsToPrime(number);

    return 0;
}
