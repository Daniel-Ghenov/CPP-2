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
