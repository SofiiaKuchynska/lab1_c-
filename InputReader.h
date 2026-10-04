#pragma once
#include <cstddef>
#include <string>
#include <vector>

// Holds input parameters read from the file
struct InputData {
    std::size_t generations;
    std::vector<int> values;
    std::vector<int> frequencies;
};

// Reads input file and validates the data
InputData readInput(const std::string& path);