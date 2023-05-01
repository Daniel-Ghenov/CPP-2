#include "SuperHero.h"

const int BUFF_SIZE = 10;

SuperHero::SuperHero(const String& firstName, const String& lastName, const String& heroName, size_t power,
                size_t cost, Element element, Stance stance): _firstName(firstName), _lastName(lastName),
                _heroName(heroName), _power(power), _cost(cost), _element(element), _stance(stance){
        
    }

void SuperHero::print() const{
    std::cout<<"\tFirst name: "<<_firstName<<std::endl;
    std::cout<<"\tLast name: "<<_lastName<<std::endl;
    std::cout<<"\tHero name: "<<_heroName<<std::endl;
    std::cout<<"\tElement: "<<_element<<std::endl;
    std::cout<<"\tStance: "<<_stance<<std::endl;
}
void SuperHero::adminPrint() const{
    std::cout<<"\tFirst name: "<<_firstName<<std::endl;
    std::cout<<"\tLast name: "<<_lastName<<std::endl;
    std::cout<<"\tHero name: "<<_heroName<<std::endl;
    std::cout<<"\tPower: "<<_power<<std::endl;
    std::cout<<"\tElement: "<<_element<<std::endl;
    std::cout<<"\tStance: "<<_stance<<std::endl;
    
}

const String& SuperHero::firstName() const{
    return _firstName;
}
const String& SuperHero::lastName() const{
    return _lastName;
}
const String& SuperHero::heroName() const{
    return _heroName;
}
size_t SuperHero::power() const{
    return _power;
}
size_t SuperHero::cost() const{
    return _cost;
}
Element SuperHero::element() const{
    return _element;
}
Stance SuperHero::stance() const{
    return _stance;
}



std::ostream& operator<<(std::ostream& os, const Element& element){
    
    switch(element){
        case Element::fire :
            return os<<"Fire";
        case Element::water :
            return os<<"Water";
        case Element::earth :
            return os<<"Earth";
    }
}
std::ostream& operator<<(std::ostream& os, const Stance& stance){

    os<<"o";
    switch(stance){
        case Stance::attack :
            return os<<"Attack";
        case Stance::deffend :
            return os<<"Deffence";
    }
}

std::istream& operator>>(std::istream& is, Element& element){
    char buff[BUFF_SIZE];
    is>>buff;
    if(strcomp(buff, "Fire" ) == 0 || strcomp(buff, "fire" ) == 0){
        element = Element::fire;
    }
    else if(strcomp(buff, "Water" ) == 0 || strcomp(buff, "water" ) == 0){
        element = Element::water;
    }
    else
        element = Element::earth;

    return;
}
std::istream& operator>>(std::istream& is, Stance& stance){
    char buff[BUFF_SIZE];
    is>>buff;
    if(strcomp(buff,"Attack" ) == 0){
        stance = Stance::attack;
    }
    else
        stance = Stance::deffend;
    return;
}