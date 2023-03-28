#include "TimeDate.h"

TimeDate::TimeDate(): TimeDate(1,1,1,0,0,0){}
TimeDate::TimeDate(unsigned day, unsigned month, unsigned year,
                            unsigned hours, unsigned mins, unsigned seconds): 
                            date(day,month, year), time(hours, mins, seconds){}

void TimeDate::printDate() const{
    time.print(false);
    std::cout<<", ";
    date.print();
}
void TimeDate::setDate(unsigned day, unsigned month, unsigned year,
                unsigned hours, unsigned mins, unsigned seconds){

    date.setDay(day);
    date.setMonth(month);
    date.setYear(year);
    time.setHours(hours);
    time.setSeconds(mins);
    time.setSeconds(seconds);
}

const Time& TimeDate::getTime() const{
    return time;
}

const Date& TimeDate::getDate() const{
    return date;
}
int TimeDate::compare(const TimeDate& other) const{
    return (date.compare(other.getDate()) != 0)? date.compare(other.getDate()) : time.compare(other.getTime());
}
