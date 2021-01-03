#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>
#include <vector>
#include "dataStructures.hpp"

// user menu choices 
const int CHOICE_LENGTH = 1;
const int MAX_CHOICE = 2;
const int QUIT = 0;
const int CHECK_TODAY = 1;
const int ADD_TASK = 2;

// Constants for user choosing how often he wants to repeat
const int NEVER_REPEAT = 0;
const int EVERY_DAY = 1;
const int EVERY_WEEK = 2;
const int EVERY_MONTH = 3;
const int EVERY_YEAR = 4;
const int WHEN_REPEAT_MIN = 0;
const int WHEN_REPEAT_MAX = 4;
const int WHEN_REPEAT_LENGTH = WHEN_REPEAT_MAX >= 10 ? 2 : 1;

const int HOURS_IN_DAY = 24;  // THIS ONE _IS_ USED
// Constants for checking time input, CURRENTLY UNUSED
const int TIME_LENGTH = 5;
const int MINUTES_IN_HOUR = 59;
const int FIRST_HOUR_NUMBER = 0;
const int SECOND_HOUR_NUMBER = 1;
const int COLON_NUMBER = 2;
const int FIRST_MINUTE_NUMBER = 3;
const int SECOND_MINUTE_NUMBER = 4;

// Constants for checking Date
const int STARTING_CHRONO_YEAR = 1900;
const int YEAR_LENGTH = 4;
const int MONTH_LENGTH = 2;
const int DAY_LENGTH = 2;
const int EXTRA_DATE_CHARACTERS = 2;
const int MONTH_START = DAY_LENGTH + 1;
const int YEAR_START = DAY_LENGTH + MONTH_LENGTH + EXTRA_DATE_CHARACTERS;
const int DATE_LENGTH = YEAR_LENGTH + MONTH_LENGTH + DAY_LENGTH + EXTRA_DATE_CHARACTERS;
const int MIN_YEAR = 2020;
const int MAX_YEAR = 2099;
const int MIN_MONTH = 1;
const int MAX_MONTH = 12;
const int DAYS_IN_LONG_MONTH = 31;
const int DAYS_IN_SHORT_MONTH = 30;
const int DAYS_FEBRUARY_LEAP = 29;
const int DAYS_FEBRUARY_NOT_LEAP = 28;
const int FIRST_DAY_NUMBER = 0;
const int FIRST_DATE_SLASH = 2;
const int FIRST_MONTH_NUMBER = 3;
const int SECOND_DATE_SLASH = 5;
const int FIRST_YEAR_NUMBER = 6;
const int DAYS_IN_WEEK = 7;
// constants for validAddTaskInput() from valid.cpp
const int CHECK_TITLE = 0;

//const int CHECK_TIME = 1;
const int CHECK_DATE = 2;
const int CHECK_WHEN_REPEAT = 3;

// some Tasks constants ¯\_(ツ)_/¯
const int SPACE_BETWEEN_TASK_PARTS = 2;
const int MIN_TASKS = 0;


// "UI" colors
const int YELLOW_ON_BLACK = 14;
const int WHITE_ON_BLACK = 15;
const int BLACK_ON_WHITE = 240;
const int HIGHLIGHTED_COLOR = BLACK_ON_WHITE;
const int NORMAL_COLOR = WHITE_ON_BLACK;

//months
const int JANUARY = 1;
const int FEBRUARY = 2;
const int MARCH = 3;
const int APRIL = 4;
const int MAY = 5;
const int JUNE = 6;
const int JULY = 7;
const int AUGUST = 8;
const int SEPTEMBER = 9;
const int OCTOBER = 10;
const int NOVEMBER = 11;
const int DECEMBER = 12;

//currently unused
//const int ADD_REPEATING_TASK = 3;

//Way tasks look in task files
const char CHARACTER_BETWEEN_SECTIONTS = ';';
const char CHARACTER_BETWEEN_TIME = ':';
const char CHARACTER_BETWEEN_DATE = '/';

//User menu inputs
const char SPACE = 32;
const char ESCAPE = 27;
const char KEY_UP = 72;
const char KEY_DOWN = 80;
const char KEY_LEFT = 75;
const char KEY_RIGHT = 77;



const std::string MENU = "What do you want to do?\n0. Quit\n1. Check Today\n2. Add task";
const std::string WHEN_REPEAT_MENU = "When do you want to repeat the task? \n0. NEVER\n1. every day\n2. Weekly\n3. Monthly\n4. Yearly";
const std::string CHECK_TODAY_INFO = "Tasks for today: ESCAPE to exit, SPACE to complete";
const std::string FILE_NAME_NORMAL_TASK = "Tasks.txt";
const std::string FILE_NAME_REPEATING_TASK = "repeatTasks.txt";
const char* CLEAR_SCREEN_WINDOWS = "CLS";


const std::vector <std::string> INPUT_INFO = {"Enter task title: ", 
"Enter time: using format HH:MM", 
"Enter date: using format DD/MM/YYYY ",
WHEN_REPEAT_MENU};
const std::vector <int> LONGER_MONTHS = {JANUARY, MARCH, MAY, JULY, AUGUST, 
OCTOBER, DECEMBER};

#endif


