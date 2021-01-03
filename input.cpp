#ifndef INPUT_CPP
#define INPUT_CPP

#include <iostream>
#include "dataStructures.hpp"
#include "constants.hpp"
#include "allFunctions.hpp"

std::string inputTaskTitle(const int whatToCheck)
{
	std::string input;
	system(CLEAR_SCREEN_WINDOWS);
	do
	{
		print(INPUT_INFO.at(whatToCheck));
		getline(std::cin, input);
	}while(!validAddTaskInput(input, whatToCheck));
	return input;
}

Date inputTaskDate(const int whatToCheck)
{
	std::string input;
	system(CLEAR_SCREEN_WINDOWS);
	do
	{
		print(INPUT_INFO.at(whatToCheck));
		getline(std::cin, input);
	}while(!validAddTaskInput(input, whatToCheck));
	return stringToRealDate(input);
}

int inputTaskWhenRepeat(const int whatToCheck)
{
	std::string input;
	system(CLEAR_SCREEN_WINDOWS);
	do
	{
		print(INPUT_INFO.at(whatToCheck));
		getline(std::cin, input);
	}while(!validAddTaskInput(input, whatToCheck));
	return std::stoi(input);
}

Task inputTask()
{
	Task fullTask;
	fullTask.title = inputTaskTitle(CHECK_TITLE);
	// fullTask.time = inputTaskOneLine(CHECK_TIME);
	fullTask.realDate = inputTaskDate(CHECK_DATE);
	fullTask.date = normalDateToString(fullTask.realDate);
	fullTask.whenRepeat = inputTaskWhenRepeat(CHECK_WHEN_REPEAT);
	return fullTask;
} 

int whenRepeatTask()
{
	std::string choiceS;
	do{
		print(WHEN_REPEAT_MENU);
		getline(std::cin, choiceS);
	}while(!checkRepeat(choiceS));
	return charToInt(choiceS.at(0));
}

/*
repeatTask inputRepeatingTask()
{
	repeatTask fullTask;
	fullTask.title = inputTaskOneLine(CHECK_TITLE);
	fullTask.whenRepeat = whenRepeatTask();
	fullTask.lastCompleted.day = 1;
	fullTask.lastCompleted.month = 1;
	fullTask.lastCompleted.year = 2020;
	return fullTask;
} */


int inputMenu()
{
	std::string choiceS;
	do{
		system(CLEAR_SCREEN_WINDOWS);
		print(MENU);
		getline(std::cin, choiceS);
	}while(!checkMenu(choiceS));
	return charToInt(choiceS.at(0));;
}

void continueProgram(const int &userChoice)
{
	if(userChoice == CHECK_TODAY) checkToday();
	else if(userChoice == ADD_TASK) fileAddTask(inputTask());
	else print("No such choice available");
}

bool menuLoop()
{
	int userChoice = inputMenu();
	if(userChoice == QUIT) return 1;
	else continueProgram(userChoice);
	return 0;
}

#endif