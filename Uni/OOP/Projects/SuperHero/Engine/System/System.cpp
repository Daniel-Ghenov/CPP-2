#include "System.h"

System::System(): System({"", "", "", "admin", "Password1"}){
    
}
System::System(const Admin& admin): _admins(8, nullptr), _shop(8, nullptr), _players(8, nullptr){
    this->_admins[0] = new Admin(admin);
    
}
System::~System(){
    for(size_t i {0}; i < this->_admins.size(); i++){
        delete this->_admins[i];
    }
    for(size_t i {0}; i < this->_players.size(); i++){
        delete this->_players[i];
    }    
    for(size_t i {0}; i < this->_shop.size(); i++){
        delete this->_shop[i];
    }
}

void System::addPlayer(const Player& player){
    this->_players.push_back(new Player (player));
    
}
void System::addAdmin(const Admin& admin){
    this->_admins.push_back(new Admin(admin));
    
}
void System::addHero(const SuperHero& hero){
    this->_shop.push_back(new SuperHero(hero));

}

void System::removePlayer(size_t index){
    Player* temp = this->_players[index];
    this->_players[index] = this->_players[this->_players.size() - 1];
    this->_players[this->_players.size() - 1] = temp;
    this->_players.pop_back();
}

void System::removeAdmin(size_t index){
    Admin* temp = this->_admins[index];
    this->_admins[index] = this->_admins[this->_admins.size() - 1];
    this->_admins[this->_admins.size() - 1] = temp;
    this->_admins.pop_back();
}

void System::removeHero(size_t index){
    SuperHero* temp = this->_shop[index];
    this->_shop[index] = this->_shop[this->_shop.size() - 1];
    this->_shop[this->_shop.size() - 1] = temp;
    this->_shop.pop_back();

}

size_t System::findPlayer(const String& username) const{

    for(size_t i {0}; i < this->_players.size() ;i++){
        if(this->_players[i]->username() == username){
            return i;
        }
    }
    throw std::invalid_argument("User not Found");
}

size_t System::findAdmin(const String& username) const{

    for(size_t i {0}; i < this->_admins.size() ;i++){
        if(this->_admins[i]->username() == username){
            return i;
        }
    }
    throw std::invalid_argument("User not Found");
}

size_t System::findHero(const String& heroName) const{
    for(size_t i {0}; i < this->_shop.size() ;i++){
        if(this->_shop[i]->heroName() == heroName){
            return i;
        }
    }
    throw std::invalid_argument("User not Found");
}

void System::printInfo(const String& username) const{
    bool found = false;

    try{
        size_t index = findAdmin(username);
        _admins[index]->printAdmin();
        found = true;
    }catch(const std::invalid_argument& except){}

    
    try{
        size_t index = findPlayer(username);
        _players[index]->printAdmin();
        found = true;
    }catch(const std::invalid_argument& except){}
    
    if(!found)
        throw std::invalid_argument("User not Found");

}

void System::printScoreboard(){
    this->sortPlayers();
    for(size_t i {0}; i < _players.size(); i++){
        _players[i]->print();
        std::cout<<std::endl;
    }
}


void System::sortPlayers(){

    for(size_t i {0}; i < _players.size(); i++){
        bool swapped = false;
        for(size_t j = i ; i < _players.size() - i - 1; j++){
            if(_players[j]->money() < _players[j + 1]->money()){
                Player* temp = _players[j];
                _players[j] = _players[j + 1];
                _players[j + 1] = temp;
                swapped = true;
            }
        }
        if(!swapped)
            return;
    }
    
}
