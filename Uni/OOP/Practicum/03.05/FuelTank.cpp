#include "FuelTank.h"

FuelTank::FuelTank(const String& manufacturer, const String& descrpition, double capacity): CarPart(manufacturer, descrpition){

}

void FuelTank::use(double toUse){
    if(toUse > this->currCap)
        throw insufficient_fuel_error("Insufficient Fuel");
        
    this->currCap -= toUse;
    
}

void FuelTank::fill(double toFill){
    this->currCap += toFill;
    if(this->currCap > this->maxCap)
        this->currCap = this->maxCap;
}

double FuelTank::getMaxCap() const{
    return this->maxCap;
}
double FuelTank::getCurrCap() const{
    return this->currCap;
}