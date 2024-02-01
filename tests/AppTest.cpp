#include <gtest/gtest.h>
#include "AddUrlCommand.hpp"
#include "CommandInitializer.hpp"
#include "IMenu.hpp"
#include "ICommand.hpp"
#include "App.hpp"

TEST(AppTest, AppExists)
{
    // Initialize an App object
    IMenu *mockMenu = nullptr;                  
    std::map<std::string, ICommand *> commands; 
    App app(mockMenu, commands);

    // Verify that the App object exists
    EXPECT_TRUE(&app != nullptr);
}