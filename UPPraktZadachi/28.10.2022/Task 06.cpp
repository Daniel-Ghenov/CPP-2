#include <iostream>



bool isCapitalLetter(char S){


    return (S > 64 && S < 91);
}
bool checkSymbol(char S){
    if(isCapitalLetter(S))
        return true;
    return (S > 97 && S < 112);
}
int main(){


    return 0;

} 