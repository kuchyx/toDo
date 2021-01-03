#ifndef GETTERS_CPP
#define GETTERS_CPP

#include <vector>
#include "dataStructures.hpp"

std::string stringToTaskTitle(const std::string s)
{
	size_t firstCharacter = s.find(CHARACTER_BETWEEN_SECTIONTS);
	return s.substr(0, firstCharacter);
}

std::string stringToTime(const std::string s)
{
	size_t firstCharacter = s.find(CHARACTER_BETWEEN_SECTIONTS);
	return  s.substr(firstCharacter + SPACE_BETWEEN_TASK_PARTS, TIME_LENGTH);
}

std::string stringToStringDate(const std::string s)
{
	size_t firstCharacter = s.find(CHARACTER_BETWEEN_SECTIONTS);
	return s.substr(firstCharacter + SPACE_BETWEEN_TASK_PARTS, DATE_LENGTH);
}

Date stringToRealDate(const std::string s)
{
	Date newDate;
	newDate.day = std::stoi(s.substr(0, DAY_LENGTH));
	newDate.month = std::stoi(s.substr(MONTH_START, MONTH_LENGTH));
	newDate.year = std::stoi(s.substr(YEAR_START, YEAR_LENGTH));
	return newDate;
}

int stringToWhenRepeat(const std::string s)
{
	size_t firstCharacter = s.find(CHARACTER_BETWEEN_SECTIONTS);
	size_t secondCharacter = s.find(CHARACTER_BETWEEN_SECTIONTS, 
	firstCharacter + SPACE_BETWEEN_TASK_PARTS);
	return std::stoi(s.substr(secondCharacter + SPACE_BETWEEN_TASK_PARTS, WHEN_REPEAT_LENGTH));
}

Task stringToTask(const std::string s, int &currentTaskNumber) 
{
	Task outputTask;
	outputTask.title = stringToTaskTitle(s); 
	//dividedTasks.at(i).time = stringToTime(s);
	outputTask.date = stringToStringDate(s);
	outputTask.realDate = stringToRealDate(outputTask.date);
	outputTask.whenRepeat = stringToWhenRepeat(s);
	outputTask.number = currentTaskNumber;
	currentTaskNumber++;
	return outputTask;
}

std::vector <Task> getDividedTasks(const std::vector <std::string> fileLines)
{
	std::vector <Task> dividedTasks(fileLines.size());
	int currentTaskNumber = 0;
	for(unsigned int i = 0; i < fileLines.size(); i++)
	{
		std::string currentLine = fileLines.at(i);
		dividedTasks.at(i) = stringToTask(currentLine, currentTaskNumber);
	}
	return dividedTasks;
}


/*
std::vector <Time> getTime(std::vector <Task> dividedTasks)
{
	std::vector <Time> dividedTimes(dividedTasks.size());
	for(unsigned int i = 0; i < dividedTasks.size(); i++)
	{
		std::string hourS = dividedTasks.at(i).time.substr(0, 2);
		std::string minuteS = dividedTasks.at(i).time.substr(3, 2);
		dividedTimes.at(i).hour = std::stoi(hourS);
		dividedTimes.at(i).minute = std::stoi(minuteS);
	}
	return dividedTimes;
}*/

std::vector <Date> getDate(const std::vector <Task> dividedTasks)
{
	std::vector <Date> dividedDates(dividedTasks.size());
	for(unsigned int i = 0; i < dividedTasks.size(); i++)
	{
		dividedDates.at(i) = stringToRealDate(dividedTasks.at(i).date);
	}
	return dividedDates;
}

std::vector <std::string> getTitlesFromTask(const std::vector <Task> tasks)
{
	std::vector <std::string> titles;
	for(unsigned int i = 0; i < tasks.size(); i++)
	{
		titles.push_back(tasks.at(i).title);
	}
	return titles;
}

int getDaysFromMonth(const monthChecker month)
{
	if(month.isFebruary)
	{
		if(!month.isLeap) return DAYS_FEBRUARY_NOT_LEAP;
		else return DAYS_FEBRUARY_LEAP;
	}
	
	if(!month.isLongMonth) return DAYS_IN_SHORT_MONTH;
	else return DAYS_IN_LONG_MONTH;
	return 0;
}

int getDaysFromNormalDate(const Date realDate)
{
	return getDaysFromMonth(monthProperties(realDate.month, realDate.year));
}

#include "check.cpp"

std::vector <Task> getTasksToday(const std::vector <Task> dividedTasks)
{
	std::vector <Task> tasksToday;
	std::vector <Date> dividedDates = getDate(dividedTasks);
	for(unsigned int i = 0; i < dividedTasks.size(); i++)
	{
		if(taskForToday(dividedDates.at(i))) 
		{
			tasksToday.push_back(dividedTasks.at(i));
			tasksToday.at(tasksToday.size() - 1).show = 1;
		}
	}
	return tasksToday;
}

#endif