#pragma once
#include <vector>
#include "FLight.h"

class Flight_manager
{
private:

	vector<Flight> flights;

public:

	void set_flight(vector<Flight>& new_flights) {  flights = new_flights; }


	void show_flights() {
		cout << endl;
		for (Flight flight : flights) { flight.show_full_flight(); }
	}

	void show_suitable_flights(vector<Flight> suitable_flights) {

		for (Flight flight : suitable_flights) { flight.show_full_flight(); }
		cout << endl;

	}


	void add_flight(Flight flight) { flights.push_back(flight); }


	vector<Flight> search_by_destination(string destination) {

		vector<Flight> suitable_flights;

		for (Flight flight : flights) {

			if (flight.get_destination() == destination) { suitable_flights.push_back(flight); }
		}

		return suitable_flights;

	}

	vector<Flight> search_day_of_week(string days) {

		vector<Flight> suitable_flights;

		for (Flight flight : flights) {

			if (flight.get_days() == days) { suitable_flights.push_back(flight); }

		}

		return suitable_flights;
	}

	vector<Flight> search_destination_later_time(string destination, int hours, int minutes) {

		vector<Flight> suitable_flights;

		for (Flight flight : flights) {

			if (flight.get_destination() == destination && flight.get_hours() > hours && flight.get_minutes() > minutes) { suitable_flights.push_back(flight); }

		}
		return suitable_flights;
	}

	vector<Flight>get_flights() {
		return flights;
	}

};
