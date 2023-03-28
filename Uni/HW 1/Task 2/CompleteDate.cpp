#include "CompleteDate.h"

CompleteDate::CompleteDate(): CompleteDate(1,1,1,0,0,0){}
CompleteDate::CompleteDate(size_t day, size_t month, size_t year,
                            size_t hours, size_t mins, size_t seconds): 
                            date(day,month, year), time(hours, mins, seconds){}

void CompleteDate::printDate() const{
    time.print(false);
    std::cout<<", ";
    date.print();
}
void CompleteDate::setDate(size_t day, size_t month, size_t year,
                size_t hours, size_t mins, size_t seconds){

    date.setDay(day);
    date.setMonth(month);
    date.setYear(year);
    time.setHours(hours);
    time.setSeconds(mins);
    time.setSeconds(seconds);
}

const Time& CompleteDate::getTime() const{
    return time;
}

const Date& CompleteDate::getDate() const{
    return date;
}
int CompleteDate::compare(const CompleteDate& other) const{
    return (date.compare(other.getDate()) != 0)? date.compare(other.getDate()) : time.compare(other.getTime());
}
