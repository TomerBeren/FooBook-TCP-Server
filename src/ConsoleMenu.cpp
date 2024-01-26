#include "ConsoleMenu.hpp"

// waits for user input from the console, processes it, and returns a vector of strings.
std::vector<std::string> ConsoleMenu::nextCommand()
{
    std::string input;
    std::getline(std::cin, input); // Read the entire line from console.

    // Check if the command is to initialize the BloomFilter if it hasn't been initialized yet.
    std::vector<std::string> tokens = InputValidator::removeDuplicatesAndInitVector(input);

    if (InputValidator::isValidBloomFilterCommand(tokens) && !this->bloomFilterInitialized)
    {
        int bitArraySize = std::stoi(tokens[0]); // First token is the bit array size.
        std::vector<std::string> hashIds(tokens.begin() + 1, tokens.end());
        this->getBloomFilter().initialize(bitArraySize, hashIds); // Mark the BloomFilter as initialized.
        this->bloomFilterInitialized = true; // Return an empty vector indicating a control command was processed.
        return {};
    }

    return tokens;
}
// Getter function for the boomFilter to work on.
BloomFilter &ConsoleMenu::getBloomFilter()
{
    return bloomFilter;
}
