#ifndef RANDOM_NUMBER_GENERATOR_HPP
#define RANDOM_NUMBER_GENERATOR_HPP

#include <random>

class RandomNumberGenerator {
private:
    std::mt19937 generator;

public:
    RandomNumberGenerator();
    RandomNumberGenerator(int seed);
    
    unsigned int get(unsigned int lowerBound, unsigned int upperBound);
};

#endif // RANDOM_NUMBER_GENERATOR_HPP