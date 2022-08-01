/*
 * waves.hpp
 *
 *  Created on: Jul 22, 2022
 *      Author: emily
 */

#ifndef WAVES_HPP_
#define WAVES_HPP_

#include <functional>

namespace wave {
	typedef std::function<float(float, int)> func_t;
	float saw(float angle, int harmonic);
	float cosaw(float angle, int harmonic);
	float square(float angle, int harmonic);
}

#endif /* WAVES_HPP_ */
