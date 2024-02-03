#include "CommandInitializer.hpp"
#include "CommandFactory.hpp"
#include "BlackListChecker.hpp"
#include "AddUrlCommand.hpp" 
#include <gtest/gtest.h>
#include "IMenu.hpp"
#include "ConsoleMenu.hpp"

class CommandInitializerTest : public ::testing::Test
{
protected:
    CommandInitializer initializer;

    // Ensure that the self-registration of AddUrlCommand occurs
    static void SetUpTestSuite()
    {
        // Trigger the static registration of AddUrlCommand
        (void)AddUrlCommand::registered;
    }
};

TEST_F(CommandInitializerTest, InitializationTest)
{
    auto &commands = initializer.getInitializedCommands();
    // Check if the commands map is not empty
    ASSERT_FALSE(commands.empty());
}

TEST_F(CommandInitializerTest, CommandsMapContentTest1)
{
    auto &commands = initializer.getInitializedCommands();
    // Check if the "1" command is present in the commands map
    ASSERT_NE(commands.find("1"), commands.end());
    // Check if the command is of the correct type
    auto *cmd = commands["1"];
    ASSERT_TRUE(dynamic_cast<AddUrlCommand *>(cmd) != nullptr);
}

TEST_F(CommandInitializerTest, CommandsMapContentTest2)
{
    auto &commands = initializer.getInitializedCommands();
    // Check if the "1" command is present in the commands map
    ASSERT_NE(commands.find("2"), commands.end());
    // Check if the command is of the correct type
    auto *cmd = commands["2"];
    ASSERT_TRUE(dynamic_cast<BlackListChecker *>(cmd) != nullptr);
}