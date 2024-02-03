#include "InputValidator.hpp"

// Checks if a given string can be converted to an integer.
bool InputValidator::isInteger(const std::string &str)
{
    std::istringstream ss(str); // Create a string stream from the input string.
    int num;

    // Attempt to read an integer from the stream and then check if we've reached the end of the string,
    // which ensures the entire string is a valid integer.
    return (ss >> num) && (ss.eof());
}

// Validates if the tokens represent a valid command for initializing a BloomFilter.
bool InputValidator::isValidBloomFilterCommand(const std::vector<std::string> &tokens)
{
    // A valid command must have at least 2 tokens: size and at least one hash function.
    if (tokens.size() < 2)
        return false;

    // The first token must be an integer representing the bit array size.
    if (!isInteger(tokens[0]))
        return false;

    // Currently, only "1" and "2" are considered valid hash function IDs.
    for (size_t i = 1; i < tokens.size(); ++i)
    {
        if (tokens[i] != "1" && tokens[i] != "2")
        {
            return false;
        }
    }
    return true;
}

// Removes duplicate tokens from the input string and returns a vector of unique tokens.
std::vector<std::string> InputValidator::removeDuplicatesAndInitVector(const std::string &input)
{
    std::vector<std::string> tokens; // To store the unique tokens.
    std::unordered_set<std::string> seenTokens; // To track tokens we've seen.
    std::istringstream ss(input); // Stream to parse the input string.
    std::string token;

    while (ss >> token) // Extract tokens one by one.
    {
        if (seenTokens.find(token) == seenTokens.end()) // If the token hasn't been seen before.
        {
            // Add it to the list of tokens.
            tokens.push_back(token);
            // Mark it as seen.
            seenTokens.insert(token);
        }
    }

    return tokens;
}
