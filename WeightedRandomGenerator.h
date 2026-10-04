#pragma once
#include <cstddef>
#include <random>
#include <vector>

// Functor that generates random numbers with given frequencies
class WeightedRandomGenerator {
private:
    std::vector<int> values;
    std::mt19937 rng;
    std::discrete_distribution<std::size_t> dist;

public:
    // Validates input vectors and initializes the random generator
    WeightedRandomGenerator(const std::vector<int>& vals,
                            const std::vector<int>& freqs);

    // Returns the next random number according to weights
    int operator()();
};