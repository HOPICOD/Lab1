#include "Flight.h"
#include "Flight_manager.h"
#include "TestCase.h"



bool runVectorCheck(vector<Flight>& flightsToTest, vector<Flight>& expectedFlights) {

	for (int i = 0; i < flightsToTest.size(); ++i) {
		string actualId = flightsToTest[i].get_destination();
		string expectedId = expectedFlights [i] .get_destination();

		if (actualId != expectedId) {
			return false;
		}
	}

	return true;
}


bool runSearchByDestinationTest(vector<Flight>& flightsToTest, vector<Flight>& expectedFlights, string destination) {

	Flight_manager flights;

	flights.set_flight(flightsToTest);

	vector<Flight> tested_flights = flights.search_by_destination(destination);

	bool test_passed = false;

	test_passed = runVectorCheck(tested_flights, expectedFlights);

	if (test_passed) {
		cout << "Search by destination successfully passed" << endl;
	}

	else { cout << "Search by destination was unsuccessful" << endl; }

	return test_passed;
}


bool runSearchByDayOfWeekTest(vector<Flight>& flightsToTest, vector<Flight>& expectedFlights, string days) {

	Flight_manager flights;

	flights.set_flight(flightsToTest);

	vector<Flight> tested_flights = flights.search_day_of_week(days);

	bool test_passed = false;

	test_passed = runVectorCheck(tested_flights, expectedFlights);

	if (test_passed) {
		cout << "Search by day of week successfully passed" << endl;
	}

	else { cout << "Search by day of week was unsuccessful" << endl; }

	return test_passed;
}


bool runSearchByDestinationAndLaterTimeTest(vector<Flight>& flightsToTest, vector<Flight>& expectedFlights, string destination, int hours, int minutes) {

	Flight_manager flights;

	flights.set_flight(flightsToTest);

	vector<Flight> tested_flights = flights.search_destination_later_time(destination, hours, minutes);

	bool test_passed = false;

	test_passed = runVectorCheck(tested_flights, expectedFlights);

	if (test_passed) {
		cout << "Search by destination with later time successfully passed" << endl;
	}

	else { cout << "Search by destination with later time was unsuccessful" << endl; }

	return test_passed;
}


void runTests() {

	vector<TestCase> search_test{

		TestCase(

			vector<Flight>{

				{"Russia","Boing","Monday", 23, 12, 30 },
				{"USA","Boing125","Friday", 5, 10, 45 },
				{"England","Plane","Tuesday", 10, 22, 15 }
				},
			vector<Flight>{

				{"Russia","Boing","Monday", 23, 12, 30 },
				
				
				},
			vector<Flight>{

				{"Russia","Boing","Monday", 23, 12, 30 },
				
				},
			vector<Flight>{

				{"Russia","Boing","Monday", 23, 12, 30 },
				

				}, 
			"Russia", 
			"Monday",
			12,
			30
			),

		TestCase(

			vector<Flight>{

				{"England","Boing","Monday", 23, 12, 30 },
				{"USA","Boing125","Friday", 5, 10, 45 },
				{"England","Plane","Tuesday", 10, 22, 15 }
				},
			vector<Flight>{

				{"England","Plane","Monday", 10, 22, 15 },
				{"England","Plane","Tuesday", 10, 22, 15 }

				},
			vector<Flight>{

				{"England","Plane","Tuesday", 10, 22, 15 }

				},
			vector<Flight>{
				{"England","Plane","Monday", 10, 22, 15 },
				{"England","Plane","Tuesday", 10, 22, 15 }

				},
			"England",
			"Tuesday",
			11,
			30
			),

		TestCase(

			vector<Flight>{

				{"Russia","Boing","Monday", 23, 12, 30 },
				{"USA","Boing125","Friday", 5, 10, 45 },
				{"Russia","Plane","Tuesday", 10, 22, 15 }
				},
			vector<Flight>{

				{"Russia","Boing","Monday", 23, 12, 30 },
				{"Russia","Plane","Tuesday", 10, 22, 15 }

				},
			vector<Flight>{

				

				},
			vector<Flight>{
				
				{"Russia","Plane","Tuesday", 10, 22, 15 }

				},
			"Russia",
			"Sunday",
			15,
			30
			),

		TestCase(

			vector<Flight>{

				{"Russia","Boing","Monday", 23, 12, 30 },
				{"Russia","Boing125","Friday", 5, 10, 45 },
				{"Russia","Plane","Tuesday", 10, 22, 15 }
				},
			vector<Flight>{

				{"Russia", "Boing", "Monday", 23, 12, 30 },
				{"Russia","Boing125","Friday", 5, 10, 45 },
				{"Russia","Plane","Tuesday", 10, 22, 15 }
				},
			vector<Flight>{

				{"Russia", "Boing125", "Friday", 5, 10, 45 }

				},
			vector<Flight>{

				{"Russia", "Boing", "Monday", 23, 12, 30 },
				{"Russia","Boing125","Friday", 5, 10, 45 },
				{"Russia","Plane","Tuesday", 10, 22, 15 }

				},
			"Russia",
			"Friday",
			0,
			0
			),

		TestCase(

			vector<Flight>{

				{"England","Boing","Monday", 23, 12, 30 },
				{"USA","Boing125","Friday", 5, 10, 45 },
				{"England","Plane","Tuesday", 10, 22, 15 }
				},
			vector<Flight>{

				{"England","Plane","Monday", 10, 22, 15 },
				{"England","Plane","Tuesday", 10, 22, 15 }

				},
			vector<Flight>{

				{"England","Plane","Tuesday", 10, 22, 15 }

				},
			vector<Flight>{
				{"England","Plane","Monday", 10, 22, 15 },
				{"England","Plane","Tuesday", 10, 22, 15 }

				},
			"England",
			"Tuesday",
			11,
			30
			)
	};

	cout << endl;

	bool test_passed = true;

	for (TestCase current_test : search_test) {
		if (!runSearchByDestinationTest(current_test.flightsToTest, current_test.expectedDestinationResult, current_test.destinationToTest)) {
			test_passed = false;
				}
		
		if (!runSearchByDayOfWeekTest(current_test.flightsToTest, current_test.expectedDaysResult, current_test.dayToTest)) {
		test_passed = false;
		}
		if (!runSearchByDestinationAndLaterTimeTest(current_test.flightsToTest, current_test.expectedDestinationResult, current_test.destinationToTest, current_test.hoursToTest, current_test.minutesToTest)) {
			test_passed = false;
		}
	}
	cout << endl;
	if (test_passed) {
		cout << "All tests passed successfully" << endl;
	}
	else { cout << "Tests passed unsuccessfully" << endl; }
	cout << endl;
}
