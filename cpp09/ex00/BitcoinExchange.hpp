#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <limits>
#include <map>
#include <iomanip>
#include <stdexcept>
#include <cstdio>
#include <cstdlib> 
#include <cctype> 
#include <climits>

bool is_double(const char* str);

bool is_valid_date(const std::string& date);

bool parsing_input(const std::string& line);

std::string find_closest_date(const std::map<std::string, double>& data, const std::string& date);

std::map<std::string, double> read_csv(const std::string& filename);