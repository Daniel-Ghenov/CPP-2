#include <iostream>

int main(){



    int n;
    std::cin>>n;
    int cnum;

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n ;j++){
            for(int l = 1; l < n; l++){
                if((i*i + j*j == l*l) && cnum != j){
                    std::cout<< i<<" "<<j<<" "<<l<<" "<<std::endl;
                    cnum = i;
                    }
            }

        }
        
    }

}