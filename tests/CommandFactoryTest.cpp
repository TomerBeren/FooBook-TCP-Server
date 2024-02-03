#include "CommandFactory.hpp"
#include "AddUrlCommand.hpp"
#include "BlackListChecker.hpp"
#include <gtest/gtest.h>

// Test fixture for CommandFactory tests
class CommandFactoryTest : public ::testing::Test
{
protected:
    // Access the singleton instance of CommandFactory for use in all tests
    CommandFactory &factory = CommandFactory::getInstance();
};

// Test to verify that commands are correctly self-registered with the CommandFactory
TEST_F(CommandFactoryTest, CommandSelfRegistration)
{
    auto &commands = factory.getCommands(); // Retrieve the map of registered commands

    // Assert that the command with identifier "1" (AddUrlCommand) is registered
    ASSERT_NE(commands.find("1"), commands.end());
    // Assert that the command with identifier "1" (BlackListChecker) is registered
    ASSERT_NE(commands.find("2"), commands.end());
}

// Test to verify that the correct type of command object is retrieved from the CommandFactory
TEST_F(CommandFactoryTest, CommandRetrieval)
{
    auto &commands = factory.getCommands(); // Retrieve the map of registered commands
    
    ICommand *command1 = commands["1"];     // Retrieve the command associated with identifier "1"
    ICommand *command2 = commands["2"];     // Retrieve the command associated with identifier "2"

    // Assert that the retrieved command is indeed an instance of AddUrlCommand and BlackListChecker
    ASSERT_TRUE(dynamic_cast<AddUrlCommand *>(command1) != nullptr);
    ASSERT_TRUE(dynamic_cast<BlackListChecker *>(command2) != nullptr);
}