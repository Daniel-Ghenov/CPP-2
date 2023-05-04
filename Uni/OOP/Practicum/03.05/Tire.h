#pragma once
#include "CarPart.h"

class Tire: public CarPart{
private:
    size_t width;
    size_t profile;
    size_t diameter;
public:

    Tire() = default;
    Tire(const String& manufacturer, const String& descrpition, size_t width, size_t profile, size_t diameter);

    size_t getWidth() const;
    size_t getProfile() const;
    size_t getDiameter() const;

    void setWidth(size_t width);
    void setProfile(size_t profile);
    void setDiameter(size_t diameter);


};

std::ostream& operator<<(std::ostream& os, const Tire& tire);