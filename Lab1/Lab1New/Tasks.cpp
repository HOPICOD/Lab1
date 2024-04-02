#include "Flight.h"
#include "Flight_manager.h"
#include "Files.h"


#include <iostream>

using namespace std;

bool confirm_save_search_results() {

	cout << "Do you want to save your search results? " << endl << "1 - Yes;" << endl << "0 - No;" << endl;;
	int user_choice = InputInt("Enter menu item:", -1, 2);

	return user_choice;
}

void add_flight(Flight_manager& flights) {

	Flight flight = Flight::get_input_flight();

	flights.add_flight(flight);
}

void load_data(Flight_manager& flights) {

	string filepath = get_valid_filepath();

	vector<Flight> flights_from_file = get_flights_from_file(filepath);

	if (flights_from_file.empty()) { cerr << "Error reading from file" << endl; }

	else { flights.set_flight(flights_from_file); }
}

void save_data(Flight_manager& flights) {

	string filepath = get_valid_filepath();

	vector<Flight> flights_to_export = flights.get_flights();

	if (flights_to_export.empty()) { cerr << "Error saving to file" << endl; return; }

	else { export_to_file(flights_to_export); }
}

void search_by_destination(Flight_manager& flights) {

	if (flights.get_flights().empty()) { cout << "There is no employees" << endl; return; }

	string destination = InputString("Set a destination to search flight: ");

	vector<Flight> suitable_flights = flights.search_by_destination(destination);

	if (suitable_flights.empty()) { cout << "There is no suitable flights" << endl; return; }

	cout << "Suitable flights:" << endl;
	flights.show_suitable_flights (suitable_flights);

	if (confirm_save_search_results()) { export_to_file(suitable_flights); }
}

void search_day_of_week(Flight_manager& flights) {

	if (flights.get_flights().empty()) { cout << "There is no flights" << endl; return; }

	string days = InputString("Set a day of week to search the flight: ");

	vector<Flight> suitable_flights = flights.search_day_of_week(days);

	if (suitable_flights.empty()) { cout << "There is no suitable flights" << endl; return; }

	cout << "Suitable flights" << endl;
	flights.show_suitable_flights(suitable_flights);

	if (confirm_save_search_results()) { export_to_file(suitable_flights); }
}

void search_destination_later_time(Flight_manager& flights) {

	if (flights.get_flights().empty()) { cout << "There is no flights" << endl; return; }

	string destination = InputString("Set a destination to search the flight: ");
	int hours = InputInt("Set a hour to search the flight: ", 0, 24);
	int minutes = InputInt("Set a minutes to search the flight: ", 0, 59);

	vector<Flight> suitable_flights = flights.search_destination_later_time(destination, hours, minutes);

	if (suitable_flights.empty()) { cout << "There is no suitable flights" << endl; return; }

	cout << "Suitable flights:" << endl;
	flights.show_suitable_flights(suitable_flights);

	if (confirm_save_search_results()) { export_to_file(suitable_flights); }
}

