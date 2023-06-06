#include "System.h"


System::System(){
    srand(time(NULL));

    std::ifstream ifs(SAVEFILE_NAME, std::ios::in | std::ios::binary);
    if(ifs.is_open()){
        loadFromBinary(ifs);
    }else
        _admins.push_back(new Admin({"", "", "", "admin", "Password1"}));

    
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
        throw std::logic_error("Username is taken");
    
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
    try{
        findHero(hero.heroName());
        throw std::logic_error("Hero exists");

    }catch(std::invalid_argument& err){
        _shop.push_back(new SuperHero(hero));
    }

}


void System::returnHero(size_t index){
    _shop.push_back(_graveyard[index]);
    std::swap(_graveyard[index], _graveyard[_graveyard.size() - 1]);
    _graveyard.pop_back();
}

void System::removePlayer(const char* username){
    size_t index = findAdmin(username);
    SharedPtr<Player> temp = _players[index];
    _players[index] = _players[_players.size() - 1];
    _players[_players.size() - 1] = temp;
    _players.pop_back();
}

void System::removeAdmin(const char* username){
    size_t index = findPlayer(username);
    SharedPtr<Admin> temp = _admins[index];
    _admins[index] = _admins[_admins.size() - 1];
    _admins[_admins.size() - 1] = temp;
    _admins.pop_back();
}

void System::removeHero(size_t index){
    SharedPtr<SuperHero> temp = _shop[index];
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
    throw std::invalid_argument("Hero not Found");
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

    try{
        size_t index = findAdmin(username);
        _admins[index]->adminPrint();
        return;
    }catch(const std::invalid_argument& except){}

    
    try{
        size_t index = findPlayer(username);
        _players[index]->adminPrint();
        return;
    }catch(const std::invalid_argument& except){}
    
    throw std::invalid_argument("User not Found");

}

bool System::shopEmpty() const{
    return _shop.empty();
}
bool System::graveyardEmpty() const{
    return _graveyard.empty();
}



SharedPtr<Player> System::logInPlayer(const char* username, const String& password){
    for(size_t i {0}; i < _players.size(); i++){
        if(password == _players[i]->password() && (strcomp(username, _players[i]->username()) == 0)){
            if(_cycleStart == _players[i]){
                endCycle();
                _cycleStart = nullptr;
            }else if(_cycleStart == nullptr){
                _cycleStart = _players[i];
            }
            return _players[i];
        }
    }
    throw std::invalid_argument("Incorrect username and/or password");
}
SharedPtr<Admin> System::logInAdmin(const char* username, const String& password){

    for(size_t i {0}; i < _admins.size(); i++){
        if(password == _admins[i]->password() && (strcomp(username, _admins[i]->username()) == 0)){
            return _admins[i];
        }
    }
    throw std::invalid_argument("Incorrect username and/or password");
}

void System::endCycle(){
    for(size_t i {0}; i < _players.size(); i++){
        _players[i]->setMoney(_players[i]->money() + CYCLE_MONEY);
    }
}


