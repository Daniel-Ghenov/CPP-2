#include "Player.h"


Player::Player(size_t money, Vector<SuperHero> heroes): _money(money), _heroes(heroes){

}


void Player::addHero(SuperHero&& hero){
    if(_money < hero.cost()){
        throw std::runtime_error("Not enough Money");
    }
    _money -= hero.cost();

    _heroes.push_back(std::move(hero));

}
void Player::addHero(const SuperHero& hero){
    if(_money < hero.cost()){
        throw std::runtime_error("Not enough Money");
    }
    _money -= hero.cost();

    _heroes.push_back(hero);

}

void Player::removeHero(const SuperHero* hero){

    for(size_t i {0}; i < _heroes.size(); i++){
        if(hero == &(_heroes[i])){
            SuperHero temp = _heroes[i];
            _heroes[i] = _heroes[_heroes.size() - 1];
            _heroes[_heroes.size() - 1] = temp;
            _heroes.pop_back();
            return;
        }
    }

    throw std::invalid_argument("Hero not Found");

}

void Player::attack(const SuperHero* first, const SuperHero* second, Player* other){

    size_t firstAttack = (dominates(first->element(), second->element()))? first->power() * DOMINATE_MULT : first->power();
    size_t secondAttack = (dominates(second->element(), first->element()))? second->power() * DOMINATE_MULT : second->power();

    if(second->stance() == Stance::deffend){
        if(firstAttack > secondAttack){
            try{
            other->removeHero(second);
            }catch(std::invalid_argument& err){
                throw std::invalid_argument("PLayer / Hero missmatch error");
            }
        }
    }
    else{
        if(firstAttack > secondAttack){
            if( other->_money < firstAttack - secondAttack){
                _money += other->_money;
                other->_money = 0;
            }
            else{
                _money += firstAttack - secondAttack;
                other->_money -= firstAttack - secondAttack;
            }            
            
            try{
            other->removeHero(second);
            }catch(std::invalid_argument& err){
                throw std::invalid_argument("PLayer / Hero missmatch error");
            }
        }
        else if(firstAttack == secondAttack){
            _money = (_money < EQUALL_LOSS)? 0 : _money - EQUALL_LOSS;
        }
        else{
            other->_money += ATTACK_LOSS;
            _money = (_money < (secondAttack - firstAttack) * 2)? 0 : _money - (secondAttack - firstAttack) * 2;
        }
    }
}
void Player::print() const{
    std::cout<<"Username: "<< username()<<"Money: "<<_money<<std::endl;
    std::cout<<"Heroes: "<<std::endl;

    for(size_t i {0}; i < _heroes.size(); i++){
        _heroes[i].print();
    }
}
void Player::adminPrint() const{
    std::cout<<"Username: "<< username()<<"Money: "<<_money<<std::endl;
    std::cout<<"Heroes: "<<std::endl;

    for(size_t i {0}; i < _heroes.size(); i++){
        _heroes[i].adminPrint();
    }
}
size_t Player::money() const{
    return _money;
}


void Player::saveToBinary(std::ofstream& ofs) const{
    if(!ofs.is_open()){
        throw std::runtime_error("File not open");
    }

    User::saveToBinary(ofs);
    ofs.write((const char*)_money, sizeof(_money));
    ofs.write((const char*) _heroes.size(), sizeof(_heroes.size()));
    for(size_t i {0}; i < _heroes.size(); i++){
        _heroes[i].saveToBinary(ofs);
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
        _heroes[i].loadFromBinary(ifs);
    }
}