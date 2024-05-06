#include "Flight.h"

#include "Input.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>
enum token { DESTINATION, PLANE_TYPE, DAY_OF_WEEK, NUMBER_OF_FLIGHT, HOURS, MINUTES };
using namespace std;

bool is_valid_day(const string& days) {
	return (days == "monday" || days == "Monday" || days == "tuesday" || days == "Tuesday" || days == "wednesday" || days == "Wednesday" || days == "thursday" || days == "Thursday" || days == "friday" || days == "Friday" || days == "saturday" || days == "Saturday" || days == "sunday" || days == "Sunday");
}

bool file_exists(string filename) {
	ifstream file(filename);
	return file.is_open();
}

bool confirm_overwrite(string filename) {

	const int YES = 1;

	cout << "File '" << filename << "' already exists." << endl;
	cout << "Do you want to overwrite it?" << endl;
	cout << "1 - Yes" << endl;
	cout << "2 - No" << endl;

	int user_choice = 0;

	user_choice = input_int("Enter menu item:", 0, 3);

	if (user_choice == YES) { return true; }

	return false;

}

vector<Flight> get_flights_from_file(string filename) {
	/*vector<Flight> files;

	ifstream input_file(filename);
	if (!input_file.is_open()) {
		cerr << "Error opening file: " << filename << endl;
		return files;
	}

	string line;
	while (getline(input_file, line)) {

		if (line.empty()) {
			cerr << "Warning: Skipped empty line." << endl;
			continue;
		}

		stringstream ss(line);

		string token{ "" };

		string destination{ "" };
		string plane_type{ "" };
		string days{ "" };


		int field_count = 0;

		int number_of_flight = 0;
		int hours = 0;
		int minutes = 0;


		while (getline(ss, token, ';')) {
			try {
				switch (field_count) {
				case DESTINATION: destination = token; break;
				case PLANE_TYPE: plane_type = token; break;
				case DAY_OF_WEEK: days = token; break;
				case NUMBER_OF_FLIGHT: number_of_flight = stoi(token); break;
				case HOURS: hours = stoi(token); break;
				case MINUTES: minutes = stoi(token); break;
				default:
					cerr << "Warning: parsing " << field_count << " field: " << "wrong number of fields" << endl;
				}
			}
			catch (invalid_argument& e) {
				cerr << "Warning: converting field " << field_count << ": " << e.what() << endl;
			}

			field_count++;
		}
		if (number_of_flight < 0 || (hours > 23 || hours < 0) || (minutes > 59 || minutes < 0)) {
			files.clear();
			input_file.close();
			return files;
		}

		Flight flight(destination, plane_type, days, number_of_flight, hours, minutes);
		files.push_back(flight);
	}

	input_file.close();
	return files;*/
	vector<Flight> flights;

	ifstream input_file(filename);
	if (!input_file.is_open()) {
		cerr << "Error opening file: " << filename << endl;
		return flights;
	}

	string line;
	while (getline(input_file, line)) {
		if (line.empty()) {
			cerr << "Warning: Skipped empty line." << endl;
			continue;
		}

		stringstream ss(line);

		string destination;
		string plane_type;
		string days;
		int number_of_flight;
		int hours;
		int minutes;

		if ( (!(ss >> destination >> plane_type >> days >> number_of_flight >> hours) || ss.get() != ':' || !(ss >> minutes)) ) {
			cerr << "Error parsing line:\" " << line << "\"" << endl;
			continue;
		}

		if ((number_of_flight < 0 || hours < 0 || hours > 23 || minutes < 0 || minutes > 59) || !(is_valid_day(days))) {
			cerr << "Error invalid data in line:\" " << line << "\"" << endl;
			continue;
		}

		Flight flight(destination, plane_type, days, number_of_flight, hours, minutes);
		flights.push_back(flight);
	}

	input_file.close();
	return flights;
};

bool is_filepath_valid(string filepath) {

	regex file_path_regex("^(?:[a-zA-Z]\\:|\\\\)\\\\([^\\\\]+\\\\)*[^\\/:*?\"<>|]+\\.txt$");

	if (!regex_match(filepath, file_path_regex)) {
		cerr << "Error: Invalid file path." << endl;
		return false;
	}

	return true;
}
bool is_filename_valid(string filename) {
	regex filename_regex("^[^\\/:*?\"<>|]+\\.txt$");

	regex filename_reserved_names("^(?:CON|PRN|AUX|NUL|COM[1-9]|LPT[1-9]|con|prn|aux|nul|com[1-9]|lpt[1-9])(?:\\..*)?$");

	regex filename_reserved_chars("[\\/:*?\"<>|]");

	if (!regex_match(filename, filename_regex)) {
		cerr << "Error: Invalid file name." << endl;
		return false;
	}

	if (regex_match(filename, filename_reserved_names)) {
		cerr << "Error: Invalid file name. Using reserved filenames is prohibited!" << endl;
		return false;
	}

	if (regex_search(filename, filename_reserved_chars)) {
		cerr << "Error: Invalid file name. Using reserved characters is prohibited!" << endl;
		return false;
	}

	return true;
}

string get_valid_filepath() {
	bool is_path_valid = false;
	bool is_name_valid = false;

	//string filename { "" };
	string filepath { "" };

	while (!is_path_valid || !is_name_valid) {
		cout << "Enter fullpath with filename (only txt acceptable): " << endl;
		getline(cin, filepath);
		size_t pos = filepath.find_last_of("\\");

		if(pos>sizeof(filepath)){
		
			if (is_filename_valid(filepath)) {

				is_path_valid = true;
				is_name_valid = true;

			}
		}

			if (pos != string::npos) {
				string filename = filepath.substr(pos + 1);
				string path = filepath.substr(0, pos + 1);

				//filename = InputString("Enter filename (only csv acceptable): ");

				//filepath = InputString("Enter full path to path: ");

				if (is_filepath_valid(path + filename) && is_filename_valid(filename)) {
					is_path_valid = true;
					is_name_valid = true;
				}
		
			}
	}

	return filepath;
}

string get_overwrite_confirmation(string& full_path) {
	if (file_exists(full_path)) {
		if (!confirm_overwrite(full_path)) {
			cout << "Please choose another file." << endl;
			full_path = get_valid_filepath();
			return get_overwrite_confirmation(full_path);
		}
		/*while (!confirm_overwrite(full_path)) {
			cout << "Please choose another file." << endl;
			full_path = get_valid_filepath();
		}*/
	}
	return full_path;
}

void export_to_file(vector<Flight> &flights_to_export) {
	if (flights_to_export.empty()) { cout << "You haven't added any flyghts yet" << endl; return; }
	string full_path = get_valid_filepath();
	full_path = get_overwrite_confirmation(full_path);

	ofstream file(full_path);
	if (!file) {
		cerr << "Error: File is read-only or another error occurred." << endl;
		file.close();

		while (true) {
			cout << "Please enter a new path." << endl;
			full_path = get_valid_filepath();
			full_path = get_overwrite_confirmation(full_path);

			file.open(full_path);
			if (file) {
				break;
			}
			else {
				cerr << "Error: File is read-only or another error occurred." << endl;
				file.close();
			}
		}
	}

	for (Flight& export_flight : flights_to_export) {
		file << export_flight.get_destination() << ' ' << export_flight.get_plane_type() << ' ' << export_flight.get_days() << ' '
			<< export_flight.get_number_of_flight() << ' ' << setw(2) << setfill('0') << export_flight.get_hours() << ":" << setw(2) << setfill('0') << export_flight.get_minutes() << "\n";
	}

	file.close();
	cout << "Data successfully exported to file: " << full_path << endl;
}