#pragma once
#include <iostream>
#include <vector>

#include "Flight_manager.h"
#include "Flight.h"


class TestCase {

public:

	vector<Flight> flightsToTest;

	vector<Flight> expectedDestinationResult;
	vector<Flight> expectedDaysResult;
	vector<Flight> expectedDestinationAndTimeResult;



	string destinationToTest;
	string dayToTest;
	int hoursToTest = 0;
	int minutesToTest = 0;

	TestCase(vector<Flight> flightsToTest,  vector<Flight> expectedDestinationResult, vector<Flight> expectedDaysResult, vector<Flight> expectedDestinationAndTimeResult,
		string destinationToTest, string dayToTest, int hoursToTest = 0, int minutesToTest = 0) :

		flightsToTest(flightsToTest),
		expectedDestinationResult(expectedDestinationResult),
		expectedDaysResult(expectedDaysResult),
		expectedDestinationAndTimeResult(expectedDestinationAndTimeResult),

		destinationToTest(destinationToTest),			
		dayToTest(dayToTest),

		hoursToTest(hoursToTest),
		minutesToTest(minutesToTest) {}


};