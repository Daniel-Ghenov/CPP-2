#include "AdminIF\AdminIF.h"



bool AdminIF::logIn(){

    char username[USERNAME_LEN];
    String password;

    std::cout<<"Please enter a username and password:"<<std::endl;
    std::cin>>username>>password;

    try{
        _admin = System::getSystem()->logInAdmin(username, password);
    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
        return false;
    }
    return true;
}

void AdminIF::start(){

    
    while(logIn());

    while(1){
        String command;
        std::cout<<"Please select a task to complete *you can use help to get a list of commands*"<<std::endl;
        std::cin>>command;

        if(command == "addPlayer"){
            addPlayer();
        }
        else if(command == "addAdmin"){
            addAdmin();
        }
        else if(command == "removePlayer"){
            removePlayer();
        }
        else if(command == "printInfo"){
            printInfo();
        }
        else if(command == "addHero"){
            addHero();
        }
        else if(command == "returnHero"){
            returnHero();
        }
        else if(command == "help"){
            help();
        }
        else if(command == "logOut"){
            break;
        }
        else{
            std::cout<<"Command not recognised please try again";
        }
    }

}


void AdminIF::addPlayer(){

    String firstName, lastName, email, password;
    char username[USERNAME_LEN];
    std::cout<<std::endl<<"Please enter a first name , last name , email , username and password";
    std::cin>>firstName>>lastName>>email>>username>>password;
    

    try{
        System::getSystem()->addPlayer({firstName, lastName, email, username, password, START_MONEY, Vector<SuperHero*>()});
    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }
}

void AdminIF::addAdmin(){

    String firstName, lastName, email, password;
    char username[USERNAME_LEN];
    std::cout<<std::endl<<"Please enter a first name , last name , email , username and password";
    std::cin>>firstName>>lastName>>email>>username>>password;

    try{
        System::getSystem()->addAdmin({firstName, lastName, email, username, password});
    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }
}

void AdminIF::removePlayer(){

    char username[USERNAME_LEN];
    std::cout<<std::endl<<"Please enter the username of the player to remove";
    std::cin>>username;

    try{
        System::getSystem()->removeAdmin(username);
    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }
}
void AdminIF::printInfo() const{

    char username[USERNAME_LEN];
    std::cout<<std::endl<<"Please enter the username of the user to print Info for";
    std::cin>>username;

    try{
        System::getSystem()->printAdminInfo(username);
    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }
}
void AdminIF::addHero(){

    String firstName, lastName, heroName;
    size_t power, cost;
    Element element;
    Stance stance;

    std::cout<<std::endl<<"Please enter a first name, last name, hero name, power, cost , element and stance";
    std::cin>>firstName>>lastName>>heroName>>power>>cost>>element>>stance;

    try{
        System::getSystem()->addHero({firstName, lastName, heroName, power, cost, element, stance});
    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }         
}

void AdminIF::returnHero(){

    size_t index;
    std::cout<<std::endl<<"Please select the index of the hero to return";
    printGraveyard();
    std::cin>>index;

    try{
        System::getSystem()->returnHero(index);
    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }         

}
void AdminIF::printGraveyard() const{
    System::getSystem()->printGraveyard();
}

void AdminIF::help() const{
    std::cout<<"addPlayer - initialize a new player"<<std::endl;
    std::cout<<"addAdmin - initialize a new admin"<<std::endl;
    std::cout<<"removePlayer - remove a player"<<std::endl;
    std::cout<<"printInfo - select the username of an admin or player to print info about him"<<std::endl;
    std::cout<<"addHero - add a new hero to the shop"<<std::endl;
    std::cout<<"returnHero - select a hero that has been destroyed to bring him back to the shop"<<std::endl;
    std::cout<<"logOut - to log out"<<std::endl;
}

