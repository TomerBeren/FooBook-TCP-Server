#ifndef IMENU_H
#define IMENU_H
#include <iostream>
#include <vector>
#include "BloomFilter.hpp"
#include "InputValidator.hpp"

// IMenu interface declaration.
class IMenu
{
public:
    // Pure virtual function that should be implemented to return the next command from the user as a vector of strings.
    virtual std::vector<std::string> nextCommand() = 0;

    // Pure virtual function that should be implemented to provide access to the application's BloomFilter instance.
    virtual BloomFilter &getBloomFilter() = 0;

    // Pure virtual destructor, defined inline to ensure derived classes can properly clean up resources.
    virtual ~IMenu() = 0;
};
// Inline definition of the pure virtual destructor to allow for proper cleanup of derived classes.
inline IMenu::~IMenu() {}
#endif