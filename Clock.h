#pragma once
#ifndef CLOCK_H
#define CLOCK_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Clock {
private:
	int hour;
	int minute;
	int second;
public:
	// default constructor
	Clock();
	// constructor with parameter
	Clock(int hour, int min, int second); 

	string AMPM();

	void displayAt12();
	void displayAt24();
	
	string nCharString(size_t n, char c);

	void displayBothClock();

	void addOneHour();
	void addOneMinute();
	void addOneSecond();

};



#endif
