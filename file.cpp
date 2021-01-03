#ifndef FILE_CPP
#define FILE_CPP

#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "dataStructures.hpp"
#include "constants.hpp"

void fileAddTask(const Task taskToAdd)
{
	std::fstream taskList;
	taskList.open(FILE_NAME_NORMAL_TASK, std::ios_base::app);
	taskList << taskToAdd.title << CHARACTER_BETWEEN_SECTIONTS << " " 
	<< taskToAdd.date << CHARACTER_BETWEEN_SECTIONTS << " " 
	<< taskToAdd.whenRepeat << std::endl;
	taskList.close();
}

/*
void fileAddRepeatingTask(const repeatTask taskToAdd)
{
	std::fstream taskList;
	taskList.open(FILE_NAME_REPEATING_TASK, std::ios_base::app);
	taskList << taskToAdd.title << CHARACTER_BETWEEN_SECTIONTS << " " 
	<< taskToAdd.whenRepeat << CHARACTER_BETWEEN_SECTIONTS << " " 
	<< taskToAdd.lastCompleted.day << "/" << taskToAdd.lastCompleted.month 
	<< "/" << taskToAdd.lastCompleted.year << std::endl;
	taskList.close();
}*/

std::vector <std::string> removeCompleted(	const std::vector <std::string> fileList, 
											const std::vector <Task> tasksToday)
{
	std::vector <std::string> tempList = fileList;

	for(unsigned int i = 0; i < tasksToday.size(); i++)
	{
		std::vector<std::string>::iterator currLine = 	tempList.begin() + 
														tasksToday.at(i).number;
		if(tasksToday.at(i).completed) tempList.erase(currLine);
		else
		{
			std::string lineS = taskToString(tasksToday.at(i));
			tempList.at(tasksToday.at(i).number) = lineS;

		}
	}
	return tempList;
}

void vectorToFile(const std::vector <std::string> strings, std::ofstream &file)
{
	for(unsigned int i = 0; i < strings.size(); i++)
	{
		file << strings.at(i) << std::endl;
	}
}


void outputFile(const std::vector <std::string> fileLines)
{
	std::ofstream taskList;
	taskList.open(FILE_NAME_NORMAL_TASK);
	vectorToFile(fileLines, taskList);
}

std::vector <std::string> fileToVector(std::ifstream &file, std::vector <std::string> strings)
{
	std::string line;
	if(file.is_open())
	{
		while(getline(file, line))
		{
			strings.push_back(line);
		}
		file.close();
	}
	return strings;
}

std::vector <std::string> readList()
{
	std::ifstream taskList (FILE_NAME_NORMAL_TASK);
	std::vector <std::string> fileLines;
	return fileToVector(taskList, fileLines);
}

#endif