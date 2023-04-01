#include <iostream>

int pow(int num, unsigned N){

    while(N > 0){

        num*=num;
        N--;
    }
    return num;
}


int main(){




    return 0;

} 