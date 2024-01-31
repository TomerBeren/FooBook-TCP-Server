#include "CommandInitializer.hpp"

// Constructor: Initializes the 'commands' member with commands from the CommandFactory.
CommandInitializer::CommandInitializer() : commands(getInitializedCommands()) {}

// Returns a static reference to commands from CommandFactory, ensuring a single initialization.
std::map<std::string, ICommand *> &CommandInitializer::getInitializedCommands()
{
    static std::map<std::string, ICommand *> &commands = CommandFactory::getInstance().getCommands();
    return commands;
}
// Initializes and starts the application using the provided CommandInitializer instance.
void CommandInitializer::init(CommandInitializer& init)
{
     // Sets up the menu and app, then runs the app.
    IMenu *menu = new ConsoleMenu();
    App myApp(menu, init.commands);
    myApp.run();
}