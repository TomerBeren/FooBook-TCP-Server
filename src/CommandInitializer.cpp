#include "CommandInitializer.hpp"

// Constructor: Initializes the 'commands' member with commands from the CommandFactory.
CommandInitializer::CommandInitializer() : commands(getInitializedCommands()) {}

// Returns a static reference to commands from CommandFactory, ensuring a single initialization.
std::map<std::string, ICommand *> &CommandInitializer::getInitializedCommands()
{
    static std::map<std::string, ICommand *> &commands = CommandFactory::getInstance().getCommands();
    return commands;
}
