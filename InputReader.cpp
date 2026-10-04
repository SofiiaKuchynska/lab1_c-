#include "InputReader.h"

#include <fstream>
#include <stdexcept>

// Reads N, K, values, and frequencies from the given file path
InputData readInput(const std::string& path) {
    std::ifstream file(path);

    // Fallback: if not found in current directory, check parent directory
    if (!file.is_open()) {
        file.clear();
        file.open("../" + path);
    }

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + path);
    }

    long long n = 0, k = 0;
    if (!(file >> n >> k)) {
        throw std::runtime_error("Failed to read N and K from file.");
    }
    if (n <= 0 || k <= 0) {
        throw std::invalid_argument("N and K must be positive.");
    }
    if (n > 100'000'000LL) {
        throw std::invalid_argument("N is too large (limit is 100 million).");
    }

    InputData data;
    data.generations = static_cast<std::size_t>(n);

    data.values.resize(static_cast<std::size_t>(k));
    for (long long i = 0; i < k; ++i) {
        if (!(file >> data.values[i])) {
            throw std::runtime_error("Failed to read value #" + std::to_string(i + 1));
        }
    }

    data.frequencies.resize(static_cast<std::size_t>(k));
    for (long long i = 0; i < k; ++i) {
        if (!(file >> data.frequencies[i])) {
            throw std::runtime_error("Failed to read frequency #" + std::to_string(i + 1));
        }
    }

    std::string extra;
    if (file >> extra) {
        throw std::runtime_error("Extra data in file: '" + extra + "'.");
    }
    return data;
}