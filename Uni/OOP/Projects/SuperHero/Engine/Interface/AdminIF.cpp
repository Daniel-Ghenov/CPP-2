#include "Interface\AdminIF.h"


AdminIF::AdminIF(){

    std::ifstream ifs(SAVEFILE_NAME, std::ios::in | std::ios::binary);  //starts from default path
    if(!ifs.is_open()){
        _sys = new System();
    }else
        _sys = new System(ifs);
}
AdminIF::AdminIF(std::ifstream& ifs){

    if(!ifs.is_open())
        throw std::runtime_error("Error opening file"); //starts system from specified path;

    _sys = new System(ifs);
}

void logIn(const char* username, const String& password){
    
}

AdminIF::~AdminIF(){
    free();
}


void AdminIF::addPlayer(const String& firstName, const String& lastName, const String& email, const char* username, const String& password){
    try{
        _sys->addPlayer({firstName, lastName, email, username, password, START_MONEY, Vector<SuperHero*>()});
    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }
}
void AdminIF::addAdmin(const String& firstName, const String& lastName, const String& email, const char* username, const String& password){
    try{
        _sys->addAdmin({firstName, lastName, email, username, password});
    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }
}
void AdminIF::removePlayer(const char* username){
    try{
        _sys->removeAdmin(username);
    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }
}
void AdminIF::printInfo(const char* username){
    try{
        _sys->printAdminInfo(username);
    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }
}
void AdminIF::addHero(const String& firstName, const String& lastName, const String& heroName, size_t power,
            size_t cost, Element element, Stance stance){
    try{
        _sys->addHero({firstName, lastName, heroName, power, cost, element, stance});
    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }         
}

void AdminIF::returnHero(size_t index){
    try{
        _sys->returnHero(index);
    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }         

}

void AdminIF::free(){
    delete[] _sys;
    _sys = nullptr;
}
