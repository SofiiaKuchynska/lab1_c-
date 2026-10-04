#include "FrequencyAnalyzer.h"

#include <cmath>
#include <unordered_map>


std::vector<StatRecord> analyzeGenerator(WeightedRandomGenerator& generator,
    const InputData& data) {
    // Count how many times each number actually appeared.
    std::unordered_map<int, long long> counts;
    for (std::size_t i = 0; i < data.generations; ++i) {
        ++counts[generator()];
    }

    long long totalFreq = 0;
    for (int f : data.frequencies) {
        totalFreq += f;
    }

    const double n = static_cast<double>(data.generations);

    std::vector<StatRecord> stats;
    stats.reserve(data.values.size());
    for (std::size_t i = 0; i < data.values.size(); ++i) {
        int v = data.values[i];
        long long cnt = counts[v];

        double expected = static_cast<double>(data.frequencies[i]) / static_cast<double>(totalFreq);
        double actual = static_cast<double>(cnt) / n;

        stats.push_back({ v, data.frequencies[i], cnt, expected, actual, std::abs(expected - actual) });
    }
    return stats;
}