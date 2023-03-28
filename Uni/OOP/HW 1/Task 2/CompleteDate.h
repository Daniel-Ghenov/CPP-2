#pragma once
#include "Time.h"
#include "Date.h"

class CompleteDate{
private:
    Time time;
    Date date;
public:
    CompleteDate();
    CompleteDate(size_t day, size_t month, size_t year,
                 size_t hours, size_t mins, size_t seconds);
    void printDate() const;
    void setDate(size_t day, size_t month, size_t year,
                 size_t hours, size_t mins, size_t seconds);
    const Time& getTime() const;
    const Date& getDate() const;
    int compare(const CompleteDate& other) const ;
};
