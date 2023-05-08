#include "System.h"

System::System(): System({"", "", "", "admin", "Password1"}){
    
}
System::System(const Admin& admin): _admins(8, nullptr), _shop(8, nullptr), _players(8, nullptr){
    _admins[0] = new Admin(admin);
    
}
System::~System(){

    free();

}

void System::addPlayer(const Player& player){
    bool exists = false;
    try{
        findPlayer(player.username());
        exists = true;
    }catch(std::invalid_argument& err){}

    try{
        findAdmin(player.username());
        exists = true;
    }catch(std::invalid_argument& err){}    //if we do not get an error in both try blocks then the user exists;

    if(!exists)
        _players.push_back(new Player(player));
    else
        throw std::logic_error("User exists");
    
}
void System::addAdmin(const Admin& admin){

        bool exists = false;
    try{
        findPlayer(admin.username());
        exists = true;
    }catch(std::invalid_argument& err){}

    try{
        findAdmin(admin.username());
        exists = true;
    }catch(std::invalid_argument& err){}    //if we do not get an error in both try blocks then the user exists;

    if(!exists)
        _admins.push_back(new Admin(admin));
    else
        throw std::logic_error("User exists");

    
}
void System::addHero(const SuperHero& hero){
    _shop.push_back(new SuperHero(hero));

}

void System::removePlayer(size_t index){
    Player* temp = _players[index];
    _players[index] = _players[_players.size() - 1];
    _players[_players.size() - 1] = temp;
    _players.pop_back();
}

void System::removeAdmin(size_t index){
    Admin* temp = _admins[index];
    _admins[index] = _admins[_admins.size() - 1];
    _admins[_admins.size() - 1] = temp;
    _admins.pop_back();
}

void System::removeHero(size_t index){
    SuperHero* temp = _shop[index];
    _shop[index] = _shop[_shop.size() - 1];
    _shop[_shop.size() - 1] = temp;
    _shop.pop_back();

}

size_t System::findPlayer(const char* username) const{

    for(size_t i {0}; i < _players.size() ;i++){
        if(strcomp(_players[i]->username(), username) == 0){
            return i;
        }
    }
    throw std::invalid_argument("User not Found");
}

size_t System::findAdmin(const char* username) const{

    for(size_t i {0}; i < _admins.size() ;i++){
        if(strcomp(_admins[i]->username(), username) == 0){
            return i;
        }
    }
    throw std::invalid_argument("User not Found");
}

size_t System::findHero(const String& heroName) const{
    for(size_t i {0}; i < _shop.size() ;i++){
        if(_shop[i]->heroName() == heroName){
            return i;
        }
    }
    throw std::invalid_argument("User not Found");
}

void System::printInfo(const char* username) const{

    try{
        size_t index = findPlayer(username);
        _players[index]->print();
    }catch(const std::invalid_argument& except){
        throw std::invalid_argument("Player not found");
    }
}


void System::printAdminInfo(const char* username) const{
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

bool System::emptyShop() const{
    return _shop.empty();
}


Player* System::logInPlayer(const char* username, const String& password){
    for(size_t i {0}; i < _players.size(); i++){
        if(password == _players[i]->password() && (strcomp(username, _players[i]->username()) == 0)){
            if(_cycleStart == _players[i]){
                _cycleStart = nullptr;
            }else if(_cycleStart == nullptr){
                _cycleStart = _players[i];
            }
            return _players[i];
        }
    }
    throw std::invalid_argument("Incorrect username and/or password");
}
Admin* System::logInAdmin(const char* username, const String& password){

    for(size_t i {0}; i < _admins.size(); i++){
        if(password == _admins[i]->password() && (strcomp(username, _admins[i]->username()) == 0)){
            if(emptyShop()){
                
            }
            return _admins[i];
        }
    }
    throw std::invalid_argument("Incorrect username and/or password");
}

void System::endCycle(){
    for(size_t i {0}; i < _players.size(); i++){
        _players[i]->_money += CYCLE_MONEY;
    }
}


void System::saveToBinary(std::ofstream& ofs) const{
    if(!ofs.is_open()){
        throw std::runtime_error("File not open");
    }

    ofs.write((const char*)_admins.size(), sizeof(_admins.size()));
    for(size_t i {0}; i < _admins.size(); i++){
        _admins[i]->saveToBinary(ofs);
    }

    ofs.write((const char*)_players.size(), sizeof(_players.size()));
    for(size_t i {0}; i < _players.size(); i++){
        _players[i]->saveToBinary(ofs);
    }

    ofs.write((const char*)_shop.size(), sizeof(_shop.size()));
    for(size_t i {0}; i < _shop.size(); i++){
        _shop[i]->saveToBinary(ofs);
    }
    
    if(_cycleStart)
        ofs.write(_cycleStart->username(), USERNAME_LEN);
    else
        ofs.write("\0", 1);
}
void System::loadFromBinary(std::ifstream& ifs){
    if(!ifs.is_open()){
        throw std::runtime_error("File not open");
    }

    size_t size;
    ifs.read((char*) size, sizeof(size));
    _admins.reserve(size * 2);
    for(size_t i {0}; i < size; i++){
        _admins[i] = new Admin();
        _admins[i]->loadFromBinary(ifs);
    }

    ifs.read((char*) size, sizeof(size));
    _players.reserve(size * 2);
    for(size_t i {0}; i < size; i++){
        _players[i] = new Player();
        _players[i]->loadFromBinary(ifs);
    }

    ifs.read((char*) size, sizeof(size));
    _shop.reserve(size * 2);
    for(size_t i {0}; i < size; i++){
        _shop[i] = new SuperHero();
        _shop[i]->loadFromBinary(ifs);
    }

    char tempUsr[USERNAME_LEN];
    ifs.read(tempUsr, USERNAME_LEN);

    if(tempUsr == '\0')
        _cycleStart = nullptr;
    else
        _cycleStart = _players[findPlayer(tempUsr)];
    
}
void System::printScoreboard(){
    sortPlayers();
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

void System::free(){

    std::ofstream ofs(FILE_NAME, std::ios::out | std::ios::binary);
    saveToBinary(ofs);
    ofs.close();

    for(size_t i {0}; i < _admins.size(); i++){
        delete _admins[i];
    }
    for(size_t i {0}; i < _players.size(); i++){
        delete _players[i];
    }    
    for(size_t i {0}; i < _shop.size(); i++){
        delete _shop[i];
    }  
}
