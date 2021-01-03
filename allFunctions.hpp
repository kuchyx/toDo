#ifndef ALL_FUNCTIONS_HPP
#define ALL_FUNCTIONS_HPP

#include <string>
#include "dataStructures.hpp"
#include "constants.hpp"

//basic.cpp
int charToInt(const char c);
void print(const std::string s);
bool charIsNumber(const char c);
int getDaysFromMonth(const monthChecker month);
void printOneStringColor(const std::vector <Task> vector, const int oneTask);
void printDate(const Date date);
void printErrorStringContainsNotNumber(const std::string s);
void printNumberTooLow(const int number, const int min);
void printNumberTooHigh(const int number, const int max);
void printNotValidStringLength(const std::string s, const int desiredLength);
void printInvalidCharacter(const char c, const char desiredCharacter);
bool numberTooLow(const int number, const int min);
bool numberTooHigh(const int number, const int max);
void printStringVector(const std::vector <std::string> vector);

//check.cpp
bool checkLongerMonth(const int month);
bool checkMenu(const std::string input);
bool checkTitle(const std::string title);
bool checkTime(const std::string time);
bool checkLeap(const int year);
bool checkDate(const std::string date);
bool taskForToday(const Date dateFromFile);
bool checkRepeat(const std::string input);
bool checkWhenRepeat(const std::string whenRepeat);

//file.cpp
void fileAddTask(const Task taskToAdd);
std::vector <std::string> readList();
std::vector <std::string> getTitles(const std::vector <std::string> fileLines);
std::vector <std::string> getTimes(const std::vector <std::string> fileLines);
std::vector <std::string> getDates(const std::vector <std::string> fileLines);
void fileReadToday();
std::vector <std::string> removeCompleted(const std::vector <std::string> fileList, 
										  const std::vector <Task> tasksToday);
										  
void outputFile(const std::vector <std::string> fileLines);

//getters.cpp
std::vector <Date> getDate(const std::vector <Task> dividedTasks);
std::vector <Task> getDividedTasks(const std::vector <std::string> fileLines);
std::vector <Task> getTasksToday(const std::vector <Task> dividedTasks);

//void fileAddRepeatingTask(const repeatTask taskToAdd);

//input.cpp
std::string inputTaskOneLine(const int whatToCheck);
Task inputTask();
int inputMenu();
void continueProgram(const int &userChoice);
bool menuLoop();

//output.cpp
void checkToday();

//valid.cpp
bool validString(const std::string s);
bool validNumberInput(const std::string input, const int min, const int max);
bool validStringLength(const std::string s, const int desiredLength);
bool validCharacter(const char inputC, const char desiredC);
bool validAddTaskInput(const std::string input, const int inputType);



#endif