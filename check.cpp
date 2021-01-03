#ifndef CHECK_CPP
#define CHECK_CPP

#include <ctime>
#include <chrono>
#include "dataStructures.hpp"
#include "constants.hpp"
#include "allFunctions.hpp"

bool checkLongerMonth(const int month)
{
	for(unsigned int i = 0; i < LONGER_MONTHS.size(); i++)
	{
		if(month == LONGER_MONTHS.at(i)) return 1;
	}
	return 0;
}

bool checkTitle(const std::string title)
{
	if(containsIllegalCharacter(title, CHARACTER_BETWEEN_SECTIONTS)) return 0;
	if(title.empty())
	{
		print("Title is empty!");
		return 0;
	}
	return 1;
}


/*
bool checkTime(const std::string time)
{
	if(!validStringLength(time, TIME_LENGTH)) return 0;
	
	std::string hourS = time.substr(FIRST_HOUR_NUMBER, 2);
	if(!validNumberInput(hourS, 0, HOURS_IN_DAY)) return 0;
	
	if(!validCharacter(time.at(COLON_NUMBER), CHARACTER_BETWEEN_TIME)) return 0;
	
	std::string minutesS = time.substr(FIRST_MINUTE_NUMBER, 2);
	if(!validNumberInput(minutesS, 0, MINUTES_IN_HOUR)) return 0;
	return 1;
} */


bool checkLeap(const int year)
{
	return (!(year % 4) && year % 100) || !(year % 400);
}

bool checkMenu(const std::string input)
{
	if(!validStringLength(input, CHOICE_LENGTH)) return 0;
	if(!charIsNumber(input.at(0))) return 0;
	return 1;
}

bool checkRepeat(const std::string input)
{
	if(!validStringLength(input, CHOICE_LENGTH)) return 0;
	if(!charIsNumber(input.at(0))) return 0;
	if(!validNumberInput(input, 0, WHEN_REPEAT_MAX)) return 0;
	return 1;
}

bool taskDaySameAsToday(const Date dateFromFile, const Date currentDate)
{
	return dateFromFile.day == currentDate.day
	&& dateFromFile.month == currentDate.month
	&& dateFromFile.year == currentDate.year;
}

Date getCurrentDate(const tm local_tm)
{
	Date currentDate;
	currentDate.year = local_tm.tm_year + STARTING_CHRONO_YEAR;
	currentDate.month = local_tm.tm_mon + 1;  // First month is represented as "0"?
	currentDate.day = local_tm.tm_mday;
	return currentDate;
}

tm getTmNow()
{
	using namespace std;
    using namespace std::chrono;
    typedef duration<int, ratio_multiply<hours::period, ratio<HOURS_IN_DAY> >::type> days;
    system_clock::time_point now = system_clock::now();
    system_clock::duration tp = now.time_since_epoch();
    tp -= duration_cast<days>(tp);
    tp -= duration_cast<hours>(tp);
    tp -= duration_cast<minutes>(tp);
    tp -= duration_cast<seconds>(tp);
    time_t tt = system_clock::to_time_t(now);
    //tm utc_tm = *gmtime(&tt);
    return *localtime(&tt);
}

// Copied from: https://stackoverflow.com/a/15958113
bool taskForToday(const Date dateFromFile)  // TO;DO: Figure out how it works
{
	Date currentDate = getCurrentDate(getTmNow());
	if(taskDaySameAsToday(dateFromFile, currentDate)) return 1;
	else return 0;
}

bool validYear(const std::string date)
{
	std::string yearS = date.substr(FIRST_YEAR_NUMBER, YEAR_LENGTH);
	if(!validNumberInput(yearS, MIN_YEAR, MAX_YEAR)) return 0;
	return 1;
}

bool validMonth(const std::string date)
{
	std::string monthS = date.substr(FIRST_MONTH_NUMBER, 2);
	if(!validNumberInput(monthS, MIN_MONTH, MAX_MONTH)) return 0;
	return 1;
}

int stringDateToYear(const std::string date)
{
	return std::stoi(date.substr(FIRST_YEAR_NUMBER, YEAR_LENGTH));
}

int stringDateToMonth(const std::string date)
{
	return std::stoi(date.substr(FIRST_MONTH_NUMBER, MONTH_LENGTH));
}

monthChecker monthProperties(const int monthNumber, const int year)
{
	monthChecker month;
	month.isLeap = checkLeap(year);
	month.isFebruary = (monthNumber == FEBRUARY);
	month.isLongMonth = 0;
	if(!month.isFebruary) month.isLongMonth = checkLongerMonth(monthNumber);
	return month;
}

bool validDays(const monthChecker month, const std::string date)
{
	int daysInMonth = getDaysFromMonth(month);
	std::string dayS = date.substr(FIRST_DAY_NUMBER, DAY_LENGTH);
	if(!validNumberInput(dayS, 0, daysInMonth)) return 0;
	else return 1;
}

bool validDays(const std::string date)
{
	int yearInt = stringDateToYear(date);
	int monthInt = stringDateToMonth(date);
	monthChecker month = monthProperties(monthInt, yearInt);
	return validDays(month, date);
}

bool checkDate(const std::string date)
{
	if(!validStringLength(date, DATE_LENGTH)) return 0;
	if(!validYear(date)) return 0;
	if(!validMonth(date)) return 0;
	if(!validDays(date)) return 0; 
	
	char firstSlash = date.at(FIRST_DATE_SLASH);
	char secondSlash = date.at(SECOND_DATE_SLASH);
	if(!validCharacter(firstSlash, CHARACTER_BETWEEN_DATE)) return 0;
	if(!validCharacter(secondSlash, CHARACTER_BETWEEN_DATE)) return 0;
	return 1;
}


bool checkWhenRepeat(const std::string whenRepeat)
{
	if(!validStringLength(whenRepeat, WHEN_REPEAT_LENGTH)) return 0;
	if(!validNumberInput(whenRepeat, WHEN_REPEAT_MIN, WHEN_REPEAT_MAX)) return 0;
	return 1;
}


#endif