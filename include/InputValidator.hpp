#ifndef INPUT_VALIDATOR_HPP
#define INPUT_VALIDATOR_HPP

#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>

// InputValidator class with static methods for input validation and processing.
class InputValidator
{
public:
    // Checks if a given string can be successfully converted to an integer.
    static bool isInteger(const std::string &str);

    // Determines if a set of tokens represents a valid command for initializing or interacting with a Bloom filter.
    static bool isValidBloomFilterCommand(const std::vector<std::string> &tokens);

    // Processes an input string to remove duplicate tokens and returns a vector of unique tokens.
    static std::vector<std::string> removeDuplicatesAndInitVector(const std::string& input);
};

#endif // INPUT_VALIDATOR_HPP
