#ifndef COMMANDINITIALIZER_HPP
#define COMMANDINITIALIZER_HPP

#include <map>
#include <string>
#include "ICommand.hpp"
#include "CommandFactory.hpp"
#include "App.hpp"
#include "IMenu.hpp"
#include "ConsoleMenu.hpp"

// CommandInitializer class orchestrates the initialization of commands and the setup of the application.
class CommandInitializer
{
public:
    // Holds a map of command names to ICommand pointers for easy command lookup and execution.
    std::map<std::string, ICommand *> &commands;

    // Constructor initializes the command map with available commands.
    CommandInitializer();

    // Retrieves a reference to a statically initialized command map populated with commands.
    static std::map<std::string, ICommand *> &getInitializedCommands();
    
    // Initializes and starts the application using the provided CommandInitializer instance.
    //static void init(CommandInitializer &init);
};

#endif // COMMANDINITIALIZER_HPP