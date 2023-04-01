#include <iostream>
#include <cmath>

int main(){
    /* 1.0
    int year;
    std::cout<< "Pick a year "<<std::endl;
    std::cin>>year;
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        {std::cout<<"Leap year"<<std::endl;}
    else
        {std::cout<<"Not a leap year"<<std::endl;}
    */
   /*2.0
    char character;
    std::cout<<"Input char"<<std::endl;
    std::cin<<character;
    if((character < 91 && character > 64) || (character < 123 && character > 96)){
        switch(character){
            case 'O':
            case 'U':
            case 'E':
            case 'A':
            case 'I':
            case 'o':
            case 'a':
            case 'u':
            case 'e':
            case 'i':
            std::cout<<"The char is a vowel"<<std::endl;
            default: std::cout<<"The char is not a vowel but is from the latin alphabet"<<std::endl;

        }
    }else{
        std::cout<<"The char is not from the latin alphabet";}*/
    /*3.0
    int a;
    int b;
    std::cout<<"Input a: "<<std::endl;
    std::cin<<a;
    std::cout<<"Input b: "<<std::endl;
    std::cin<<b;

    (a > b) ? a : b;*/




    /*
    int percentage {0};
    std::cout<<"Enter percentage";
    std::cin>>percentage;
    if(percentage >= 90)
        std::cout<<"6+";
    else if(percentage >= 80)
        std::cout<<6;
    else if(percentage >= 70)
        std::cout<<5;
    else if(percentage >= 60)
        std::cout<<4;
    else if(percentage >= 50)
        std::cout<<3;
    else
        std::cout<<2;*/
        /*
    double a, b, c;
    std::cin<<a<<b<<c;
    if(a + b < c && a + c < b && b + c < a && a > 0 && b > 0 && c > 0)
        std::cout<<"Valid triangle";
    else
        std::cout<<"Invalid triangle";*/
    /*
    double a, b, c;
    int x1, x2;
    x1 = ((b * -1) + sqrt((pow(b, 2) -(4* c * a))))/ 2 ;
    x2 = ((b * -1) - sqrt((pow(b, 2) -(4* c * a))))/ 2 ;
    std::cout<<x1<<" "<<x2;*/
    /*
    char symbol;
    std::cin>>symbol;
    if(symbol < 91 && symbol > 64 )
        std::cout<<symbol + 32;
    else if(symbol < 123 && symbol > 96 )
        std::cout<<symbol - 32;
    else
        std::cout<<"Invalid symbol"*/
        /*
    std::string romanNumeral;
    int numeralNum;
    std::cin<<romanNumeral;

    for(size_t i {0};i < romanNumeral.size();i++){
        if(romanNumeral[i] == 'I')
            numeralNum += 1;
        else if(romanNumeral[i] == 'V')
            numeralNum += 5;
        else if(romanNumeral[i] == 'X')
            numeralNum += 10;
    }*/



    return 0;
}