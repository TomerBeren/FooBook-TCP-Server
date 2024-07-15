#ifndef APP_HPP
#define APP_HPP

#include <iostream>
#include <map>
#include "IMenu.hpp"
#include "ICommand.hpp"

// Defines the App class, which manages the application's main loop and command execution.
class App
{
private:
    IMenu *menu;                                // Pointer to an object that implements the IMenu interface, managing user input/output.
    std::map<std::string, ICommand *> commands; // Map of command names to their respective ICommand implementations.

public:
    // Constructor for the App class, taking a menu system and a map of commands as parameters.
    App(IMenu *menu, std::map<std::string, ICommand *> commands);
    // Runs the main loop of the application, processing user commands through the menu system.
    void run(const std::string &input, std::ostream &output);
};

#endif // APP_HPP