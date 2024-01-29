#include "CommandFactory.hpp"

// Singleton pattern implementation to get the single instance of CommandFactory
CommandFactory& CommandFactory::getInstance() {
    static CommandFactory instance;
    return instance;
}
//The registerCommand method maps a command name to its creation function, enabling dynamic command instantiation.
void CommandFactory::registerCommand(const std::string& name, CommandCreator creator) {
    commandMap[name] = creator();
}
// Retrieves the map of command names to ICommand pointers
std::map<std::string, ICommand*>& CommandFactory::getCommands() {
    return commandMap;
}
