#include <iostream>
#include <string>
#include "AddUrlCommand.hpp"

// Executes the command to add a URL to the BloomFilter
void AddUrlCommand::execute(std::string &url, BloomFilter &bloomFilter) 
{
    // Applies hash functions to the given URL and updates the BloomFilter accordingly
    AbstractCommand::applyHashFunctions(url, bloomFilter, [&](int index)
    { 
        // Sets the bit at the calculated index. Uses std::abs to ensure the index is non-negative.
        bloomFilter.setBitArray(std::abs(index)); 
    });
    // Inserts the given URL into the set of false positives for the BloomFilter
    bloomFilter.insertFaslePositives(url);
}
// Returns a unique identifier for the AddUrlCommand
std::string AddUrlCommand::getId()
{
    return "1";
}
// Static member that registers the AddUrlCommand with the CommandFactory upon program start
bool AddUrlCommand::registered = []()
{
    // Lambda function executed immediately to register this command type with the CommandFactory
    // Uses the singleton instance of CommandFactory to register the AddUrlCommand class
    // The lambda passed to registerCommand constructs a new instance of AddUrlCommand
    CommandFactory::getInstance().registerCommand(getId(), []() -> ICommand *
                                                  { return new AddUrlCommand(); });
    return true;
}();
