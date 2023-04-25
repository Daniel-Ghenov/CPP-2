#include <iostream>
#include <string>

int main(){

    bool istrue;
    int x {-121};
    /*
    std::string xStr = std::__cxx11::to_string(x);
    */
    std::string xStr;
    std::cout<<"xStr is: "<<xStr<< std::endl;
    std::string cont = xStr;
                
    for(size_t i {0}; i < xStr.length(); i++){
            int n = xStr.length();
            cont[i] = xStr[n-i-1];
            std::cout<< xStr[n-i]<<std::endl;
            std::cout<< "Cont is currently: "<<cont<<std::endl;
    }

    if(cont == xStr){
        istrue = true;
    }else {istrue = false;}

    std::cout<<"xStr is: "<<xStr<< std::endl;
    std::cout<< "Istrue is currently: "<<istrue<< std::endl;
    std::cout<< "Cont is currently: "<<cont<< std::endl;

    return 0;
}