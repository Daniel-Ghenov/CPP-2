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


int main(){
               
    const int TerminalWidth = 80;
    const int TerminalHeight = 25;
    int shapeSize = 0;
    std::cin>>shapeSize;
    if(shapeSize < 2 || shapeSize > 9){
        std::cout<<"Incorrect input";
        return 0;
    }

    //Setting a buffer above the shape.
    for(int j {1}; j <= (TerminalHeight - 2*shapeSize +1)/2; j++){
        std::cout<<std::endl;
    }
    //Setting a check so we can increment i untill it reaches the length of the desired shape.
    //Then we force it back untill it becomes 0.
    bool ReachedMiddle = false;

    for(int i {1};i >= 1;){
        //Pushing the shape to the middle.
        for(int j {1}; j <= (TerminalWidth - 3*shapeSize)/2; j++){
            std::cout<<" ";
        }
        //Making the left part of the shape.
        for(int j {1}; j <= i; j++){
            std::cout<<j;
        }
        for(int j {0}; j < (3*shapeSize - 2* i); j++){
            if(i == shapeSize)
                std::cout<<"-";
            else
                std::cout<<" ";
            //Filling the hole between the left and right shapes.
        }
        //Making the right part of the shape.
        for(int j = i; j > 0; j--){
            std::cout<<j;
        }
        std::cout<<std::endl;
        if(i == shapeSize){
            ReachedMiddle = true;
        }
        if(!ReachedMiddle){
            i++;
        }else{
            i--;
        }
    }                                 

    for(int j {1}; j <= ((TerminalHeight - 2*shapeSize +1)/2); j++){
        std::cout<<std::endl;
    }
    //Setting a buffer below the shape                  


    return 0;
}
