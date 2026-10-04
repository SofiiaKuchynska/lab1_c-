#include "WeightedRandomGenerator.h"

#include <set>
#include <stdexcept>

// Constructor that checks input validity and seeds the generator
WeightedRandomGenerator::WeightedRandomGenerator(const std::vector<int>& vals,
                                                 const std::vector<int>& freqs) {
    if (vals.empty() || vals.size() != freqs.size()) {
        throw std::invalid_argument("Values and frequencies must be non-empty and same size.");
    }

    std::set<int> seen;
    long long total = 0;
    for (std::size_t i = 0; i < vals.size(); ++i) {
        if (!seen.insert(vals[i]).second) {
            throw std::invalid_argument("Values must be distinct.");
        }
        if (freqs[i] < 0) {
            throw std::invalid_argument("Frequency cannot be negative.");
        }
        total += freqs[i];
    }
    if (total == 0) {
        throw std::invalid_argument("Sum of frequencies must be positive.");
    }

    values = vals;
    std::random_device rd;
    rng.seed(rd());
    dist = std::discrete_distribution<std::size_t>(freqs.begin(), freqs.end());
}

// Generates a single weighted random value
int WeightedRandomGenerator::operator()() {
    return values[dist(rng)];
}