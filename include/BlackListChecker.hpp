// BlackListChecker.hpp
#pragma once

#include "ICommand.hpp"
#include "CommandFactory.hpp"
#include "AbstractCommand.hpp"
#include <iostream>

// BlackListChecker class definition
class BlackListChecker : public AbstractCommand
{
public:
    // Overrides the execute method from AbstractCommand to provide specific implementation
    void execute(std::string &url, BloomFilter &bloomFilter,std::ostream &output) override;
    // Returns a unique identifier for this command type.
    static std::string getId();
    // Static variable to ensure this command is registered with the CommandFactory.
    // The actual registration logic is implemented in the BlackListChecker.cpp file.
    static bool registered;
};