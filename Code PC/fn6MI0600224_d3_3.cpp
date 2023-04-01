/**
*  
* Solution to homework assignment 3
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

void initializeArrays (int* array1, int* array2, int size){

    for(size_t i {0}; i < size; i++){
        std::cin>>array1[i];
    }    
    for(size_t i {0}; i < size; i++){
        std::cin>>array2[i];
    }
}
void printMaxTimes(int* maxTimes,int size){
    
    for(size_t i {0}; i < size; i++){
        if(maxTimes[i] < 10)
            std::cout<<"000"<<maxTimes[i];    
        else if(maxTimes[i] < 100)
            std::cout<<"00"<<maxTimes[i];
        else if(maxTimes[i] < 1000)
            std::cout<<"0"<<maxTimes[i];
        else
            std::cout<<maxTimes[i];
        if(i % 2 == 0)
            std::cout<<'-';
        else 
            std::cout<<std::endl;       
    }
}   

void checkFlights(int ammountOfFlights){
    int maxFlights = 0, maxTimesCounter = 0;
    int* arrivingTimes = new int(ammountOfFlights);
    int* departingTimes = new int(ammountOfFlights);
    int* maxTimes = new int(2*ammountOfFlights);


    initializeArrays(arrivingTimes, departingTimes, ammountOfFlights);

    for(size_t i {0}; i < ammountOfFlights; i++){
        int tempCount = 0;
        int arriveTime = arrivingTimes[i];
        for(size_t j {0}; j < ammountOfFlights; j++){
            if(arrivingTimes[j] <= arriveTime && arriveTime <= departingTimes[j])
                tempCount++;
        }
        if(tempCount > maxFlights){
            maxTimesCounter = 0;
            maxFlights = tempCount;
        }
        if(tempCount == maxFlights){
            maxTimes[maxTimesCounter++] = arrivingTimes[i];
            int MaxDepart = 2400;
            for(size_t j {0}; j < ammountOfFlights; j++){
                if(departingTimes[j] > arrivingTimes[i] && departingTimes[j] < MaxDepart)
                    MaxDepart = departingTimes[j];
            }
            maxTimes[maxTimesCounter++] = MaxDepart;
        }
    }
    std::cout<<maxFlights<<std::endl;
    printMaxTimes(maxTimes, maxTimesCounter);


    delete[] arrivingTimes;
    delete[] departingTimes;

}

int main(){

    int ammountOfFlights;
    std::cin>>ammountOfFlights;
    checkFlights(ammountOfFlights);



    return 0;
}