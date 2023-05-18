#include "Player.h"


Player::Player(const String& firstName, const String& lastName, const String& email, const char* username, const String& password, size_t money, Vector<SharedPtr<SuperHero>> heroes):
                User(firstName, lastName, email, username, password), _money(money), _heroes(heroes){

}
void Player::addHero(SharedPtr<SuperHero>& hero){
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

void Player::removeHero(const SharedPtr<SuperHero>& hero){

    for(size_t i {0}; i < _heroes.size(); i++){
        if(_heroes[i] == hero){
            SharedPtr<SuperHero> temp = _heroes[i];
            _heroes[i] = _heroes[_heroes.size() - 1];
            _heroes[_heroes.size() - 1] = temp;
            _heroes.pop_back();
            return;
        }
    }

    throw std::invalid_argument("Hero not Found");

}

void Player::print() const{
    std::cout<<"Username: "<< username()<<std::endl;
    std::cout<<"Money: "<<_money<<std::endl;
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
void Player::setMoney(size_t money){
    _money = money;
}
const Vector<SharedPtr<SuperHero>>& Player::heroes() const{
    return _heroes;
}


void Player::saveToBinary(std::ofstream& ofs) const{
    if(!ofs.is_open()){
        throw std::runtime_error("File not open");
    }

    User::saveToBinary(ofs);
    
    ofs.write((const char*)&_money, sizeof(_money));
    size_t size = _heroes.size();
    ofs.write((const char*)&size, sizeof(size));
    for(size_t i {0}; i < size; i++){
        _heroes[i]->saveToBinary(ofs);
    }

}

void Player::loadFromBinary(std::ifstream& ifs){
    if(!ifs.is_open()){
        throw std::runtime_error("File not open");
    }
    User::loadFromBinary(ifs);

    ifs.read((char*)&_money, sizeof(_money));
    size_t size;
    ifs.read((char*)&size, sizeof(size));
    _heroes.clear();
    for(size_t i {0}; i < size; i++){
        _heroes.push_back(new SuperHero());
        _heroes[i]->loadFromBinary(ifs);
    }
}
