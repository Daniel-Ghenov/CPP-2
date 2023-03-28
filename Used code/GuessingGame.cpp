#include <iostream>
#include <cmath>
#include <time.h>

int main(){

    srand(time(NULL));

    int cnum = (rand() % 100) + 1;
    int gnum;

    std::cout << "Try to guess the number: ";
    std::cin >> gnum;

    while (cnum != gnum){
        if (cnum > gnum){
            std::cout << "The number is larger! try again: ";
            std::cin >> gnum;
        }
        else {
            std::cout << "The number is smaller! try again: ";
            std::cin >> gnum;
        }
    }

    std::cout << "Congratulations! You have won!" << std::endl << "The number was: " << gnum;
    

    return 0;
}