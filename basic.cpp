#ifndef BASIC_CPP
#define BASIC_CPP

#include <string>
#include <vector>
#include <iostream>
#include <windows.h>
#include "dataStructures.hpp"
#include "constants.hpp"

void print(const std::string s) { std::cout << s << std::endl; }
int charToInt(const char c) { return c - '0'; }

void e() { print("Poor man breakboint"); }

bool charIsNumber(const char c) { return c >= '0' && c <= '9'; }


void printErrorStringContainsNotNumber(const std::string s)
{
	std::cout << "string: \"" << s 
	<< "\" contains character different than number " << std::endl; 
}

void printNumberTooLow(const int number, const int min)
{
	std::cout << "number: " << number 
	<< " is too low. Minimal number is: " << min << std::endl;
}

void printNumberTooHigh(const int number, const int max)
{
	std::cout << "number: " << number 
	<< " is too high. Maximal number is: " << max << std::endl;
}

void printNotValidStringLength(const std::string s, const int desiredLength)
{
	std::cout << "String: \"" << s << "\" is too short/too long, it is: " 
	<< s.length() << " characters long but should be: " << desiredLength 
	<< " characters long " << std::endl;
}

void printInvalidCharacter(const char c, const char desiredCharacter)
{
	std::cout << "[ " << c << " ] Is invalid character, expected: [ " 
	<< desiredCharacter << " ]" << std::endl;
}

void printContainsIllegalCharacter(	const std::string s, 
									const char illegalCharacter )
{
	std::cout << "String: " << s << " consists of illegal sign: [" 
	<< illegalCharacter << "]!" << std::endl;
}


bool numberTooLow(const int number, const int min)
{
	if(number < min) 
	{
		printNumberTooLow(number, min);
		return 1;
	}
	return 0;
}

bool numberTooHigh(const int number, const int max)
{
	if(number > max) 
	{
		printNumberTooHigh(number, max);
		return 1;
	}
	return 0;
}

bool containsIllegalCharacter(const std::string s, const char illegalCharacter)
{
	if(	s.find(illegalCharacter) != std::string::npos)
	{
		printContainsIllegalCharacter(s, illegalCharacter);
		return 1;
	}
	return 0; 
}

void printTaskVector(const std::vector <Task> vector)
{
	print("Printing titles");
	for(unsigned int i = 0; i < vector.size(); i++) print(vector.at(i).title);
	//print("Printing times");
	//for(unsigned int i = 0; i < vector.size(); i++) print(vector.at(i).time);
	print("Printing dates");
	for(unsigned int i = 0; i < vector.size(); i++) print(vector.at(i).date);
}

/*
void printTimeVector(const std::vector <Time> vector)
{
	print("Printing hours");
	for(unsigned int i = 0; i < vector.size(); i++) 
		{
			std::cout << vector.at(i).hour << std::endl;
		}
	print("Printing minutes");
	for(unsigned int i = 0; i < vector.size(); i++) 
		{
			std::cout << vector.at(i).minute << std::endl;
		}
}*/

void printDate(const Date date)
{
	print("Printing Day");
	std::cout << date.day << std::endl;
	print("Printing Month");
	std::cout << date.month << std::endl;
	print("Printing Year");
	std::cout << date.year << std::endl;
}

void printDateVector(const std::vector <Date> vector)
{
	print("Printing Days");
	for(unsigned int i = 0; i < vector.size(); i++) 
	{
		std::cout << vector.at(i).day << std::endl;
	}
	print("Printing Months");
	for(unsigned int i = 0; i < vector.size(); i++) 
	{
		std::cout << vector.at(i).month << std::endl;
	}
	print("Printing Years");
	for(unsigned int i = 0; i < vector.size(); i++) 
	{
		std::cout << vector.at(i).year << std::endl;
	}
}

void printStringVector(const std::vector <std::string> vector)
{
	for(unsigned int i = 0; i < vector.size(); i++) print(vector.at(i));
}

void printTaskInfo(const Task task)
{
	std::cout << task.number  << ". " << task.title << "; " << task.date 
	<< "; " << task.whenRepeat << "; " << (task.completed ? "[X]" : "[]") 
	<< std::endl;
}

void printHighlightedTask(const std::vector <Task> vector, const int i)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, HIGHLIGHTED_COLOR);
	printTaskInfo(vector.at(i));
	SetConsoleTextAttribute(hConsole, NORMAL_COLOR);
}

void printOneStringColor(const std::vector <Task> vector, const int oneTask)
{
	int sizeOfVector = vector.size();
	for(int i = 0; i < sizeOfVector; i++)
	{
		if(vector.at(i).show == 1)
		{
			if(i == oneTask) printHighlightedTask(vector, i);
			else printTaskInfo(vector.at(i));
		}
	}
}

std::string normalDateToStringMonth(const Date realDate)
{
	std::string month;
	if(realDate.month < 10) month = "0" + std::to_string(realDate.month) + CHARACTER_BETWEEN_DATE;
	else month = std::to_string(realDate.month) + CHARACTER_BETWEEN_DATE;
	return month;
}

std::string normalDateToStringDay(const Date realDate)
{
	std::string day;
	if(realDate.day < 10) day = "0" + std::to_string(realDate.day) + CHARACTER_BETWEEN_DATE;
	else day = std::to_string(realDate.day) + CHARACTER_BETWEEN_DATE;
	return day;
}

std::string normalDateToString(const Date realDate)
{
 
	std::string day = normalDateToStringDay(realDate);
	std::string month = normalDateToStringMonth(realDate);
	std::string year = std::to_string(realDate.year);
	std::string stringToReturn = day + month + year;
	return stringToReturn;
}

std::string taskToString(const Task task)
{
	std::string outputString = task.title + CHARACTER_BETWEEN_SECTIONTS + " " 
							 + task.date + CHARACTER_BETWEEN_SECTIONTS + " " 
							 + std::to_string(task.whenRepeat);
	return outputString;
}

#endif