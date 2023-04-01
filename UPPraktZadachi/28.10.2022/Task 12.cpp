#include <iostream>

int abs(int a){

    return (a > 0) ? a : -a;
}

int inInterval(int a){

    while(a > 100000 || a < 100){
        std::cout<<"Try again: ";
        std::cin>>a;
    }
    return a;
}

int closestPowOfTwo(int a){

    a = inInterval(a);

    int ctrlNum = 0;
    for(int i = 64;;a *= 2){
        if(abs(a - i) < abs(a - ctrlNum)){
            ctrlNum = i;
        }
        else
            return ctrlNum;
    }

}

int main(){


    std::cout<<closestPowOfTwo(0);

    return 0;

} 