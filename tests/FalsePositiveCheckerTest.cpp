#include "FalsePositiveChecker.hpp"
#include "BloomFilter.hpp" 
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

// Test fixture for FalsePositiveChecker
class FalsePositiveCheckerTest : public ::testing::Test
{
protected:
   
    BloomFilter bloomFilter;  // BloomFilter instance for testing
    FalsePositiveChecker checker; // FalsePositiveChecker instance

     // Variables to capture and restore cout's buffer
    std::streambuf *originalCoutBuffer;
    std::ostringstream capturedCout;

    // Redirects cout to capture output in SetUp
    void SetUp() override
    {
        originalCoutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(capturedCout.rdbuf()); // Redirect cout to capture output.
    }

     // Restores cout's original buffer in TearDown
    void TearDown() override
    {
        std::cout.rdbuf(originalCoutBuffer); // Reset cout to its original state.
    }
};

// Tests checker's output when URL is not in BloomFilter
TEST_F(FalsePositiveCheckerTest, URLNotInBloomFilter)
{
    
    std::string testUrl = "http://example.com";
    bool flag = false; // Assuming the URL is not in the BloomFilter.

    checker.checkAndReport(testUrl, flag, bloomFilter);

    // Check the output.
    EXPECT_EQ(capturedCout.str(), "false\n");
}

// Tests checker's output when URL is in BloomFilter but not a false positive
TEST_F(FalsePositiveCheckerTest, NotFalsePositive)
{
    // Assuming the URL is in the BloomFilter's control set.
    std::string testUrl = "http://example.com";
    bloomFilter.insertFaslePositives(testUrl); 
    bool flag = true;

    checker.checkAndReport(testUrl, flag, bloomFilter);

    // Check the output.
    EXPECT_EQ(capturedCout.str(), "true true\n");
}

// Tests checker's output for a false positive
TEST_F(FalsePositiveCheckerTest, FalsePositive)
{
    // Assuming the URL is not in the BloomFilter's control set.
    std::string testUrl = "http://example.com";
    bool flag = true;

    checker.checkAndReport(testUrl, flag, bloomFilter);

    // Check the output.
    EXPECT_EQ(capturedCout.str(), "true false\n");
}