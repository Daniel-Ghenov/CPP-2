#pragma once
#include "CarPart.h"
#include "Exception.h"

class FuelTank: public CarPart{
private:
    double maxCap;
    double currCap;
public:
    FuelTank() = default;
    FuelTank(const String& manufacturer, const String& descrpition, double capacity);
    
    void use(double toUse);
    void fill(double toFill);
    double getMaxCap() const;
    double getCurrCap() const;
};