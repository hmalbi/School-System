#pragma once
#pragma once
#include <string>
#include "Person.h"
#include "Resours.h"
using namespace std;

class Date : public Resours
{
protected:
	int day;
	int month;
	int year;
public:
	Date();
	Date(string, string, string);
	int getday();
	void setday(string);
	int getmonth();
	void setmonth(string);
	int getyear();
	void setyear(string);
	bool isLeapYear(int);
	int getTotalDaysInYears(int);
	int getNumOfDaysInMonth(int, int);
	int getTotalDaysInMonths(int, int);
	void camputedateoftoday(int *, int *, int *);
	~Date();
};

