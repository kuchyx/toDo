#ifndef VALID_HPP
#define VALID_HPP

#include <iostream>
#include "dataStructures.hpp"
#include "constants.hpp"
#include "allFunctions.hpp"

bool validString(const std::string s)
{
	for(unsigned int i = 0; i < s.length(); i++)
	{
		if(!charIsNumber(s.at(i)))
		{
			printErrorStringContainsNotNumber(s);
			return 0;
		}
	}
	return 1;
}

bool validNumberInput(const std::string input, const int min, const int max)
{
	if(!validString(input)) return 0;
	int inputInt = std::stoi(input);
	if(numberTooLow(inputInt, min)) return 0;
	if(numberTooHigh(inputInt, max)) return 0;
	return 1;
}

bool validStringLength(const std::string s, const int desiredLength)
{
	int stringLength = s.length();
	if(stringLength != desiredLength)
	{
		printNotValidStringLength(s, desiredLength);
		return 0;
	}
	return 1;
}

bool validCharacter(const char inputC, const char desiredC)
{
	if(inputC != desiredC) 
	{
		printInvalidCharacter(inputC, desiredC);
		return 0;
	}
	return 1;
}



bool validAddTaskInput(const std::string input, const int inputType)
{
	if(inputType == CHECK_TITLE) return checkTitle(input);
	//if(inputType == CHECK_TIME) return checkTime(input);
	if(inputType == CHECK_DATE) return checkDate(input);
	if(inputType == CHECK_WHEN_REPEAT) return checkWhenRepeat(input);
	else return 0;
}

#endif