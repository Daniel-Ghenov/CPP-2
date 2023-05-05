/**
*  
* Solution to homework assignment 4
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
void swap(int& a, int& b){
    int tempnum = a;
    a = b;
    b = tempnum;
}
int gcd(int a, int b){
    //We use the Ucledean Method of finding gcd
    if(b > a)
        swap(a,b);
    while(b > 0){
        int tempnum = a % b;
        a = b;
        b = tempnum;
    }
    return a;
}
void pourInto(int& fromWatter, int& toWater, int maxWaterTo){
    if(fromWatter > maxWaterTo - toWater){
        fromWatter -= (maxWaterTo - toWater);
        toWater = maxWaterTo;
    }else{
        toWater += fromWatter;
        fromWatter = 0;
    }
}
int pourAlgorithm(int water1Max ,int water2Max,int wantedWater){
    int water1 = 0 , water2 = 0, stepCount = 0;
    while(water1 != wantedWater && water2 != wantedWater){
        if(water1 == 0)
            water1 = water1Max;
        else if(water2 == water2Max)
            water2 = 0;
        else    
            pourInto(water1, water2, water2Max);
        stepCount++;
    }
    return stepCount;
}
void lowestNumberOfSteps(int water1Max ,int water2Max,int wantedWater){
    //if wantedWater is not devisible by the gcd of n andwater2Maxthen there is no way to get wantedWater liters in the jug;
    if(water1Max < 1 || water1Max > 20 ||water2Max < 1 ||water2Max > 20){
        std::cout<<"Incorrect input";
        return;
    }if(wantedWater > 20 || wantedWater < 1 || wantedWater % gcd(water1Max, water2Max) != 0 || (wantedWater > water1Max && wantedWater > water2Max)){
        std::cout<<"-1";
        return;
    }
    int stepsSmaller = pourAlgorithm(water1Max, water2Max, wantedWater);
    int stepsLarger = pourAlgorithm(water2Max, water1Max, wantedWater);
    std::cout<<((stepsSmaller < stepsLarger)? stepsSmaller : stepsLarger);

}
int main(){

    int water1Max , water2Max, wantedWater;
    std::cin>>water1Max>>water2Max>>wantedWater;
    lowestNumberOfSteps(water1Max, water2Max, wantedWater);

    return 0;
}