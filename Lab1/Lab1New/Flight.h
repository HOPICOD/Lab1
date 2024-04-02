#pragma once

#include <iostream>
#include "Input.h"

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



	static Flight get_input_flight() {

		string new_destination = InputString("Set destination:");
		string new_plane_type = InputString("Set plane type:");
		string new_day_of_week = InputString("Set day of week:");

		
		int new_number_of_flight = InputInt("Set number of flight:", 0, INT_MAX);
		int new_hour = InputInt("Set hour of flight:", 0, 23);
		int new_minutes = InputInt("Set minutes of flight:", 0, 59);

		


		return Flight(new_destination, new_plane_type, new_day_of_week, new_number_of_flight, new_hour, new_minutes);

	}





	string get_destination() { return destination; }
	string get_plane_type() { return plane_type; }
	string get_days() { return days; }


	int get_number_of_flight() { return number_of_flight; }
	int get_hours() { return hours; }
	int get_minutes() { return minutes; }



	void show_full_flight() { cout << destination << ' ' << plane_type << ' ' << days << ' ' << number_of_flight << " " << hours << ":" << minutes << endl; }

};
