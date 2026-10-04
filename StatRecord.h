#pragma once

#include <compare>

// One row of statistics for a specific number.
struct StatRecord {
    int value;
    long long givenFreq;    
    long long actualCount;  
    double expectedFreq;    // givenFreq / sum of frequencies
    double actualFreq;      // actualCount / n
    double discrepancy;     // |expectedFreq - actualFreq|

    // Compare records by discrepancy — this is the only meaningful comparison here.
    std::partial_ordering operator<=>(const StatRecord& other) const {
        return discrepancy <=> other.discrepancy;
    }

    // If <=> is written manually, == must be written separately.
    bool operator==(const StatRecord& other) const {
        return discrepancy == other.discrepancy;
    }
};
