/*
 * util.hpp
 *
 *  Created on: Jul 25, 2022
 *      Author: emily
 */



#ifndef UTIL_HPP_
#define UTIL_HPP_

// # pragmas disable the warning
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnonportable-include-path"
#include <SFML/audio.hpp>
#pragma GCC diagnostic pop

namespace util {
	float degToRad(float degrees);
	sf::Int16 floatToInt16(float n);
	bool isDigits(const std::string& s);
}

#endif /* UTIL_HPP_ */
