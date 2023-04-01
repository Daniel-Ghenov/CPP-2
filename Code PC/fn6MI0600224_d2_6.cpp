/**
*  
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Daniel Ghenov
* @idnumber 6MI0600224
* @task 6
* 
*/
#include <iostream>

int reversed (int a){
	int reversed = 0;
	
	while(a > 0){
		reversed += a % 10;
		reversed *= 10;
		a /= 10;
	}
	return reversed/ 10;
}
bool isPalindorme(int a){
	return (a == reversed(a) && a > 100);
}
bool isHalfPalindrome(int a){
    bool hasOneOddNumberedDigit = false;
    bool HasOneNon0EvenDigit = false;
    if(a < 100)
        return false;
    for(size_t i {0}; i < 9; i++){
        int digitCount;
        int tempA = a;
        while(tempA > 0){
            if(tempA % 10 == i)
                digitCount++;
            tempA /= 10;
        }
        if(digitCount % 2 != 0 && hasOneOddNumberedDigit)
            return false;
        if(digitCount % 2 != 0 && !hasOneOddNumberedDigit)
            hasOneOddNumberedDigit = true;
        else if(digitCount % 2 == 0 && i != 0)
            HasOneNon0EvenDigit = true;
    }
    return HasOneNon0EvenDigit;
}

int countPalindromes(unsigned int start,unsigned int end){

    int count = 0;

    if(start < 1 || start > 2147483648)
        return -1;
    if(end < 1 || end > 2147483648)
        return -1;
    
    for(size_t i = start; i <= end; i++){
        if(isPalindorme(i))
            count++;
        else if(isHalfPalindrome(i))
            count++;

    }
    return count;
}

int main(){

    unsigned int start, end;
    std::cin>>start>>end;
    std::cout<<countPalindromes(start, end);



    return 0;
}