void System::saveToBinary(std::ofstream& ofs) const{
    if(!ofs.is_open()){
        throw std::runtime_error("File not open");
    }

    size_t size = _admins.size();
    ofs.write((const char*)&size, sizeof(size));
    for(size_t i {0}; i < _admins.size(); i++){
        _admins[i]->saveToBinary(ofs);
    }

    size = _players.size();
    ofs.write((const char*)&size, sizeof(size));
    for(size_t i {0}; i < _players.size(); i++){
        _players[i]->saveToBinary(ofs);
    }

    size = _shop.size();
    ofs.write((const char*)&size, sizeof(size));
    for(size_t i {0}; i < _shop.size(); i++){
        _shop[i]->saveToBinary(ofs);
    }

    size = _graveyard.size();
    ofs.write((const char*)&size, sizeof(size));
    for(size_t i {0}; i < _graveyard.size(); i++){
        _graveyard[i]->saveToBinary(ofs);
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
    ifs.read((char*)&size, sizeof(size));
    _admins.clear();
    for(size_t i {0}; i < size; i++){
        _admins.push_back(new Admin());
        _admins[i]->loadFromBinary(ifs);
    }

    ifs.read((char*)&size, sizeof(size));
    _players.clear();

    for(size_t i {0}; i < size; i++){
        _players.push_back(new Player());
        _players[i]->loadFromBinary(ifs);
    }

    ifs.read((char*)&size, sizeof(size));
    _shop.clear();

    for(size_t i {0}; i < size; i++){
        _shop.push_back(new SuperHero());
        _shop[i]->loadFromBinary(ifs);
    }

    ifs.read((char*)&size, sizeof(size));
    _graveyard.clear();
    for(size_t i {0}; i < size; i++){
        _graveyard.push_back(new SuperHero());
        _graveyard[i]->loadFromBinary(ifs);
    }

    char tempUsr[USERNAME_LEN];
    ifs.read(tempUsr, USERNAME_LEN);

    if(tempUsr[0] == '\0')
        _cycleStart = nullptr;
    else
        _cycleStart = _players[findPlayer(tempUsr)];
    
}

void System::attack(const char* attackerUsername, const String& attackerHeroName , const char* deffenderUsername, const String& deffendHeroName){

    SharedPtr<Player> attacker = _players[findPlayer(attackerUsername)];
    SharedPtr<SuperHero> deffendHero;
    SharedPtr<SuperHero> attackHero = attacker->heroes()[attacker->findHero(attackerHeroName)];
    
    SharedPtr<Player> deffender = _players[findPlayer(deffenderUsername)];

    if(deffendHeroName == ""){
        deffendHero = deffender->heroes()[rand() % deffender->heroes().size()];  //setting the deffending hero to a random one
    }else{
        deffendHero = deffender->heroes()[deffender->findHero(deffendHeroName)];
    }

    size_t attackHeroAttack = (dominates(attackHero->element(), deffendHero->element()))? attackHero->power() * DOMINATE_MULT : attackHero->power();    //setting attack with multipliers
    size_t deffendHeroAttack = (dominates(deffendHero->element(), attackHero->element()))? deffendHero->power() * DOMINATE_MULT : deffendHero->power();

    if(deffendHero->stance() == Stance::deffend){   //if the deffeding hero is in deffence stance we only check if we should remove it
        if(attackHeroAttack > deffendHeroAttack){
            _graveyard.push_back(deffendHero);
            deffender->removeHero(deffendHero);
        }
    }
    else{
        if(attackHeroAttack > deffendHeroAttack){
            if( deffender->money() < attackHeroAttack - deffendHeroAttack){
                attacker->setMoney(attacker->money() + deffender->money());
                deffender->setMoney(0);
            }
            else{
                attacker->setMoney(attacker->money() + (attackHeroAttack - deffendHeroAttack));
                deffender->setMoney(deffender->money() - (attackHeroAttack - deffendHeroAttack));
            }            
            _graveyard.push_back(deffendHero);
            deffender->removeHero(deffendHero);
        }
        else if(attackHeroAttack == deffendHeroAttack){
            attacker->setMoney((attacker->money() < EQUALL_LOSS)? 0 : attacker->money() - EQUALL_LOSS);
        }
        else{
            deffender->setMoney(deffender->money() + ATTACK_LOSS);
            attacker->setMoney((attacker->money() < (deffendHeroAttack - attackHeroAttack) * 2)? 0 : attacker->money() - (deffendHeroAttack - attackHeroAttack) * 2);
        }
    }
}
void System::buy(const char* buyerUsername, const String& heroName){
    
    size_t index = findHero(heroName);
    _players[findPlayer(buyerUsername)]->addHero(_shop[index]);
    std::swap(_shop[index], _shop[_shop.size() - 1]);
    _shop.pop_back();
}


void System::printScoreboard(){
    sortPlayers();
    for(size_t i {0}; i < _players.size(); i++){
        std::cout<<i + 1<<": "<<_players[i]->username()<<", Money: "<<_players[i]->money();
        std::cout<<std::endl;
    }
}
void System::printGraveyard() const noexcept{

    for(size_t i {0}; i < _graveyard.size(); i++){
        std::cout<<i<<": ";
        _graveyard[i]->print();
        std::cout<<std::endl;
    }
}
void System::printShop() const noexcept{

    for(size_t i {0}; i < _shop.size(); i++){
        std::cout<<i + 1<<": ";
        _shop[i]->adminPrint();
        std::cout<<std::endl;
    }
}

void System::changeStance(const char* playerUsername,const String& heroName){
    _players[findPlayer(playerUsername)]->changeStance(heroName);
}

void System::sortPlayers(){

    for(size_t i {0}; i < _players.size(); i++){
        bool swapped = false;
        for(size_t j = i ; j < _players.size() - i - 1; j++){
            if(_players[j]->money() < _players[j + 1]->money()){
                SharedPtr<Player> temp = _players[j];
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

    std::ofstream ofs(SAVEFILE_NAME, std::ios::out | std::ios::binary);
    if(!ofs.is_open()){
        throw std::runtime_error("Cannot Save System");
    }
    saveToBinary(ofs);
    ofs.close();

}

System* System::getSystem(){
    static System sys;

    return &sys;
}
