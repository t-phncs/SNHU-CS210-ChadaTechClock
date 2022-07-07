#include "Clock.h"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

Clock::Clock() {
	// current date/time based on current system
	time_t now = time(0);
	tm* local_time = localtime(&now);
	// assign hour/minute/second to their right correspondent
	hour = local_time->tm_hour;
	minute = local_time->tm_min;
	second = local_time->tm_sec;
}

Clock::Clock(int hour, int minute, int second) {
	// use 'this' pointer to retrieve object (optional) to improve readability
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}

string Clock::AMPM() {
	// function to determine whether hour will become AM or PM at 12 hour clock
	if (this->hour <= 12) {
		return " AM";
	}
	else {
		return " PM";
	}
}
void Clock::displayAt12() {
	if (this->hour == 0 || this->hour == 12) {
		// hour will become 0 if hour = 12 or hour will still be 12 @ 12
		hour = 12;
	}
	else {
		// if hour > 12, using modulo will give the remainder become new hour
		hour = hour % 12;
	}
	// using setfill with setwidth to get the leading 0 if there is a single digit in hour, minute or second
	cout << setfill('0') << setw(2) << this->hour << ":" << setw(2) << this->minute << ":" << setw(2) << this->second << AMPM();
}

void Clock::displayAt24() {
	// if/else to check hour 
	if (hour > 12) {
		hour -= 12;
	}
	else if (hour < 12) {
		hour += 12;
	}
	cout << setfill('0') << setw(2) << this->hour << ":" << setw(2) << this->minute << ":" << setw(2) << this->second;
}

string Clock::nCharString(size_t n, char c) {
	string str;
	// using append with number of size_t, and 1 char will repeat the char 
	str.append(n, c);
	return str;
}


void Clock::displayBothClock() {
	cout << nCharString(27, '*') << "     " << nCharString(27, '*') << endl;
	cout << "*" << "     " << "12 - Hour Clock" << "     " << "*";
	cout << "     "<< "*" << "     " << "24 - Hour Clock" << "     " << "*" << endl;
	cout << "*" << nCharString(5, ' ');
	displayAt12(); 
	cout << nCharString(9, ' ') <<  "*";
	cout << nCharString(5, ' ') << "*     ";
	displayAt24();
	cout << nCharString(12, ' ') << "*" << endl;
	cout << nCharString(27, '*') << "     " << nCharString(27, '*') << endl;
}


void Clock::addOneHour() {
	hour++;
}
void Clock::addOneMinute() {
	
	if (minute == 59) {
		// calling function addOneHour to increment an hour if minute turn to 60 
		addOneHour();
	}
	minute++;
}
void Clock::addOneSecond() {
	if (second == 59) {
		// calling function addOneMinute to increment 1 minute if second turn to 60 
		addOneMinute();
	}
	second++;
}



