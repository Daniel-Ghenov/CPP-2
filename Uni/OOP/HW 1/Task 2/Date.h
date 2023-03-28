#pragma once
#include <iostream>

class Date
{
	unsigned MAX_DAYS[12] =		//Taken from Angel Dimitriev
	{
		31,28,31,30,31,30,31,31,30,31,30,31
	};
	size_t day = 1;
	size_t month = 1;
	size_t year = 1;

	bool isLeapYear() const;

	mutable bool isModified = true;
	mutable int dayOfWeek = -1;

public:
	Date();
	Date(size_t day, size_t month, size_t year);
	size_t getDay() const;
	size_t getMonth() const;
	size_t getYear() const;

	void setDay(size_t day);
	void setMonth(size_t month);
	void setYear(size_t year);

	bool isEqualTo(const Date& d) const;

	void print() const;
	void goToNextDay();
	int getDayOfWeek() const;

	int compare(const Date& d) const;

};