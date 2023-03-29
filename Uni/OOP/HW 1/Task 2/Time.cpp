#include "Time.h"

Time::Time(unsigned hours, unsigned mins, unsigned seconds)
{
	setHours(hours);
	setMins(mins);
	setSeconds(seconds);
}

Time::Time() : Time(0, 0, 0)
{}

Time::Time(unsigned seconds)
{
	hours = seconds / 3600;
	seconds %= 3600;

	mins = seconds / 60;
	seconds %= 60;

	this->seconds = seconds;
}


unsigned Time::getSeconds() const
{
	return seconds;
}
unsigned Time::getMins() const
{
	return mins;
}
unsigned Time::getHours() const
{
	return hours;
}

void Time::setSeconds(unsigned seconds)
{
	if (seconds > 59)
		seconds = 59;
	this->seconds = seconds;
}
void Time::setMins(unsigned mins)
{
	if (mins > 59)
		mins = 59;
	this->mins = mins;
}
void Time::setHours(unsigned hours)
{
	if (hours > 23)
		hours = 23;
	this->hours = hours;
}

void Time::tick()
{
	unsigned seconds = convertToSeconds();
	seconds++;
	Time newObj(seconds);

	*this = newObj; //êîïèå
}

int Time::compare(const Time& other) const
{
	unsigned mySeconds = convertToSeconds();
	unsigned otherSeconds = other.convertToSeconds();

	if (mySeconds > otherSeconds)
		return 1;
	else if (mySeconds < otherSeconds)
		return -1;
	else
		return 0;
}
Time Time::getDiff(const Time& other) const
{
	unsigned mySeconds = convertToSeconds();
	unsigned otherSeconds = other.convertToSeconds();

	unsigned diff;

	if (mySeconds > otherSeconds)
		diff = mySeconds - otherSeconds;
	else
		diff = otherSeconds - mySeconds;

	return Time(diff);
}

Time Time::getToMidnight() const
{
	Time midnight(23, 59, 59);
	Time diff = getDiff(midnight);
	diff.tick();
	return diff;
}
void Time::print(bool is12hoursclock) const
{
	if (hours < 10)
		std::cout << 0;
	std::cout << ((is12hoursclock && hours > 12) ? hours - 12 : hours) << ":";
	if (mins < 10)
		std::cout << 0;
	std::cout << mins << ":";
	if (seconds < 10)
		std::cout << 0;
	std::cout << seconds;
	if (is12hoursclock)
		std::cout << ((hours > 12) ? "PM" : "AM");
}