#ifndef OUTPUT_CPP
#define OUTPUT_CPP
#include <conio.h>
#include "allFunctions.hpp"
#include "datastructures.hpp"


void readTasksToday(const std::vector <Task> dividedTasks)
{
	std::vector <Date> dividedDates = getDate(dividedTasks);
	for(unsigned int i = 0; i < dividedTasks.size(); i++)
	{
		if(taskForToday(dividedDates.at(i))) print(dividedTasks.at(i).title);
	}
}

void printInfoAndTitlesColor(const std::string userInfo, const std::vector <Task> tasksToday, const int currentTask)
{
	system(CLEAR_SCREEN_WINDOWS);
	print(userInfo);
	printOneStringColor(tasksToday, currentTask);
}

std::vector <Task> getTasksTodayFromNothing()
{
	std::vector <std::string> fileList = readList();
	std::vector <Task> dividedTasks = getDividedTasks(fileList);
	std::vector <Task> tasksToday = getTasksToday(dividedTasks);
	return tasksToday;
}

int up(int currentTask, const int maxTasks, const std::vector <Task> tasksToday)
{
	if(currentTask - 1 >= MIN_TASKS) currentTask--;
	else currentTask = maxTasks;
	printInfoAndTitlesColor(CHECK_TODAY_INFO, tasksToday, currentTask);
	return currentTask;
}

int down(int currentTask, const int maxTasks, const std::vector <Task> tasksToday)
{
	if(currentTask + 1 <= maxTasks) currentTask++;
	else currentTask = MIN_TASKS;
	printInfoAndTitlesColor(CHECK_TODAY_INFO, tasksToday, currentTask);
	return currentTask;
}

Task modifyRepeatNever(Task &currentTask)
{
	currentTask.completed = !currentTask.completed;
	return currentTask;
}


Task modifyRepeatYear(Task &currentTask)
{
	currentTask.realDate.year++;
	currentTask.date = normalDateToString(currentTask.realDate);
	currentTask.show = 0;
	return currentTask;
}

Task modifyRepeatMonth(Task &currentTask)
{
	if(currentTask.realDate.month == DECEMBER) 
	{
		modifyRepeatYear(currentTask);
		currentTask.realDate.month = JANUARY;
	}
	else currentTask.realDate.month++;
	currentTask.date = normalDateToString(currentTask.realDate);
	currentTask.show = 0;
	return currentTask;
}

Task modifyRepeatWeek(Task &currentTask)
{
	if(currentTask.realDate.day + DAYS_IN_WEEK >  getDaysFromNormalDate(currentTask.realDate))
	{
		currentTask.realDate.day = DAYS_IN_WEEK - (getDaysFromNormalDate(currentTask.realDate) - currentTask.realDate.day);
		modifyRepeatMonth(currentTask);
		currentTask.date = normalDateToString(currentTask.realDate);
	}else
	{
		currentTask.realDate.day += DAYS_IN_WEEK;
		currentTask.date = normalDateToString(currentTask.realDate);
	}
	currentTask.show = 0;
	return currentTask;
}

Task modifyRepeatDay(Task &currentTask)
{
	if(currentTask.realDate.day + 1 > getDaysFromNormalDate(currentTask.realDate))
	{
		modifyRepeatMonth(currentTask);
		currentTask.realDate.day = 1;
		currentTask.date = normalDateToString(currentTask.realDate);
	}else
	{
		currentTask.realDate.day++;
		currentTask.date = normalDateToString(currentTask.realDate);
	}
	currentTask.show = 0;
	return currentTask;
}


Task modifyDate(Task &currentTask)
{
	if(currentTask.whenRepeat == NEVER_REPEAT) return modifyRepeatNever(currentTask);
	else if(currentTask.whenRepeat == EVERY_DAY) return modifyRepeatDay(currentTask);
	else if(currentTask.whenRepeat == EVERY_WEEK) return modifyRepeatWeek(currentTask);
	else if(currentTask.whenRepeat == EVERY_MONTH) return modifyRepeatMonth(currentTask);
	else if(currentTask.whenRepeat == EVERY_YEAR) return modifyRepeatYear(currentTask);
	else return currentTask;
}

std::vector <Task> space(const int currentTask, std::vector <Task> &tasksToday)
{
	if(tasksToday.size() == 0) return tasksToday;
	modifyDate(tasksToday.at(currentTask));
	printInfoAndTitlesColor(CHECK_TODAY_INFO, tasksToday, currentTask);
	return tasksToday;
}



std::vector <Task> moveThroughTaskList(std::vector <Task> &tasksToday)
{
	int maxTasks = tasksToday.size() - 1;
	int currentTask = MIN_TASKS;
	int c = 0;
	while(c != ESCAPE)
    {
		c = 0;
        switch((c=getch())) 
		{
			case KEY_UP:
				currentTask = up(currentTask, maxTasks, tasksToday);
				break;
			case KEY_DOWN:
				currentTask = down(currentTask, maxTasks, tasksToday);
				break;
			case SPACE:
				tasksToday = space(currentTask, tasksToday);
				break;
        }
    }
	return tasksToday;
}

std::vector <std::string> detectKeys()
{
	std::vector <Task> tasksToday = getTasksTodayFromNothing();
	printInfoAndTitlesColor(CHECK_TODAY_INFO, tasksToday, MIN_TASKS);
	tasksToday = moveThroughTaskList(tasksToday);
	return removeCompleted(readList(), tasksToday);
}

void checkToday() { outputFile(detectKeys()); }

#endif