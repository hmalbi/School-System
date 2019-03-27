#include "Date.h"


Date::Date()
{
	day = 1;
	month = 1;
	year = 2015;
}

Date::Date(string d, string m, string y){
	day = atoi(d.c_str());
	month = atoi(m.c_str());
	year = atoi(y.c_str());
}

int Date::getday(){
	return day;
}

void Date::setday(string d){
	day = atoi(d.c_str());
}

int Date::getmonth(){
	return month;
}

void Date::setmonth(string m){
	month = atoi(m.c_str());
}

int Date::getyear(){
	return year;
}

void Date::setyear(string y){
	year = atoi(y.c_str());
}

/** Determine if it is a leap year */
bool Date::isLeapYear(int year)
{
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		return true;

	return false;
}

/** Get the total number of days from Jan 1, 1970 to the specified year */
int Date::getTotalDaysInYears(int year)
{
	int total = 0;
	// Get the total days from 1970 to the specified year
	for (int i = 1970; i <= year; i++)
	if (isLeapYear(i))
		total = total + 366;
	else
		total = total + 365;
	return total;
}
/** Get the number of days in a month */
int Date::getNumOfDaysInMonth(int year, int month)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	if (month == 2)
	if (isLeapYear(year))
		return 29;
	else
		return 28;
	return 0; // If month is incorrect.
}
/** Get the total number of days from Jan 1 to the month in the year */
int Date::getTotalDaysInMonths(int year, int month)
{
	int total = 0;
	// Add days from Jan to the month
	for (int i = 1; i <= month; i++)
		total = total + getNumOfDaysInMonth(year, i);

	return total;
}
void Date::camputedateoftoday(int *day, int *month, int *year)
{
	// Obtain the total seconds since the midnight, Jan 1, 1970
	int totalSeconds = time(0);
	// Compute the current second in the minute in the hour
	int currentSecond = (int)(totalSeconds % 60);
	// Obtain the total minutes
	int totalMinutes = totalSeconds / 60;
	// Compute the current minute in the hour
	int currentMinute = (int)(totalMinutes % 60);
	// Obtain the total hours
	int totalHours = totalMinutes / 60;
	// Compute the current hour
	int currentHour = (int)(totalHours % 24);
	// Compute the total days
	int totalDays = (int)(totalHours / 24);
	if (currentHour > 0) totalDays++;
	// Obtain Year
	int currentYear = 2000;
	do
	{
		currentYear++;
	} while (getTotalDaysInYears(currentYear) < totalDays);
	// Obtain Month
	int totalNumOfDaysInTheYear = totalDays - getTotalDaysInYears(currentYear - 1);
	int currentMonth = 0;
	do
	{
		currentMonth++;
	} while (getTotalDaysInMonths(currentYear, currentMonth) < totalNumOfDaysInTheYear);
	// Obtain Day
	int currentDay = totalNumOfDaysInTheYear - getTotalDaysInMonths(currentYear, currentMonth - 1);
	// Display results
	*day = currentDay;
	*month = currentMonth;
	*year = currentYear;
}

Date::~Date()
{
}

