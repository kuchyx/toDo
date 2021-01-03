#ifndef TO_DO_CPP
#define TO_DO_CPP

#include <chrono>
#include <ctime>
#include <iostream>
#include <string> 
#include <vector>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "dataStructures.hpp"
#include "constants.hpp"
#include "allfunctions.hpp"
#include "basic.cpp"
#include "valid.cpp"
#include "check.cpp"
#include "getters.cpp"
#include "file.cpp"
#include "output.cpp"
#include "input.cpp"



int main()
{
	bool end = 0;
	while(!end) { end = menuLoop(); };
	return 0;
}

#endif