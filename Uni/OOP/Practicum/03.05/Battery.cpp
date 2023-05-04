#include "Battery.h"
Battery(const String& manufacturer, const String& descrpition, size_t capacity, const String& batteryId): CarPart(manufacturer, descrpition){
    this->setCapacity(capacity);
    this->setBatteryId(batteryId)

}


size_t Battery::getCapacity() const{
    return this->capacity;

}
const String& Battery::getBatteryId() const{
    return this->batteryId;

}

void Battery::setCapacity(size_t capacity){
    this->capacity = capacity;

}
void Battery::setBatteryId(const String& BatteryId){
    this->batteryId = BatteryId;

}

std::ostream& operator<<(std::ostream& os, const Battery& battery){

    return os<<(CarPart&)battery<<battery.getCapacity()<<" Ah";

}
