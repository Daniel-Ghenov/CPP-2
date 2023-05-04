#pragma once
#include <iostream>
#include "MyString.h"

class CarPart{
private:
    size_t id;
    String manufacturer;
    String description;
    static size_t instances;

public:
    CarPart();
    CarPart(const String& manufacturer, const String& descrpition);
    CarPart(const CarPart& other);
    CarPart(CarPart&& other);
    CarPart& operator=(CarPart&& other);
    CarPart& operator=(const CarPart& other);
    
    void setManufacturer(const String& manufacturer);
    void setDescription(const String& description);

    size_t getId() const ;
    const String& getManufacturer() const;
    const String& getDescription() const;


    friend std::ostream& operator<<(std::ostream& os, const CarPart& part);

};

std::ostream& operator<<(std::ostream& os, const CarPart& part);