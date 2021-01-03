#ifndef DATA_STRUCTURES_HPP
#define DATA_STRUCTURES_HPP

#include <string>
#include "constants.hpp"

/*
struct Time{
	int hour;
	int minute;
};*/

struct Date{
	int day;
	int month;
	int year;
};

struct Task{
	std::string title;
	//std::string time;
	Date realDate;
	std::string date;
	int whenRepeat;
	bool completed = 0;
	bool show = 0;
	int number;
};

/*
struct repeatTask{
	std::string title;
	int whenRepeat;
	Date lastCompleted;
	int number;
}; */

struct monthChecker{
	bool isFebruary;
	bool isLongMonth;
	bool isLeap;
};

#endif