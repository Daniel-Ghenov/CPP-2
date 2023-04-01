#include <iostream>

int pow(int num, unsigned N){

    while(N > 0){

        num*=num;
        N--;
    }
    return num;
}

void binaryNumber(int n){

    int binary = 0;

    for(int i = 0; n > 0;i++){
        if(n % 2 == 1){
            binary += pow(10, i);
        }
        n/=2;
    }
    std::cout<<binary;

}


int main(){


    return 0;

} 