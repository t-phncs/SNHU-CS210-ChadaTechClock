#include "Clock.h"
#include <iostream>
#include <string>
#include <ctime>


using namespace std;

int main() {
	Clock clock;
	clock.displayBothClock();
	// initialize choice to 0
	int choice = 0;

	cout << clock.nCharString(30, '*') << endl;
	cout << "* 1- Add One Hour " << clock.nCharString(11, ' ') << "*" << endl;
	cout << "* 2- Add One Minute" << clock.nCharString(10, ' ') << "*" << endl;
	cout << "* 3- Add One Second" << clock.nCharString(10, ' ') << "*" << endl;
	cout << "* 4- Exit" << clock.nCharString(20, ' ') << "*" << endl;
	cout << clock.nCharString(30, '*') << endl;

	while (choice < 1 || choice > 4) {
		cin >> choice;
		// code will execute based on user input
		switch (choice) {
		case 1:
			
			clock.addOneHour();
			clock.displayBothClock();
			break;
			
		case 2:
			
			clock.addOneMinute();
			clock.displayBothClock();
			break;
		case 3:
			
			clock.addOneSecond();
			clock.displayBothClock();
			break;
		case 4:
			cout << "exit";
			exit(0);
			break;
		default:
			cout << "Invalid" << endl;
			cin >> choice;
			break;
		}
	}
	
	return 0;
}