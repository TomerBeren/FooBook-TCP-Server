#include "BloomFilter.hpp"

// Initializes the BloomFilter with a given size and hash function IDs
void BloomFilter::initialize(int size, const std::vector<std::string> &ids)
{
    // Resize bit array and initialize all bits to false
    bitArray.resize(size, false); 
    // Copy the hash function IDs
    hashFunctionIDs = ids;        
}
// Getter method to access the current state of the bit array.
const std::vector<bool> &BloomFilter::getBits() const
{
    return this->bitArray;
}
// Getter method for retrieving the list of hash function IDs associated with this Bloom Filter.
const std::vector<std::string> &BloomFilter::getHashFunctions()
{
    return this->hashFunctionIDs;
}
// Method to set a specific bit in the bit array to true (1), indicating the presence of an element.
void BloomFilter::setBitArray(int index)
{
    this->bitArray[index] = 1;
}
// Getter method for retrieving the size of the bit array, which corresponds to the capacity of the Bloom Filter.
int BloomFilter::getBitArraySize()
{
    return this->bitArray.size();
}
// Getter method for accessing the set of false positives recorded by the Bloom Filter.
std::unordered_set<std::string> BloomFilter::getFalsePositives()
{
    return this->falsePositive;
}
// Method to add URL's to a list to cross check false positives within the Bloom Filter.
void BloomFilter::insertFaslePositives(std::string& url){
    this->falsePositive.insert(url);
}