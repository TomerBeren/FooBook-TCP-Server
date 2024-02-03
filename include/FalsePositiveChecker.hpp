#ifndef FALSE_POSITIVE_CHECKER_HPP
#define FALSE_POSITIVE_CHECKER_HPP

#include <string>
#include <unordered_set>
#include <iostream>
#include "BloomFilter.hpp"

// FalsePositiveChecker class definition
class FalsePositiveChecker
{
public:
    // Checks if the given URL is considered a false positive by the BloomFilter
    // and reports the result.
    void checkAndReport(const std::string &url, bool flag, BloomFilter &bloomFilter);
};

#endif // FALSE_POSITIVE_CHECKER_HPP