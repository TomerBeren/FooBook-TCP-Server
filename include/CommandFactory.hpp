// CommandFactory.hpp
#ifndef COMMANDFACTORY_HPP
#define COMMANDFACTORY_HPP

#include <string>
#include <map>
#include <functional>
#include "ICommand.hpp" 

class CommandFactory {
public:
    // Define a type for the command creation function
    using CommandCreator = std::function<ICommand*()>;

    // Get the singleton instance of the factory
    static CommandFactory& getInstance();

    // Register a command with the factory
    void registerCommand(const std::string& name, CommandCreator creator);

    // Get the map of commands
    std::map<std::string, ICommand*>& getCommands();

private:
    // Constructor is private to prevent instantiation
    CommandFactory() = default;

    // Map to store the name-command pairs
    std::map<std::string, ICommand*> commandMap;
};

#endif // COMMANDFACTORY_HPP