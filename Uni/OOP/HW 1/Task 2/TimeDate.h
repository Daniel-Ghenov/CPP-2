#pragma once
#include "Time.h"
#include "Date.h"

class TimeDate{
private:
    Time time;
    Date date;
public:
    TimeDate();
    TimeDate(unsigned day, unsigned month, unsigned year,
                 unsigned hours, unsigned mins, unsigned seconds);
    void printDate() const;
    void setDate(unsigned day, unsigned month, unsigned year,
                 unsigned hours, unsigned mins, unsigned seconds);
    const Time& getTime() const;
    const Date& getDate() const;
    int compare(const TimeDate& other) const ;
};