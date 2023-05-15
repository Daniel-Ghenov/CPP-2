#include "CombinedIF.h"

CombinedIF::~CombinedIF(){
    free();
}


void CombinedIF::start(){

    String choice;
    std::cout<<"Please select whether to log in as an admin or a player"<<std::endl;
    std::cin>>choice;
    if(choice == "admin"){
        _adminIF = new AdminIF();
        _adminIF->start();
    }
    else if(choice == "player"){
        _playerIF = new PlayerIF();
        _playerIF->start();
    }
    else{
        std::cout<<"please select either \"admin\" or \"player\" "<<std::endl;
    }
}

void CombinedIF::free(){
    delete[] _playerIF;
    delete[] _adminIF;
    _playerIF = nullptr;
    _adminIF = nullptr;
}
