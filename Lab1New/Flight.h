#pragma once

#include <iostream>
#include "Input.h"
#include <iomanip>

using namespace std;

class Flight {
private:

	string destination;
	string plane_type;
	string days;

	int number_of_flight;
	int hours;
	int minutes;

public:
	Flight(string destination, string plane_type, string days, int number_of_flight, int hours, int minutes) :
		destination(destination), plane_type(plane_type), days(days), number_of_flight(number_of_flight), hours(hours), minutes(minutes){}





	string get_destination() { return destination; }
	string get_plane_type() { return plane_type; }
	string get_days() { return days; }


	int get_number_of_flight() { return number_of_flight; }
	int get_hours() { return hours; }
	int get_minutes() { return minutes; }



	void show_full_flight() {
		
		/*cout << destination << ' ' << plane_type << ' ' << days << ' ' << number_of_flight << ' ';
		if (hours < 10) {
			cout << '0';
		}
		cout << hours << ':';
		if (minutes < 10) {
			cout << '0';
		}
		cout << minutes << endl;
		cout << endl;*/
		cout << destination << ' ' << plane_type << ' ' << days << ' ' << number_of_flight << ' '
			<< setw(2) << setfill('0') << hours << ':'
			<< setw(2) << setfill('0') << minutes << endl << endl;

	}

};
