#include "System.h"


System::System(): System({"", "", "", "Admin", "password"}){
    
}
System::System(const Admin& admin): _admins(8, nullptr){
    _admins[0] = new Admin(admin);
    
}
System::~System(){
    for(size_t i {0}; i < _admins.size(); i++){
        delete _admins[i];
    }
    for(size_t i {0}; i < _players.size(); i++){
        delete _players[i];
    }
}

void System::addPlayer(const Player& player){
    _players.push_back(new Player (player));
    
}
void System::addAdmin(const Admin& admin){
    _admins.push_back(new Admin(admin));
    
}

