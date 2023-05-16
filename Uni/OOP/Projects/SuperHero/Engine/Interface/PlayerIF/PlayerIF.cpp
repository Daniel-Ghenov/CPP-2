#include "PlayerIF.h"


bool PlayerIF::logIn(){

    char username[USERNAME_LEN];
    String password;

    std::cout<<"Please enter a username and password:"<<std::endl;
    std::cin>>username>>password;

    try{
        _player = System::getSystem()->logInPlayer(username, password);

    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
        return false;
    }
    return true;
}

void PlayerIF::start(){
    while(!logIn());

    while(1){
        String command;
        std::cout<<"Please select a task to complete *you can use help to get a list of commands*"<<std::endl;
        std::cin>>command;

        if(command == "deleteAcc"){
            deleteAcc();
        }
        else if(command == "printInfo"){
            printInfo();
        }
        else if(command == "printScoreboard"){
            printScoreboard();
        }
        else if(command == "attack"){
            attack();
        }
        else if(command == "shop"){
            shop();
        }
        else if(command == "buy"){
            buy();
        }
        else if(command == "changeStance"){
            changeStance();
        }        
        else if(command == "help"){
            help();
        }
        else if(command == "logOut"){
            break;
        }
        else{
            std::cout<<"Command not recognised please try again:"<<std::endl;
        }
    }
}

void PlayerIF::deleteAcc(){

    String response;
    std::cout<<"This action is permanent, are you sure you want to do this"<<std::endl;
    std::cout<<"Please type in I am sure"<<std::endl;
    std::cin>>response;

    if(response != "I am sure"){
        return;
    }

    try{
        System::getSystem()->removePlayer(_player->username());

    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }
}

void PlayerIF::printInfo() const{

    char username[USERNAME_LEN];
    std::cout<<std::endl<<"Please enter the username of the player print Info for";
    std::cin>>username;

    try{
        System::getSystem()->printInfo(username);
    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }
}

void PlayerIF::printScoreboard(){
    
    char username[USERNAME_LEN];
    std::cout<<std::endl<<"Please enter the username of the player to print Info for";
    std::cin>>username;
    
    try{
        System::getSystem()->printInfo(username);
    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }
}

void PlayerIF::attack(){
    char username[USERNAME_LEN];
    std::cout<<std::endl<<"Please enter the username of the player you wish to attack";
    std::cin>>username;

    try{
        System::getSystem()->printInfo(username);
    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }

    String heroName;
    std::cout<<"Enter the hero name of the hero you wish to attack or press enter to chose a random one"<<std::endl;
    getline(std::cin, heroName);

    String attackerName;
    std::cout<<"Enter the hero name of the hero you wish to attack with"<<std::endl;

    getline(std::cin, attackerName);
    
    try{
        System::getSystem()->attack(_player->username(), attackerName, username, heroName);

    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }
}

void PlayerIF::shop(){
    System::getSystem()->printShop();
}

void PlayerIF::buy(){
    System::getSystem()->printShop();

    String heroName;
    std::cout<<"Enter the hero name of the hero you wish to buy"<<std::endl;
    getline(std::cin, heroName);

    try{
        System::getSystem()->buy(_player->username(), heroName);

    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }  
}

void PlayerIF::changeStance(){

    String heroName;
    std::cout<<"Enter the hero name of the hero you wish to change stances for"<<std::endl;
    getline(std::cin, heroName);

    try{
        _player->changeStance(heroName);

    }catch(std::exception& exc){
        std::cout<<exc.what()<<std::endl;
        std::cout<<"Please try again"<<std::endl;
    }  

}


void PlayerIF::help() const{

    std::cout<<"deleteAcc - delete your account"<<std::endl;
    std::cout<<"printInfo - print info for a player"<<std::endl;
    std::cout<<"printScoreboard - print the scoreboard of all players"<<std::endl;
    std::cout<<"attack - to attack a player"<<std::endl;
    std::cout<<"shop - to see the shop"<<std::endl;
    std::cout<<"buy - to buy a hero"<<std::endl;
    std::cout<<"changeStance to change the stance of a hero"<<std::endl;
    std::cout<<"logOut - to log out"<<std::endl;

}

