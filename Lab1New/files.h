#pragma once

#include "Flight.h"

#include <iostream>
#include <vector>

using namespace std;

bool file_exists(string filename);

bool confirm_overwrite(string filename);

vector<Flight> get_flights_from_file(string filename);

void export_to_file(vector<Flight> &flights_to_export);

bool is_filepath_valid(string filepath);

bool is_filename_valid(string filename);

string get_valid_filepath();
