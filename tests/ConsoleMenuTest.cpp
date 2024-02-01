#include <gtest/gtest.h>
#include "ConsoleMenu.hpp"
#include "InputValidator.hpp"
#include "IMenu.hpp"
#include <iostream>
#include <typeinfo>

// Tests for the ConsoleMenu Class
TEST(MenuTest, Input)
{

    std::stringstream ss("8 1 2\n"); // Simulate input stream with a test string
    std::vector<std::string> tokens; // Container for parsed tokens
    std::string token;

    // Parse the simulated input into tokens
    while (ss >> token)
    {
        tokens.push_back(token);
    }

    // Check the number of tokens
    ASSERT_EQ(tokens.size(), 3);
    EXPECT_EQ(tokens[0], "8");
    EXPECT_EQ(tokens[1], "1");
    EXPECT_EQ(tokens[2], "2");
}
// Test case for verifying the creation and configuration of a ConsoleMenu instance
TEST(MenuTest, ClassCreation)
{
    ConsoleMenu menu; // Instantiate a ConsoleMenu object

    std::stringstream ss("8 1 2\n");
    std::vector<std::string> tokens;
    std::string token;

    // Parse the simulated input into tokens
    while (ss >> token)
    {
        tokens.push_back(token);
    }

    // Initialize the BloomFilter of the menu if the second token is an integer
    if (!InputValidator::isInteger(tokens[1]))
    {
        menu.getBloomFilter().initialize(std::stoi(tokens[0]), std::vector<std::string>(tokens.begin() + 1, tokens.end()));
    }
    // Expect that the type of the BloomFilter instance obtained from the menu matches the BloomFilter type
    EXPECT_EQ(typeid(menu.getBloomFilter()), typeid(BloomFilter));
}