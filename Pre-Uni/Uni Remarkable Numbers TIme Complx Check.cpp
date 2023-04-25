#include <algorithm>
#include <iostream>
#include <chrono>

int pow(int, int);

double sqrt(int );

int closestRemarkableNumber(int);

double checkRuntime(double, double);

int main(){
               
    double loopTo;
    double loopFrom;
    std::cout<<"Enter Num to Loop from: ";
    std::cin>>loopFrom;
    std::cout<<"Enter Num to Loop to: ";
    std::cin>>loopTo;
    std::cout<<"Average Duration of program in milliseconds: "<<checkRuntime(loopFrom, loopTo);
    
    
    
    return 0;
}

double checkRuntime(double loopFrom, double loopTo){
    auto start = std::chrono::high_resolution_clock::now();

    for(int i = loopFrom; i < loopTo; i++){
        closestRemarkableNumber(i);
    }
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    return (double)duration.count()/(loopTo - loopFrom);
}

int closestRemarkableNumber(int inputNumber){
    if(inputNumber < 1 || inputNumber > 1000000000){
        //std::cout<<"Incorrect input";
        return 0; 
    }

    //We are going to check trough every number lower and higher number at the same time and the first one that is remarkable will be displayed.
    int controlNum = 1;
    for(int lowerTry = inputNumber, higherTry = inputNumber;;lowerTry--, higherTry++){
        //For optimisation purposes we will skip all even integers except for 2
        if(higherTry % 2 == 0 && higherTry != 2){
            continue;
            }   
        bool lowerRemarkable = true;
        bool higherRemarkable = true;
        int lowerSqrt = sqrt(lowerTry);
        int higherSqrt = sqrt(higherTry);
        //We are checking if lower and higher are prime.
        for(int i {2}; i <= lowerSqrt; i++){
            if(lowerTry % i == 0){
                lowerRemarkable = false;
                break;
            }
        }
        for(int i {2}; i <= higherSqrt; i++){
            if(higherTry % i == 0){
                higherRemarkable = false;
                break;
            }
        }
        //For optimisation we check if they are both already not remarkable.
        if(!lowerRemarkable && !higherRemarkable)
            continue;
        //We are now checking if lower and higher contain only different digits.
        for(int i {0}; i <= 9 && lowerRemarkable; i++){
            int cnum = 0;
            int tempLow = lowerTry;
            while(tempLow != 0 && cnum <= 1){
                if(tempLow % 10 == i)
                    cnum++;
                tempLow /= 10;
            }
            if(cnum > 1){
                lowerRemarkable = false;
                break;
            }

        }
        //For optimisation we check if they are both already not remarkable.
        if(!lowerRemarkable && !higherRemarkable)
            continue;
        //Then we continue with the higher number.
        for(int i {0}; i <= 9 && higherRemarkable; i++){
            int cnum = 0;
            int tempHigh = higherTry;
            while(tempHigh != 0 && cnum <= 1){
                if(tempHigh % 10 == i)
                    cnum++;
                tempHigh /= 10;
            }
            if(cnum > 1){
                higherRemarkable = false;
                break;
            }

        }
        if(lowerRemarkable){
        //std::cout<<"Closest remarkable number is: "<<lowerTry;
        return 0;
        }
        if(higherRemarkable){
        //std::cout<<"Closest remarkable number is: "<<higherTry;
        return 0;
        }
        
    }
}

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
