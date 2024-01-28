#pragma once

#include "ICommand.hpp"
#include <functional>

class AbstractCommand : public ICommand
{
protected:
    // Applies hash functions to a URL and performs a given action for each hash result.
    static void applyHashFunctions(const std::string &url, BloomFilter &bloomFilter, std::function<void(int)> action)
    {
        // Retrieve hash function identifiers from the BloomFilter.
        std::vector<std::string> hashIds = bloomFilter.getHashFunctions();

        // Iterate over each hash function identifier.
        for (const std::string &hashId : hashIds)
        {
            // Initial hash value of the URL.
            size_t hashValue = std::hash<std::string>{}(url);

            // Apply the hash function multiple times based on the hashId value if at all.
            for (size_t i = 1; i < std::stoull(hashId); i++)
            {
                hashValue = std::hash<std::string>{}(std::to_string(hashValue));
            }

            // Calculate the index for the BloomFilter's bit array.
            int index = hashValue % bloomFilter.getBitArraySize();
            // Perform the action on the calculated index according to the base class.
            action(index);
        }
    }

public:
    // Abstract method that concrete commands must implement to execute their specific action.
    virtual void execute(std::string &url, BloomFilter &bloomFilter) = 0;
    // Virtual destructor to ensure derived class destructors are called correctly.
    virtual ~AbstractCommand() {}
};