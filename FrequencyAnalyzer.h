#pragma once

#include <vector>

#include "InputReader.h"
#include "StatRecord.h"
#include "WeightedRandomGenerator.h"

// Generates data.generations numbers, counts actual frequencies, 
// and compares them with the given ones. 

std::vector<StatRecord> analyzeGenerator(WeightedRandomGenerator& generator,
    const InputData& data);
