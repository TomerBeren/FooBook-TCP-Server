#include <gtest/gtest.h> 
#include "BloomFilter.hpp"

TEST(AddUrlCommandTest, ExecuteHashIds)
{
    // Create an instance of BloomFilter
    BloomFilter bloomFilter;
    bloomFilter.initialize(8, {"1", "2"});
    // Create an instance of AddUrlCommand
    AddUrlCommand addUrlCommand;

    // mimicking the AbstractCommand execute function to add URL's
    std::string url = "example.com";
    size_t hashValue1 = std::hash<std::string>{}(url);
    int index1 = hashValue1 % bloomFilter.getBitArraySize();
    size_t hashValue2 = std::hash<std::string>{}(url);
    hashValue2 = std::hash<std::string>{}(std::to_string(hashValue2));
    int index2 = hashValue2 % bloomFilter.getBitArraySize();
    addUrlCommand.execute(url, bloomFilter);
    std::vector<bool> bitArray = bloomFilter.getBits();
    //check if the BloomFilter bitArray is updated correctly
    EXPECT_TRUE(bitArray[index1]);
    EXPECT_TRUE(bitArray[index2]);
}
// Test case for the getId() function
TEST(AddUrlCommandTest, GetId)
{
    // Create an instance of AddUrlCommand
    AddUrlCommand addUrlCommand;

    // Call the getId() function and check if it returns the correct ID
    EXPECT_EQ(addUrlCommand.getId(), "1");
}

// Test case for the registered static member
TEST(AddUrlCommandTest, Registered)
{
    // The registered static member should already be initialized.
    // Check if it returns true, indicating successful registration.
    EXPECT_TRUE(AddUrlCommand::registered);
}