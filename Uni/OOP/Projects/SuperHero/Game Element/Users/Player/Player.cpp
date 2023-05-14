#include "Player.h"


Player::Player(const String& firstName, const String& lastName, const String& email, const char* username, const String& password, size_t money, Vector<SuperHero*> heroes):
                User(firstName, lastName, email, username, password), _money(money), _heroes(heroes){

}
Player::~Player(){
    free();
}
Player::Player(const Player& other){
    copyFrom(other);
}
Player::Player(Player&& other){
    move(std::move(other));
}
Player& Player::operator=(const Player& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}
Player& Player::operator=(Player&& other){
    if(this != &other){
        free();
        move(std::move(other));
    }
    return *this;
}

void Player::addHero(SuperHero* hero){
    if(_money < hero->cost()){
        throw std::runtime_error("Not enough Money");
    }
    _money -= hero->cost();

    _heroes.push_back(hero);

}
size_t Player::findHero(const String& heroName){

    for(size_t i {0}; i < _heroes.size() ;i++){
        if(_heroes[i]->heroName() == heroName){
            return i;
        }
    }
    throw std::invalid_argument("Hero not Found");
}

void Player::removeHero(const SuperHero* hero){

    for(size_t i {0}; i < _heroes.size(); i++){
        if(hero == _heroes[i]){
            SuperHero* temp = _heroes[i];
            _heroes[i] = _heroes[_heroes.size() - 1];
            _heroes[_heroes.size() - 1] = temp;
            _heroes.pop_back();
            return;
        }
    }

    throw std::invalid_argument("Hero not Found");

}

void Player::print() const{
    std::cout<<"Username: "<< username()<<"Money: "<<_money<<std::endl;
    std::cout<<"Heroes: "<<std::endl;

    for(size_t i {0}; i < _heroes.size(); i++){
        _heroes[i]->print();
    }
}
void Player::adminPrint() const{
    std::cout<<"Username: "<< username()<<"Money: "<<_money<<std::endl;
    std::cout<<"Heroes: "<<std::endl;

    for(size_t i {0}; i < _heroes.size(); i++){
        _heroes[i]->adminPrint();
    }
}

void Player::changeStance(const String& heroName){
    _heroes[findHero(heroName)]->changeStance();
}

size_t Player::money() const{
    return _money;
}
size_t Player::setMoney(size_t money){
    _money = money;
}
const Vector<SuperHero*>& Player::heroes() const{
    return _heroes;
}


void Player::saveToBinary(std::ofstream& ofs) const{
    if(!ofs.is_open()){
        throw std::runtime_error("File not open");
    }

    User::saveToBinary(ofs);
    ofs.write((const char*)_money, sizeof(_money));
    ofs.write((const char*) _heroes.size(), sizeof(_heroes.size()));
    for(size_t i {0}; i < _heroes.size(); i++){
        _heroes[i]->saveToBinary(ofs);
    }

}

void Player::loadFromBinary(std::ifstream& ifs){
    if(!ifs.is_open()){
        throw std::runtime_error("File not open");
    }
    User::loadFromBinary(ifs);

    ifs.read((char*)_money, sizeof(_money));
    size_t size;
    ifs.read((char*) size, sizeof(size));
    _heroes.reserve(size * 2);
    for(size_t i {0}; i < size; i++){
        _heroes[i]->loadFromBinary(ifs);
    }
}

void Player::copyFrom(const Player& other){
    _heroes.reserve(other._heroes.size());

    for(size_t i {0}; i < other._heroes.size(); i++){
        _heroes[i] = new SuperHero(*other._heroes[i]);
    }
}
void Player::move(Player&& other){

    _heroes.reserve(other._heroes.size());
    for(size_t i {0}; i < other._heroes.size(); i++){
        _heroes[i] = other._heroes[i];
        other._heroes.clear();
    }
}

void Player::free(){
    for(size_t i {0}; i < _heroes.size(); i++){
        delete[] _heroes[i];
    }
}
