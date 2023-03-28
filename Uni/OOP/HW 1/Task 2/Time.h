#pragma once
#include <iostream>

class Time
{
	size_t seconds;		//Taken from Angel Dimitriev
	size_t mins; 
	size_t hours; 

	size_t convertToSeconds() const
	{
		return 3600 * hours + 60 * mins + seconds;
	}


public:
	Time(); // 00:00:00
	Time(size_t hours, size_t mins, size_t seconds);
	Time(size_t seconds);


	size_t getSeconds() const;
	size_t getMins() const;
	size_t getHours() const;

	void setSeconds(size_t seconds);
	void setMins(size_t mins);
	void setHours(size_t hours);

	void tick();

	int compare(const Time& other) const;
	Time getDiff(const Time& other) const;

	Time getToMidnight() const;

	void print(bool is12hoursclock) const;

};