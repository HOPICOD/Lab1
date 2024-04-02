#pragma once
#include "Flight_manager.h"


void add_flight(Flight_manager& flights);

void load_data(Flight_manager& flights);

void save_data(Flight_manager& flights);

void search_by_destination(Flight_manager& flights);

void search_day_of_week(Flight_manager& flights);

void search_destination_later_time(Flight_manager& flights);
