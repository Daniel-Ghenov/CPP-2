#pragma once
#include "CarPart.h"

class Battery: public CarPart{
private:
    size_t capacity;
    String batteryID;

public:
    Battery() = default;
    Battery(const String& manufacturer, const String& descrpition, size_t capacity, const String& batteryId);

    size_t getCapacity() const;
    const String& getBatteryId() const;

    void setCapacity(size_t capacity);
    void setBatteryId(const String& BatteryId);

};

std::ostream& operator<<(std::ostream& os, const Battery& battery);