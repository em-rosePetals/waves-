#include <iostream>
#include <unordered_map>
#include <vector> // what do you think it's here for?
#include <cmath> // pi, sin
#include <limits> // int16_max
#include <functional> // std::function
#include <SFML/Audio.hpp>

#include "waves.hpp"
#include "util.hpp"

const int SAMPLE_RATE = 44100;

/**
 * creates a vector with amplitude points appropriate to the wave function
 */
void makeNoises(std::vector<sf::Int16>& vec, const wave::func_t& wavefun, int end) {
	for (size_t i = 0; i < vec.size(); ++i) {
		vec[i] = util::floatToInt16(wavefun(i, end));
	}
}

int userNum() {
	bool validIn = false;
	int result = -1;
	do {
		std::cout << "Hey I'd like to have a number to stop at thanks! \n";
		std::string s;
		std::getline(std::cin, s);
		validIn = true;
		if (!util::isDigits(s)) {
			std::cout << "Sorry to bother you but it'd be nice if you only gave "
					<< "me positive integers thank you have a good day! \n";
			validIn = false;
		} else {
			try {
				result = std::stoi(s);
			} catch (std::exception& e) {
				std::cout << "Whoah there this number is WAY too big I need something smaller!! \n";
				validIn = false;
			}
		}
	} while (!validIn);
	return result;
}
/**
 * plays the noise
 */
void play() {
	sf::SoundBuffer buf;
	std::vector<sf::Int16> noises(SAMPLE_RATE * 4);
	int end = userNum();
	makeNoises(noises, wave::saw, end);
	// loads buffer from the vector
	buf.loadFromSamples(&noises[0], noises.size(), 1, SAMPLE_RATE);
	// sound player thing
	sf::Sound player;
	// puts the buffer into the sound player
	player.setBuffer(buf);
	// percentage volume
	player.setVolume(30.0f);
	// plays the sound
	player.play();
	std::cout << "Press return once you're done! \n";
	std::string s;
	std::getline(std::cin, s);
	if (s == "\n") {
		player.stop();
	}
}
wave::func_t getWave() {
	const std::unordered_map<std::string, wave::func_t>
			map {{"saw", wave::saw}, {"cos", wave::cosaw}, {"square", wave::square}};
	bool validIn;
	wave::func_t result;
	do {
		std::string s;
		std::getline(std::cin, s);
		result = map.at(s);
		// TODO finish this thing up
		validIn = result != nullptr;
		if (!validIn) {
			std::cout << "Hey I haven't heard of that wave before"
					<< " you're gonna have to choose another one sorry! \n";
		}
	} while (!validIn);
	return result;
}

int main() {
	while (true) {
		play();
	}
}
