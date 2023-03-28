/**
*  
* Solution to homework assignment 4
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
#include <iomanip>

const int MAX_USER_INPUT = 300;

char** enterStrings(int numberOfStrings){
    char** allStrings = new char*[numberOfStrings];
    std::cin.ignore();
    for(size_t i {0}; i < numberOfStrings; i++){
        allStrings[i] = new char[MAX_USER_INPUT];
        std::cin.getline(allStrings[i], MAX_USER_INPUT);
    }
    return allStrings;
}
double stringToDouble(char* array, int dotPlace, bool isNegative){
    double wholePart = 0;
    double fraction = 0;
    for(size_t i {0}; array[i] != ',' && array[i] != '.' && array[i] != '\0'; i++){
        (wholePart *= 10) += (array[i] - '0');
    }
    if(dotPlace == 0){
        return wholePart;
    }
    int arraySize = 0;
    while(array[arraySize++] != '\0');
    for(int i = arraySize - 2; i > dotPlace ;i--){
        (fraction += (array[i] - '0')) /= 10;
    }
    return (isNegative) ? wholePart + fraction : (wholePart + fraction) * -1;
    
}
bool checkString(char* array, int& dotPos, bool& isNegative){
    //We check if the string contains only numbers and at most one "." or ","
    bool hasZeroPoints = true;
    for(size_t i {0}; array[i] != '\0'; i++){
        if(i == 0 && array[i] == '-'){
            isNegative = true;
        }
        else if((array[i] < '0' || array[i] > '9') && (array[i] != '.' && array[i] != ',')){
            return false;
        }
        else if((array[i] == '.' || array[i] == ',') && (i == 0 || array[i + 1] == '\0')){
            return false;  
        }
        else if(array[i] == ',' || array[i] == '.'){
            if(hasZeroPoints){
                dotPos = i;
                hasZeroPoints = false;
            }else{
                return false;
            }
        }
    }
    return true;
}

void sortDoubles(double* array, int numberOfStrings){
    for(size_t i {0}; i < numberOfStrings - 1; i++){
        for(size_t j {0}; j < numberOfStrings - 1 - i; j++){
            if(array[j] > array[j + 1]){
                double temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }   
    }
}
void printDoubles(double* array, int size){
    for(size_t i {0}; i < size; i++){
        std::cout<< array[i] <<' ';
    }
}
void checkAllStrings(){
    int numberOfStrings;
    std::cin>>numberOfStrings;   
    if(numberOfStrings > 50 || numberOfStrings < 3){
        std::cout<<"Incorrect input"; 
        return;
    }
    double* allDoubles = new double[numberOfStrings]();
    char** allStrings = enterStrings(numberOfStrings);
    int doubleSize = 0;
    for(size_t i {0}; i < numberOfStrings; i++){
        int dotPos = 0;
        bool isNegative = false;
        if(checkString(allStrings[i], dotPos, isNegative)){
            allDoubles[doubleSize++] = stringToDouble(allStrings[i], dotPos, isNegative);
        }
    }
	sortDoubles(allDoubles, doubleSize);
    printDoubles(allDoubles, doubleSize);
    for(size_t i {0}; i < numberOfStrings; i++){
        delete[] allStrings[i];
    }
    delete[] allStrings;
    delete[] allDoubles;
}

int main(){

    checkAllStrings();

    return 0;
}