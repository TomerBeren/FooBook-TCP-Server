#include <gtest/gtest.h>
#include "BlackListChecker.hpp"
#include "BloomFilter.hpp"
#include "AddUrlCommand.hpp"

TEST(BlackListCheckerTest, inputExample1)
{
    // Create an instance of BloomFilter
    BloomFilter bloomFilter;
    bloomFilter.initialize(8, {"1", "2"});
    // Create an instance of BlackListChecker
    BlackListChecker blackListChecker;
    AddUrlCommand AddUrlCommand;

    //section 1
    std::string blacklistedUrl = "www.example.com0";
    testing::internal::CaptureStdout();
    blackListChecker.execute(blacklistedUrl, bloomFilter);
    std::string output1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output1, "false\n");

    //section 2
    AddUrlCommand.execute(blacklistedUrl, bloomFilter);
    testing::internal::CaptureStdout(); // Redirect stdout
    blackListChecker.execute(blacklistedUrl, bloomFilter);
    std::string output2 = testing::internal::GetCapturedStdout(); // Capture stdout
    EXPECT_EQ(output2, "true true\n");

    //section 3
    std::string url = "www.example.com1";
    testing::internal::CaptureStdout(); // Redirect stdout
    blackListChecker.execute(url, bloomFilter);
    std::string output3 = testing::internal::GetCapturedStdout(); // Capture stdout
    EXPECT_EQ(output3, "false\n");

    //section 4
    std::string url2 = "www.example.com11";
    testing::internal::CaptureStdout(); // Redirect stdout
    blackListChecker.execute(url2, bloomFilter);
    std::string output4 = testing::internal::GetCapturedStdout(); // Capture stdout
    EXPECT_EQ(output4, "true false\n");

}
// Test case for the getId() function
TEST(BlackListCheckerTest, GetId)
{
    // Create an instance of AddUrlCommand
    BlackListChecker blackListChecker;

    // Call the getId() function and check if it returns the correct ID
    EXPECT_EQ(blackListChecker.getId(), "2");
}

// Test case for the registered static member
TEST(BlackListCheckerTest, Registered)
{
    // The registered static member should already be initialized.
    // Check if it returns true, indicating successful registration.
    EXPECT_TRUE(BlackListChecker::registered);
}