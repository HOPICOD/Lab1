#include <iostream>
using namespace std;

enum WEEK{MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };


int input_int(string message, int min, int max) {

	int user_input;

	cout << message << endl;

	cin >> user_input;

	while (cin.fail() || user_input <= min || user_input >= max) {

		cin.clear();//снимает тип ошибки
		cin.ignore(INT_MAX, '\n');// очищает поток ввода

		cout << "Retype:" << endl;
		cin >> user_input;
	}

	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return user_input;
}

//double InputDouble(string message, int min, int max) {
//
//	double user_input;
//
//	cout << message << endl;
//
//	cin >> user_input;
//
//	while (cin.fail() || user_input < min || user_input > max) {
//
//		cin.clear();//снимает тип ошибки
//		cin.ignore(INT_MAX, '\n');// очищает поток ввода
//
//		cout << "Retype:" << endl;
//		cin >> user_input;
//	}
//
//	cin.clear();
//	cin.ignore(INT_MAX, '\n');
//
//	return user_input;
//}

string input_string(string message) {

	string user_input;

	cout << message << endl;

	cin >> user_input;

	while (user_input.empty()) {

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cout << "Retype:" << endl;
		cin >> user_input;
	}

	cin.ignore(INT_MAX, '\n');

	return user_input;
}


string day_of_week_input() {

	int user_choice = 0;
	string user_day;
	
	cout << "1 - Monday" << endl;
	cout << "2 - Tuesday" << endl;
	cout << "3 - Wednesday" << endl;
	cout << "4 - Thursday" << endl;
	cout << "5 - Friday" << endl;
	cout << "6 - Saturday" << endl;
	cout << "7 - Sunday" << endl;
	user_choice = input_int("Select the day of week:", 0, 8);

	switch (user_choice) {

	case(MONDAY): {user_day = "Monday"; return user_day; }
	case(TUESDAY): {user_day = "Tuesday"; return user_day; }
	case(WEDNESDAY): {user_day = "Wednesday"; return user_day; }
	case(THURSDAY): {user_day = "Thursday"; return user_day; }
	case(FRIDAY): {user_day = "Friday"; return user_day; }
	case(SATURDAY): {user_day = "Saturday"; return user_day; }
	case(SUNDAY): {user_day = "Sunday"; return user_day; }
	}
}