/*
 * util.cpp
 *
 *  Created on: Jul 25, 2022
 *      Author: emily
 */
#include <cmath>
#include "util.hpp"

float util::degToRad(float degrees) {
	return degrees / 180.0 * M_PI;
}
/**
 * converts a float in range [-1.0, 1.0] to an int16
 */
sf::Int16 util::floatToInt16(float n) {
	n *= std::numeric_limits<sf::Int16>::max();
	return static_cast<sf::Int16>(n);
}
/**
 * checks if a string is only decimal digits
 */
bool util::isDigits(const std::string& s) {
	for (char c: s) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}
