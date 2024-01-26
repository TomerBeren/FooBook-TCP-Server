
#include <gtest/gtest.h>
#include <vector>
#include <string>

// Tests for isInteger function
TEST(InputValidator, IsInteger)
{
    EXPECT_TRUE(InputValidator::isInteger("123"));   // Test with a valid integer string
    EXPECT_FALSE(InputValidator::isInteger("abc"));  // Alphabetic characters
    EXPECT_FALSE(InputValidator::isInteger("12a3")); // Alphanumeric characters
    EXPECT_FALSE(InputValidator::isInteger(""));     // Empty string test
}

// Tests for isValidBloomFilterCommand function
TEST(InputValidator, IsValidBloomFilterCommand)
{
    // Valid commands
    EXPECT_TRUE(InputValidator::isValidBloomFilterCommand({"123", "1", "2"}));
    EXPECT_TRUE(InputValidator::isValidBloomFilterCommand({"456", "2"}));

    // Invalid commands
    EXPECT_FALSE(InputValidator::isValidBloomFilterCommand({"123"}));      // Too few elements
    EXPECT_FALSE(InputValidator::isValidBloomFilterCommand({"abc", "1"})); // Non-integer first element
    EXPECT_FALSE(InputValidator::isValidBloomFilterCommand({"8", "7", "1"}));
    EXPECT_FALSE(InputValidator::isValidBloomFilterCommand({" "})); // Invalid second element
}

// Tests for removeDuplicatesAndInitVector function
TEST(InputValidator, RemoveDuplicatesAndInitVector)
{
    // Input with duplicates, expecting unique elements in order
    std::vector<std::string> result1 = InputValidator::removeDuplicatesAndInitVector("8 1 1 1 2");
    std::vector<std::string> expected1 = {"8", "1", "2"};
    EXPECT_EQ(result1, expected1);

    // Another input with duplicates
    std::vector<std::string> result2 = InputValidator::removeDuplicatesAndInitVector("8 1 2 2");
    std::vector<std::string> expected2 = {"8", "1", "2"};
    EXPECT_EQ(result2, expected2);

    // Input where the order of first occurrence is preserved
    std::vector<std::string> result3 = InputValidator::removeDuplicatesAndInitVector("8 1 2 2 1");
    std::vector<std::string> expected3 = {"8", "1", "2"};
    EXPECT_EQ(result3, expected3);
}