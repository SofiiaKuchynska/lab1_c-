#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "FrequencyAnalyzer.h"
#include "InputReader.h"
#include "StatRecord.h"
#include "WeightedRandomGenerator.h"

// Apply an arbitrary action to each record.
// Here we use the library functional object std::function
void processStatistics(const std::vector<StatRecord>& stats,
    const std::function<void(const StatRecord&)>& action) {
    for (const auto& s : stats) {
        action(s);
    }
}

void printReport(const std::vector<StatRecord>& stats) {
    std::cout << std::fixed << std::setprecision(5);
    std::cout << std::setw(8) << "Number"
        << std::setw(8) << "Given"
        << std::setw(8) << "Count"
        << std::setw(11) << "Expected"
        << std::setw(11) << "Actual"
        << std::setw(11) << "Diff" << '\n';
    std::cout << std::string(57, '-') << '\n';

    // Lambda as a callback for processStatistics.
    processStatistics(stats, [](const StatRecord& r) {
        std::cout << std::setw(8) << r.value
            << std::setw(8) << r.givenFreq
            << std::setw(8) << r.actualCount
            << std::setw(11) << r.expectedFreq
            << std::setw(11) << r.actualFreq
            << std::setw(11) << r.discrepancy << '\n';
        });

    // max_element uses our operator<, synthesized from operator<=>.
    auto maxIt = std::max_element(stats.begin(), stats.end());
    std::cout << "\nMax diff: " << maxIt->discrepancy
        << " (number = " << maxIt->value << ")\n";
}

int main(int argc, char* argv[]) {
    try {
        std::string path = (argc > 1) ? argv[1] : "input.txt";

        InputData data = readInput(path);
        WeightedRandomGenerator generator(data.values, data.frequencies);
        std::vector<StatRecord> stats = analyzeGenerator(generator, data);

        printReport(stats);
    }
    catch (const std::exception& e) {
        std::cerr << "[ERROR] " << e.what() << '\n';
        return 1;
    }
    return 0;
}