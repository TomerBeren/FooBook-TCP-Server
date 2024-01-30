#ifndef BLOOMFILTER_HPP
#define BLOOMFILTER_HPP

#include <vector>
#include <string>
#include <unordered_set>

class BloomFilter
{
private:
    std::unordered_set<std::string> falsePositive; // Control set for falsepositive checkings
    std::vector<bool> bitArray;                    // The bit array for the filter.
    std::vector<std::string> hashFunctionIDs;      // Stores the hash function identifiers

public:
    BloomFilter() = default;                                        // Default constructor.
    void initialize(int size, const std::vector<std::string> &ids); // Initializes the filter.
    const std::vector<bool> &getBits() const;                       // Returns the bit array.
    const std::vector<std::string> &getHashFunctions();             // Returns hash function IDs.
    void setBitArray(int index);                                    // Sets a bit in the array.
    int getBitArraySize();                                          // Returns the size of the bit array.
    std::unordered_set<std::string> getFalsePositives();            // Gets the control set.
    void insertFaslePositives(std::string &url);                    // Adds a URL to the control set.
};

#endif // BLOOMFILTER_HPP