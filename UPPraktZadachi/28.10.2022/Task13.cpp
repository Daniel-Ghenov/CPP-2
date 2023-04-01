#include <iostream>
#include <cmath>

bool isPrime(int a){

    for(int i = 1; i < sqrt(a); i++){
        if(a % i == 0)
            return false;
    }
    return true;
}

void allLowerPrimes(int a){
    if(a > 0)
        std::cout<<"0"<<std::endl;
    if(a > 1)
        std::cout<<"1"<<std::endl;
    for(int i {2}; i < a; i++){

        if(isPrime(i))
            std::cout<<i;

    }



}

bool isSumofTwoPrimes(int a){

    return (a > 2 && a % 2 == 0) || isPrime(a);
    


}


void Checker(int a){

    std::cout<< (isPrime(a))<<std::endl;

    allLowerPrimes(a);

    std::cout<< (isSumofTwoPrimes(a))<<std::endl;

}

int main(){




    return 0;

} 