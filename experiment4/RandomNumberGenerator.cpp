#include "RandomNumberGenerator.hpp"

RandomNumberGenerator::RandomNumberGenerator() : generator(std::random_device{}()) { }

RandomNumberGenerator::RandomNumberGenerator(int seed) : generator(seed) { }

unsigned int RandomNumberGenerator::get(unsigned int lowerBound, unsigned int upperBound) {
    std::uniform_int_distribution<unsigned int> dis(lowerBound, upperBound);

    return dis(generator);
}
