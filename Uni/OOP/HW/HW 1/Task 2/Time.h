#pragma once
#include <iostream>

class Time
{
	unsigned seconds;		//Taken from Angel Dimitriev
	unsigned mins; 
	unsigned hours; 

	unsigned convertToSeconds() const
	{
		return 3600 * hours + 60 * mins + seconds;
	}


public:
	Time(); // 00:00:00
	Time(unsigned hours, unsigned mins, unsigned seconds);
	Time(unsigned seconds);


	unsigned getSeconds() const;
	unsigned getMins() const;
	unsigned getHours() const;

	void setSeconds(unsigned seconds);
	void setMins(unsigned mins);
	void setHours(unsigned hours);

	void tick();

	int compare(const Time& other) const;
	Time getDiff(const Time& other) const;

	Time getToMidnight() const;

	void print(bool is12hoursclock) const;

};