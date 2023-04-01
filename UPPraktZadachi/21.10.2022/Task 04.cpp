#include <iostream>

int main(){

    int m,n;
    std::cin>>m;
    std::cin>>n;
    int cnum = 1;
    int totalNums = n*m;

    for(int i {0}; i < n; i++){
        for(int j {0}; j < m; j++){
        std::cout<<cnum<<"   ";
        cnum++;

        }
    std::cout<<std::endl;
    }


}