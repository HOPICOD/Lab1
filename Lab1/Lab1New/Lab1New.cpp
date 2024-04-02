#include "Flight.h"
#include "Flight_manager.h"
#include "ShowMenu.h"
#include "Input.h"
#include "Tasks.h"
#include "Files.h"

#include <iostream>
#include <vector>

enum menu {ADD_FLIGHT = 1, SHOW_FLIGHTS, SAVE_DATA, LOAD_DATA, SEARCH_BY_DESTINATIONS, SEARCH_BY_DAY_OF_WEEK, SEARCH_BY_DESTINATION_AND_LATER_TIME, RUN_TESTS, EXIT};

using namespace std;

int main()
{
    ShowGreeting();

    int user_menu_choice = 0;

    bool repeat = true;

    string file = { "" };

    Flight_manager flights;

    do {
        ShowTasks_for_input();
        user_menu_choice = InputInt("Select menu point", 0, 10);
        switch (user_menu_choice) {
        case(ADD_FLIGHT): {
            add_flight(flights);
            break;
        }
        case(SHOW_FLIGHTS): {
            flights.show_flights();
            break;

        }
        case(SAVE_DATA): {
            save_data(flights);
            break;
        }
        case(LOAD_DATA): {
            load_data(flights);
            break;
        }
        case(SEARCH_BY_DESTINATIONS): {
            search_by_destination(flights);
            break;
        }
        case(SEARCH_BY_DAY_OF_WEEK):{
            search_day_of_week(flights);
            break;
        }
        case(SEARCH_BY_DESTINATION_AND_LATER_TIME): {
            search_destination_later_time(flights);
            break;
        }
        case(RUN_TESTS): {
            break;
        }
        case(EXIT): {
            repeat = false;
        }
        }

    } while (repeat);
}

