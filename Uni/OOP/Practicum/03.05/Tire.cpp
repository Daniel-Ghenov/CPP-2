#include "Tire.h"

Tire::Tire(const String& manufacturer, const String& descrpition, size_t width, size_t profile, size_t diameter): CarPart(manufacturer, descrpition){
    setWidth(width);
    setProfile(profile);
    setDiameter(diameter);
}


size_t Tire::getWidth() const{
    return this->width;
}
size_t Tire::getProfile() const{
    return this->profile;
}
size_t Tire::getDiameter() const{
    return this->diameter;    
}

void Tire::setWidth(size_t width){
    if(width < 155 || width > 365)
        throw std::invalid_argument("Width must be <= 365 and >= 155");
    
    this->width = width;
    
}
void Tire::setProfile(size_t profile){
    if(width < 30 || width > 80)
        throw std::invalid_argument("Width must be <= 80 and >= 30");
    
    this->profile = profile;
}
void Tire::setDiameter(size_t diameter){
    if(width < 13 || width > 21)
        throw std::invalid_argument("Width must be <= 21 and >= 13");
    
    this->diameter = diameter;
}


std::ostream& operator<<(std::ostream& os, const Tire& tire){
    return os<<(CarPart&)tire<<tire.getWidth()<<'/'<<tire.getProfile()<<"R"<<tire.getDiameter();
}
