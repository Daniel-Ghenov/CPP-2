#pragma once
#include "Battery.h"
#include "Engine.h"
#include "FuelTank.h"
#include "Tire.h"

class Car{
private:
    Battery battery;
    Engine engine;
    FuelTank tank;
    Tire tires[4];

    size_t drivenKM;
    size_t weight;

    void setKM(size_t km);
public:
    Car(const Battery& battery, const Engine& engine, const FuelTank& tank, const Tire& tires, size_t drivenKM, size_t weight);

    const FuelTank& getFuelTank() const;
    void drive(double km);

    size_t getWeight() const;
    size_t getDriven() const;

    size_t getHP() const;

};

Car* dragRace(const Car* car1, Car* car2);