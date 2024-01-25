#include <gtest/gtest.h>
#include "BloomFilter.hpp"
#include <vector>

BloomFilter bf; // Create a global BloomFilter object for testing

// Test case for verifying the initialization of the BloomFilter
TEST(BloomFilterTest, Initialization)
{
    bf.initialize(8, {"1", "2"}); // Initialize the BloomFilter with size 1 and 2 hash functions
    const std::vector<bool> &bits = bf.getBits();
     // Check all bits are false initially
    for (bool bit : bits)
    {
        EXPECT_FALSE(bit);
    }
    const std::vector<std::string> &hash = bf.getHashFunctions();
    // Verify hash function IDs initialized correctly
    EXPECT_EQ(hash[0], "1");
    EXPECT_EQ(hash[1], "2");
}
