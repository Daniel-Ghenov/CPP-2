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
void SuperHero::changeStance(){
    
    if(_stance == Stance::attack)
        _stance = Stance::deffend;
    else
        _stance = Stance::attack;
}

void SuperHero::saveToBinary(std::ofstream& ofs) const{
    if(!ofs.is_open()){
        throw std::runtime_error("File not open");
    }

    ofs.write((const char *) _firstName.size(), sizeof(_firstName.size()));
    ofs.write(_firstName.data(), _firstName.size());

    ofs.write((const char *) _lastName.size(), sizeof(_lastName.size()));
    ofs.write(_lastName.data(), _lastName.size());
    
    ofs.write((const char *) _heroName.size(), sizeof(_heroName.size()));
    ofs.write(_heroName.data(), _heroName.size());

    ofs.write((const char*)_power, sizeof(_power));
    ofs.write((const char*)_cost, sizeof(_cost));
    ofs.write((const char*)_element, sizeof(_element));
    ofs.write((const char*)_stance, sizeof(_stance));

}
void SuperHero::loadFromBinary(std::ifstream& ifs){
    if(!ifs.is_open()){
        throw std::runtime_error("File not open");
    }
    size_t size;
    char* data;

    ifs.read((char*) size, sizeof(size));   //reading size then setting a buffer and copying to a string
    data = new char[size];
    ifs.read(data, size);
    _firstName = data;
    delete[] data;

    ifs.read((char*) size, sizeof(size));   //reading size then setting a buffer and copying to a string
    data = new char[size];
    ifs.read(data, size);
    _lastName = data;
    delete[] data;

    ifs.read((char*) size, sizeof(size));   //reading size then setting a buffer and copying to a string
    data = new char[size];
    ifs.read(data, size);
    _heroName = data;
    delete[] data;

    ifs.read((char*)_power, sizeof(_power));
    ifs.read((char*)_cost, sizeof(_cost));
    ifs.read((char*)_element, sizeof(_element));
    ifs.read((char*)_stance, sizeof(_stance));
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
    return os;
}
std::ostream& operator<<(std::ostream& os, const Stance& stance){

    os<<"o";
    switch(stance){
        case Stance::attack :
            return os<<"Attack";
        case Stance::deffend :
            return os<<"Deffence";
    }
    return os;
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

    return is;
}
std::istream& operator>>(std::istream& is, Stance& stance){
    char buff[BUFF_SIZE];
    is>>buff;
    if(strcomp(buff,"Attack" ) == 0){
        stance = Stance::attack;
    }
    else
        stance = Stance::deffend;
    return is;
}



bool dominates(const Element& element1, const Element& element2){

    if((element1 == Element::fire && element2 == Element::earth) ||
       (element1 == Element::earth && element2 == Element::water)||
       (element1 == Element::water && element2 == Element::fire))
       return true;
    
    return false;
}
