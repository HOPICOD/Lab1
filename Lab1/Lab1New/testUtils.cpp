#include <iostream>
#include <string>
#include <vector>

#include "Flight.h"


bool runVectorCheck(vector<Flight>& vectorToCheck, vector<Flight>& expectedVector) {
	bool passed = true;
	
	for (size_t i = 0; i < vectorToCheck.size(); ++i) {
		string actualId = vectorToCheck[i].get_destination();
		string expectedId = expectedVector[i].get_destination();

		if (actualId != expectedId) {
			std::cerr << "\n\nError: Mismatch at index " << i << ": "
				<< actualId << " != " << expectedId << "\n\n";
			return false;
		}
	}

	return passed;
}

void printTestResults(const bool checkStatus, const string functionTitle, const string caseTitle) {
	/*checkStatus ?
		std::cout << "Test passed: " << functionTitle << " - " << caseTitle << std::endl :
		std::cout << "Test failed: " << functionTitle << " - " << caseTitle << std::endl;*/
}
