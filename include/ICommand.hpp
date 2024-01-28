#ifndef ICOMMAND_H
#define ICOMMAND_H
#include <iostream>
#include "BloomFilter.hpp"


// ICommand interface declaration.
class ICommand
{
public:
    // Pure virtual function that specifies the interface for executing a command.
    virtual void execute(std::string &url, BloomFilter &bloomFilter) = 0;

    // Virtual destructor to allow for proper cleanup of derived class objects through base class pointers.
    virtual ~ICommand() {}
};

#endif // ICOMMAND_H