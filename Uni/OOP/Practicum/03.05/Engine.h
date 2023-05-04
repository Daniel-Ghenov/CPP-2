#pragma once
#include "CarPart.h"

class Engine: public CarPart{
private:
    size_t HP;

public:
    Engine() = default;
    Engine(const String& manufacturer, const String& descrpition, size_t HP);

    void setHP(size_t horsepower);

    size_t getHP() const;
};  

std::ostream& operator<<(std::ostream& os, const Engine& engine);