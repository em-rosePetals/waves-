/*
 * waves.cpp
 *
 *  Created on: Jul 22, 2022
 *      Author: emily
 */
#include <cmath>
#include "waves.hpp"
#include "util.hpp"



/**
 * angle is in radians
 */
inline float sawBase(float angle, int harmonic) {
	float result = 0;
	for (int i = 1; i <= harmonic; ++i) {
		result += sin((i) * angle) / i;
	}
	return result;
}
/**
 * saw wave
 * angle is in degrees
 */
float wave::saw(float angle, int harmonic) {
	angle = util::degToRad(angle);
	// calculates the function
	float result = sawBase(angle, harmonic);
	// normalizes the wave function to be in [-1.0, 1.0]
	result /= sawBase(M_PI / (harmonic + 1), harmonic);
	return result;
}

/**
 * generates square wave
 * angle is in degrees
 */
float wave::square(float angle, int harmonic) {
	angle = util::degToRad(angle);
	float result = 0;
	for (int i = 1; i <= harmonic; ++i) {
		result += sin((2 * i - 1) * angle) / i;
	}
	return result;
}
/**
 * generates a wave that's a saw, but with cosine instead of sine
 * angle is in degrees
 */
float wave::cosaw(float angle, int harmonic) {
	angle = util::degToRad(angle);
	float result = 0;
	for (int i = 1; i <= harmonic; ++i) {
		result += cos(i * angle) / i;
	}
	return result;
}

