#include "Car.h"

const double QuartMile = 0.4;

Car::Car(const Battery& battery, const Engine& engine, const FuelTank& tank, const Tire& tires, size_t drivenKM, size_t weight):
        battery(battery), engine(engine), tank(tank){

    this->setKM(drivenKM);
    this->weight = weight;

}
void Car::setKM(size_t km){

}
    
const FuelTank& Car::getFuelTank() const{
    return this->tank;

}
void Car::drive(double km){
    try{
        tank.use(km);
        this->drivenKM += km;
    }
    catch(const insufficient_fuel_error& error){
        throw error;
    }
}

size_t Car::getWeight() const{
    return weight;
}
size_t Car::getDriven() const{
    return drivenKM;
}

size_t Car::getHP() const{
    return engine.getHP();
}


Car* dragRace(Car* car1, Car* car2){
    bool hasFuel1 = false;
    bool hasFuel2 = false;
    try{
        car1->drive(QuartMile);
        hasFuel1 = true;
    }
    catch(const insufficient_fuel_error& error){}
    try{
        car2->drive(QuartMile);
        hasFuel2 = true;
    }catch(const insufficient_fuel_error& error){}

    if(!hasFuel1 && !hasFuel2)
        return nullptr;
    else if(!hasFuel2){
        return car1;
    }
    else if(!hasFuel1){
        return car2;
    }
    else{
        return ((car1->getWeight()/ car1->getHP()) > (car2->getWeight()/ car2->getHP()))? car1 : car2;
    }
}
