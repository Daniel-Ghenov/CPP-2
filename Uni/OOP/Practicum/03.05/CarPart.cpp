#include "CarPart.h"

size_t CarPart::instances = 1;

CarPart::CarPart(){
    instances++;
    id = instances;
}

CarPart::CarPart(const String& manufacturer, const String& descrpition){
    instances++;
    id = instances;

}
CarPart::CarPart(const CarPart& other): manufacturer(other.manufacturer), description(other.description), id(other.id){

}

CarPart::CarPart(CarPart&& other): manufacturer(std::move(other.manufacturer)), description(std::move(other.description)){
    
}
CarPart& CarPart::operator=(const CarPart& other){
    manufacturer = other.manufacturer;
    description = other.description;
    id = other.id;
}


CarPart& CarPart::operator=(CarPart&& other){
    this->manufacturer = std::move(other.manufacturer);
    this->description = std::move(other.description);
    this->id = other.id;

}
void CarPart::setManufacturer(const String& manufacturer){
    this->manufacturer = manufacturer;

}
void CarPart::setDescription(const String& description){
    this->description = description;

}

size_t CarPart::getId() const {
    return this->id;

}
const String& CarPart::getManufacturer() const{
    return this->manufacturer;

}
const String& CarPart::getDescription() const{
    return this->description;

}


std::ostream& operator<<(std::ostream& os, const CarPart& part){
    return os<<part.getId()<<"by "<<part.getManufacturer()<<" - "<<part.getDescription()<<" - ";
}
