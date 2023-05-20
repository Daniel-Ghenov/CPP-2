#include "CombinedIF.h"



void CombinedIF::start(){

    while(1){
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
        std::cout<<"Would You like to log in as a different user? (y/n): "<<std::endl;
        std::cin>>choice;
        if(choice == "n"){
            System::getSystem()->free();
            break;
        }
    }

}
