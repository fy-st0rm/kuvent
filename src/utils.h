#pragma once

#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>



static std::time_t dateStringToTimestamp(const std::string& dateStr) {
	std::tm tm = {};
	std::istringstream ss(dateStr);
	#ifdef _WIN32
        ss >> std::get_time(&tm, "%d-%B-%Y"); // Parse string into std::tm
    #else
        ss >> std::get_time(&tm, "%d-%b-%Y"); // Parse string into std::tm
    #endif
	if (ss.fail()) {
		throw std::runtime_error{"failed to parse time string"};
	}
	std::time_t timestamp = std::mktime(&tm); // Convert std::tm to std::time_t
	return timestamp;
}
