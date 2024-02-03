#include "BlackListChecker.hpp"

// Executes the blacklist check command
void BlackListChecker::execute(std::string &url, BloomFilter &bloomFilter) 
{
    // Initially assume URL is blacklisted (all bits found in BloomFilter)
    bool flag = true;
     // Apply hash functions to the URL and check corresponding bits in the BloomFilter
    AbstractCommand::applyHashFunctions(url, bloomFilter, [&](int index)
    {
        // If any bit corresponding to the hash function is not set, the url is not blacklisted.
        if (!bloomFilter.getBits()[index]) {
            flag = false;
        } 
    });
     // Check if the output was a flase positive.
    FalsePositiveChecker checker;
    checker.checkAndReport(url, flag, bloomFilter);
}
// Returns a unique identifier for the BlackListChecker command
std::string BlackListChecker::getId()
{
    return "2";
}
// Static member variable that registers the BlackListChecker with the CommandFactory upon program start
bool BlackListChecker::registered = []()
{
    // Lambda function executed immediately to register this command type with the CommandFactory
    // Uses the singleton instance of CommandFactory to register the BlackListChecker class
    // The lambda passed to registerCommand constructs a new instance of BlackListChecker
    CommandFactory::getInstance().registerCommand(getId(), []() -> ICommand *
                                                  { return new BlackListChecker(); });
    return true;
}();
